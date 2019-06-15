#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define TAMANHO_MENSAGEM 1024
#define PORTA 2000 //Porta do servidor

void* threadLeitura(void* args);
void escreverMensagem();

struct sockaddr_in server; //Struct para tratar enderecos de internet
char mensagem[TAMANHO_MENSAGEM]; //buffer para as mensagens
int sock; //variável para armazenar o descritor do socket do servidor
int jogou = 0; //flag para saber se o cliente ja jogou

int main(int argc, char const *argv[]) {


  //Abertura do socket do servidor
  //Função socket
  //parâmetros: 1 - domínio: AF_INET para processos de sistemas diferentes
  //            2 - tipo de socket: SOCK_STREAM conexão bidirecional de um fluxo de bytes
  //            3 - protocolo: 0 para um protocolo padrão
  printf("Criando socket do servidor...\n");
  pthread_t id; //variável para guardar o identificador da thread
  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock != -1) {
    printf("Socket criado\n");
  }else{
    printf("Erro ao criar socket\n");
    exit(1);
  }

  //Configura a struct com as informações de rede do servidor
  server.sin_family = AF_INET; //Família do endereço
  server.sin_port = htons(PORTA); //Número da porta, htons() converte para o formate de rede
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); //Endereço ip, inet_addr() converte o ip para o formato binario de rede

  //Tenta conectar o servidor com a função connect()
  if(connect(sock, (struct sockaddr*) &server, sizeof(server)) != -1){
    printf("Conectado no servidor!\n");

    //Cria uma nova thread para leitura de dados
    int ret = pthread_create(&id,NULL,&threadLeitura,NULL);
  }else{
    printf("Erro ao conectar.\n");
    exit(1);
  }

  while(1){
    //Menu com as jogadas
    if(!jogou){
      printf("-- JOGADA --\n");
      printf("1 - PEDRA\n");
      printf("2 - PAPEL\n");
      printf("3 - TESOURA\n");
      printf("------------\n");

      escreverMensagem();
    }
  }

  return 0;
}

//Função que a thread utilza par ler os dados
void* threadLeitura(void* args){
  int bytes;
  do{
    bytes = recv(sock, mensagem, TAMANHO_MENSAGEM,0);
    mensagem[bytes] = 0; //Char 0 para finalizar a string
    if(bytes > 0){
      printf("Recebido: %s \n",mensagem);
    }
  }while (mensagem[0] != '.' && bytes != 0);

  printf("Close socket.\n");
  close(sock);
}

void escreverMensagem(){
  scanf("%80s", mensagem);
  printf("Enviei: %s \n",mensagem);
  send(sock, mensagem, strlen(mensagem), 0);
  jogou = 1;
}
