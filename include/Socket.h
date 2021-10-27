#ifndef SOCKET_H
#define SOCKET_H
//Bibliotecas para utilização e modularização do socket
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Bibliotecas para declaração/input/output de strings e/ou variáveis
#include <string.h>
#include <iostream>

using namespace std;

#define maxSizeRecv 4090

struct databuff {  //Criação de um buffer de char responsável por receber a requisição
    char dataChar[maxSizeRecv];
    int bufflen;
};

class Socket //Classe de manipulação de sockets de conexão
{
    public:
        Socket() {};
        Socket(int port, string host);
        virtual ~Socket();
        void createcfg(struct sockaddr_in &server,int port, string host); //Função para configurar o socket
        int bindsock(int &sockfd,struct sockaddr_in &clientAddr); //Função para estabelecimento de conexão
        int listensock(int maxconn); //Ouve as requisições enviadas ao socket
        int acceptsk(); //Aceita as requisições
        databuff sockrecv(int &sockfd);
        int socksendk(int &sockfd, string str); //Envia o resultado das requisições
        void setTimeOut(int &sockfd, int time); //Timer para estabelecer o tempo em que a conexão ficará aberta
        sockaddr_in getClientAddr(); //Captura o endereço do cliente
        void closesock(int &sockfd); //Encerra o socket
        void closesock(); //Encerra o socket embutido
    private:
        int sockfd;
        struct sockaddr_in serverAddr; //Variável para estabelecimento do endereço do servidor
        struct sockaddr_in clientAddr; //Variável para recebimento do endereço do cliente
        socklen_t clientAddrSize;  //Receberá o tamanho do endereço do cliente
};

#endif // SOCKET_H
