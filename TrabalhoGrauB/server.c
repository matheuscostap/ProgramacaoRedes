#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


#define TAMANHO_MENSAGEM 1024
#define PORTA 2000 //Porta do servidor

void* threadLeitura(void* args);
int partida(int jogada1, int jogada2);
void escreverMensagem();
void enviarMensagem(char msg[]);
void textoJogada(int jogada);


typedef enum {PEDRA = 1, PAPEL = 2, TESOURA = 3} JOGADA;

struct sockaddr_in server; //Struct para tratar enderecos de internet
struct sockaddr cliente; //Struct para guardar infos de cliente
int socketCliente;
char mensagem[TAMANHO_MENSAGEM] = "0";
int jogadaCliente = 0;
int parar = 1;

int main(int argc, char const *argv[]) {

  pthread_t id;
  int sock;

  printf("Criando socket do servidor...\n");
  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock != -1) {
    printf("Socket criado\n");
  }else{
    printf("Erro ao criar socket\n");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(PORTA);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  //memset(server.sin_zero, 0x0, 8);

  if(bind(sock, (struct sockaddr*) &server, sizeof(server)) != -1){
    printf("Bind com sucesso\n");
  }else{
    perror("Bind com Erro: ");
    exit(1);
  }

  int ret;
  ret = listen(sock,1);
  if (ret != 1) {
    printf("Aguardando conexao\n");
  }else{
    perror("Listen erro: ");
    exit(1);
  }

  socklen_t tamanho_sock = sizeof(struct sockaddr);
  socketCliente = accept(sock, (struct sockaddr*) &cliente, &tamanho_sock);

  if (socketCliente != -1) {
    printf("Conexão recebida com sucesso\n");
    ret = pthread_create(&id,NULL,&threadLeitura,NULL);

    /*if(ret == 0){
      printf("Thread de leitura criada\n");
    }else{
      printf("Erro ao criar thread de leitura\n");
    }*/

  }else{
    perror("Erro ao receber conexão: ");
    exit(1);
  }

  sleep(1);
  enviarMensagem("Bem vindo ao servidor de JoKenPo");

  while(parar){
    int jogadaServidor;
    printf("-- JOGADA --\n");
    printf("1 - PEDRA\n");
    printf("2 - PAPEL\n");
    printf("3 - TESOURA\n");
    printf("4 - FECHAR SERVIDOR\n");
    printf("------------\n");

    scanf("%d", &jogadaServidor);

    if (jogadaServidor == 4) {
      close(socketCliente);
      close(sock);
      return 0;
    }

    while(jogadaCliente == 0){
      printf("Aguardando jogada do adversário...\n");
      sleep(1);
    }

    printf("Jogada do Cliente: ");
    textoJogada(jogadaCliente);
    printf("Jogada do Servidor: ");
    textoJogada(jogadaServidor);

    if (partida(jogadaServidor, jogadaCliente) == jogadaServidor){
      printf("Você venceu!\n");
      enviarMensagem("Você perdeu!\n");
    }else{
      printf("Você perdeu!\n");
      enviarMensagem("Você venceu!\n");
    }

    close(socketCliente);
    parar = 0;
  }

  close(sock);

  return 0;
}


void* threadLeitura(void* args){
  int bytes;
  do{
    bytes = recv(socketCliente, mensagem, TAMANHO_MENSAGEM,0);
    mensagem[bytes] = 0; //Char 0 para finalizar a string
    if(bytes > 0){
      printf("Recebido: %s \n",mensagem);
      jogadaCliente = atoi(mensagem);
    }
  }while (mensagem[0] != '.' && bytes != 0);
}

//Jogada 1 = server, Jogada 2 = cliente
int partida(int jogada1, int jogada2){
  if (jogada1 == PEDRA && jogada2 == PAPEL){
    return jogada2;
  }

  if (jogada1 == PEDRA && jogada2 == TESOURA) {
    return jogada1;
  }

  if (jogada1 == PEDRA && jogada2 == PEDRA){
    return 0;
  }

  if (jogada1 == PAPEL && jogada2 == PAPEL){
    return 0;
  }

  if (jogada1 == PAPEL && jogada2 == TESOURA){
    return jogada2;
  }

  if (jogada1 == PAPEL && jogada2 == PEDRA){
    return jogada1;
  }

  if (jogada1 == TESOURA && jogada2 == PAPEL) {
    return jogada1;
  }

  if (jogada1 == TESOURA && jogada2 == TESOURA) {
    return 0;
  }

  if (jogada1 == TESOURA && jogada2 == PEDRA){
    return jogada2;
  }
}

void escreverMensagem(){
  scanf("%80s", mensagem);
  send(socketCliente, mensagem, strlen(mensagem), 0);
}

void enviarMensagem(char msg[]){
  send(socketCliente, msg, strlen(msg), 0);
}

void textoJogada(int jogada){
  if (jogada == PEDRA) {
    printf("Pedra\n");
  }

  if (jogada == TESOURA){
    printf("Tesoura\n");
  }

  if (jogada == PAPEL){
    printf("Papel\n");
  }
}
