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


//Enum para representar as jogadas
typedef enum {PEDRA = 1, PAPEL = 2, TESOURA = 3} JOGADA;

struct sockaddr_in server; //Struct para tratar enderecos de internet
struct sockaddr cliente; //Struct para guardar infos de cliente
int socketCliente; //Variável para armazenar o descritor do socket do cliente
char mensagem[TAMANHO_MENSAGEM] = "0"; //buffer para as mensagens
int jogadaCliente = 0; //Variável para armazenar a jogada do cliente
int parar = 1;

int main(int argc, char const *argv[]) {

  pthread_t id; //variável para guardar o identificador da thread
  int sock;

  //Abertura do socket do servidor
  //Função socket
  //parâmetros: 1 - domínio: AF_INET para processos de sistemas diferentes
  //            2 - tipo de socket: SOCK_STREAM conexão bidirecional de um fluxo de bytes
  //            3 - protocolo: 0 para um protocolo padrão
  printf("Criando socket do servidor...\n");
  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock != -1) {
    printf("Socket criado\n");
  }else{
    printf("Erro ao criar socket\n");
    exit(1);
  }

  //Associar porta e endereço ip para o socket com a função bind
  //Configura a struct com as informações de rede
  server.sin_family = AF_INET; //Família do endereço
  server.sin_port = htons(PORTA); //Número da porta, htons() converte para o formate de rede
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); //Endereço ip, inet_addr() converte o ip para o formato binario de rede

  //Configura o socket
  if(bind(sock, (struct sockaddr*) &server, sizeof(server)) != -1){
    printf("Bind com sucesso\n");
  }else{
    perror("Bind com Erro: ");
    exit(1);
  }

  //Aguardar conexão de um cliente com a função listen
  //listen() define o socket como passivo para aguardar conexões
  //parâmetros: 1 - socket: o socket criado anteriormente
  //            2 - quantidade de conexões que podem ficar pendentes
  int ret;
  ret = listen(sock,1);
  if (ret != 1) {
    printf("Aguardando conexao\n");
  }else{
    perror("Listen erro: ");
    exit(1);
  }

  //Aceitar a requisição do cliente
  //accept() cria um novo socket para a primeira conexão pendente e retorna o descritor dele
  //parâmetros: 1 - socket: o socket criado para o servidors
  //            2 - um ponteiro para uma struct do tipo sockaddr que irá receber as infos do cliente
  //            3 - o tamanho da struct para inicalizar corretamente
  socklen_t tamanho_sock = sizeof(struct sockaddr);
  socketCliente = accept(sock, (struct sockaddr*) &cliente, &tamanho_sock);

  if (socketCliente != -1) {
    printf("Conexão recebida com sucesso\n");

    //Cria uma nova thread para leitura de dados
    ret = pthread_create(&id,NULL,&threadLeitura,NULL);
  }else{
    perror("Erro ao receber conexão: ");
    exit(1);
  }

  //Pausa a execução por 1 segundo para sincronizar as saidas nos dois lados
  sleep(1);
  enviarMensagem("Bem vindo ao servidor de JoKenPo");

  while(parar){
    //Menu com as as jogadas
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

    //Aguarda a jogada do clinte
    while(jogadaCliente == 0){
      printf("Aguardando jogada do adversário...\n");
      sleep(1);
    }

    printf("Jogada do Cliente: ");
    textoJogada(jogadaCliente);
    printf("Jogada do Servidor: ");
    textoJogada(jogadaServidor);

    //Verifica o vencedor da partida e envia o resultado para os dois lados
    if (partida(jogadaServidor, jogadaCliente) == jogadaServidor){
      printf("Você venceu!\n");
      enviarMensagem("Você perdeu!\n");
    }else{
      printf("Você perdeu!\n");
      enviarMensagem("Você venceu!\n");
    }

    //Fecha o socket do cliente
    close(socketCliente);
    parar = 0;
  }

  //Fecha o socket do servidor
  close(sock);
  return 0;
}

//Função que a thread utilza par ler os dados
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
