#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define PORTA 2000 //porta do servidor
#define TAMANHO_MENSAGEM 4096 //tamanho da mensagem a ser recebida...

struct sockaddr_in server; //Struct para tratar enderecos de internet
struct sockaddr_in cliente; //Struct para guardar infos do cliente
char mensagem[TAMANHO_MENSAGEM]; //Char array como buffer para enviar mensagem

int main(void){

  //1° - Abertura do socket do servidor
  int sock;
  printf("Criando socket do servidor...\n");
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

  //2° - Associar porta e endereço ip para o socket com a função bind
  //Configura a struct com as informações de rede
  server.sin_family = AF_INET; //Família do endereço
  server.sin_port = htons(PORTA); //Número da porta, htons() converte para o formate de rede
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); //Endereço ip, inet_addr() converte o ip para o formato binario de rede
  memset(server.sin_zero, 0x0, 8);

  //Verifica se o bind teve sucesso
  if(bind(sock, (struct sockaddr*) &server, sizeof(server)) != -1){
    printf("Bind com sucesso\n");
  }else{
    perror("Bind com Erro: ");
    exit(1);
  }

  //3° - Aguardar conexão de um cliente com a função listen
  //listen() define o socket como passivo para aguardar conexões
  //parâmetros: 1 - socket: o socket criado anteriormente
  //            2 - quantidade de conexões que podem ficar pendentes
  int ret;
  ret = listen(sock,1);
  if (ret != 1) {
    printf("Listen com sucesso\n");
  }else{
    perror("Listen erro: ");
    exit(1);
  }

  //4° - Aceitar a requisição do cliente
  //accept() cria um novo socket para a primeira conexão pendente e retorna o descritor dele
  //parâmetros: 1 - socket: o socket criado para o servidors
  //            2 - um ponteiro para uma struct do tipo sockaddr que irá receber as infos do cliente
  //            3 - o tamanho da struct para inicalizar corretamente
  int tamanho_sock = sizeof(cliente);
  int socketCliente;
  socketCliente = accept(sock, (struct sockaddr*) &cliente, &tamanho_sock);

  //Verfica se o accept teve sucesso
  if (socketCliente != -1) {
    printf("Conexão recebida com sucesso\n");
  }else{
    perror("Erro ao receber conexão: ");
    exit(1);
  }

  strcpy(mensagem,"Bem vindo ao servidor\n");
  write(socketCliente, mensagem, strlen(mensagem));

  while(1){
    int bytes;
    bytes = recv(sock, mensagem, TAMANHO_MENSAGEM,0);
    mensagem[bytes] = '\0'; //Char 0 para finalizar a string
    printf("Recebido: %s\n", mensagem);
    printf("Enviar mensagem: ");
    //Limpa o buffer
    bzero(mensagem, TAMANHO_MENSAGEM);
    //Leitura do teclado
    fgets(mensagem,TAMANHO_MENSAGEM,stdin);
    //Envia a mensagem
    write(sock, mensagem, strlen(mensagem));
    bzero(mensagem, TAMANHO_MENSAGEM);
    /*int s = send(sock,mensagem,strlen(mensagem),0);
    if (s < 0) {
      printf("Erro ao enviar mensagem\n");
    }*/

  }
}
