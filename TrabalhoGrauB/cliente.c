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
char mensagem[TAMANHO_MENSAGEM];
int sock;
int jogou = 0;

int main(int argc, char const *argv[]) {

  printf("Criando socket do servidor...\n");
  pthread_t id;
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

  if(connect(sock, (struct sockaddr*) &server, sizeof(server)) != -1){
    printf("Conectado no servidor!\n");

    int ret = pthread_create(&id,NULL,&threadLeitura,NULL);

    /*if(ret == 0){
      printf("Thread de leitura criada\n");
    }else{
      printf("Erro ao criar thread de leitura\n");
    }*/
  }else{
    printf("Erro ao conectar.\n");
    exit(1);
  }

  while(1){
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
