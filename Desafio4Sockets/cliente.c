#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define PORTA 2000 //porta do servidor
#define TAMANHO_MENSAGEM 4096 //tamanho da mensagem a ser recebida...

struct sockaddr_in server; //Struct para guardar infos do servidor
char mensagem[TAMANHO_MENSAGEM]; //Char array como buffer para enviar mensagem

int main(void){

  //1° - Abertura do socket do servidor
  int sock;
  printf("Criando socket do Cliente...\n");
  //Função socket
  //parâmetros: 1 - domínio: AF_INET para processos de sistemas diferentes
  //            2 - tipo de socket: SOCK_STREAM conexão bidirecional de um fluxo de bytes
  //            3 - protocolo: 0 para um protocolo padrão
  sock = socket(AF_INET, SOCK_STREAM, 0);

  //Verifica se o socket foi criado corretamente
  if (sock != -1) {
    printf("Socket criado\n");
  }else{
    printf("Erro ao criar socket\n");
    exit(1);
  }

  //2° - Conecta-se a um socket server usando a função connect()
  //Configura a struct com as informações do servidor
  server.sin_family = AF_INET; //Família do endereço
  server.sin_port = htons(PORTA); //Número da porta, htons() converte para o formate de rede
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); //Endereço ip, inet_addr() converte o ip para o formato binario de rede
  memset(server.sin_zero, 0x0, 8);

  //Verifica se o connect teve sucesso
  if(connect(sock, (struct sockaddr*) &server, sizeof(server)) != -1){
    printf("Conectado no servidor!\n");
  }else{
    printf("Erro ao conectar.\n");
    exit(1);
  }

  //3° - Fica constantemente recebendo infos do servidor utilizando a funcao recv() ou read()
  while (1) {
      int bytes;
      bytes = recv(sock, mensagem, TAMANHO_MENSAGEM,0);
      mensagem[bytes] = '\0'; //Char 0 para finalizar a string
      printf("Recebido: %s\n", mensagem);
      printf("Enviar mensagem: ");
      //Limpa o buffer
      bzero(mensagem, TAMANHO_MENSAGEM);
      //Leitura do teclado
      //fgets(mensagem,TAMANHO_MENSAGEM,stdin);
      strcpy(mensagem,"Oi do cliente\n");

      //Envia a mensagem
      write(sock, mensagem, strlen(mensagem));
      bzero(mensagem, TAMANHO_MENSAGEM);
      /*int s = send(sock,mensagem,strlen(mensagem),0);
      if (s < 0) {
        printf("Erro ao enviar mensagem\n");
      }*/
  }

}
