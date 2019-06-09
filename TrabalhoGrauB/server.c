#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>


#define TAMANHO_MENSAGEM 1024
#define PORTA 2000 //Porta do servidor

struct sockaddr_in server; //Struct para tratar enderecos de internet
struct sockaddr cliente; //Struct para guardar infos de cliente
int socketCliente;
char mensagem[TAMANHO_MENSAGEM];

void* threadLeitura(void* args);

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
    printf("Listen com sucesso\n");
  }else{
    perror("Listen erro: ");
    exit(1);
  }

  socklen_t tamanho_sock = sizeof(struct sockaddr);
  socketCliente = accept(sock, (struct sockaddr*) &cliente, &tamanho_sock);

  if (socketCliente != -1) {
    printf("Conexão recebida com sucesso\n");
    ret = pthread_create(&id,NULL,&threadLeitura,NULL);

    if(ret == 0){
      printf("Thread de leitura criada\n");
    }else{
      printf("Erro ao criar thread de leitura\n");
    }

  }else{
    perror("Erro ao receber conexão: ");
    exit(1);
  }

  while(1){
    do{
      scanf("%80s", mensagem);
      printf("Enviei: %s \n",mensagem);
      send(socketCliente, mensagem, strlen(mensagem), 0);
    }while(mensagem[0] != '.');

    close(socketCliente);
    return 0;
  }

  close(sock);

  return 0;
}


void* threadLeitura(void* args){
  printf("Thread inicio\n");

  int bytes;
  do{
    bytes = recv(socketCliente, mensagem, TAMANHO_MENSAGEM,0);
    mensagem[bytes] = 0; //Char 0 para finalizar a string
    if(bytes > 0){
      printf("Recebido: %s \n",mensagem);
    }
  }while (mensagem[0] != '.' && bytes != 0);

  printf("Thread fim\n");

}
