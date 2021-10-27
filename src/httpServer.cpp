#include "httpServer.h"

httpServer::httpServer(int port, string host, string dir)
{
    socktServer = new Socket(port, host); //Criação do novo socket
    this->dir = dir; //Atribuição do diretório do servidor
}

httpServer::~httpServer() //Destrutor
{
    delete socktServer;
    socktServer = nullptr;
}

void httpServer::startServer()//Inicialização do servidor
{
    serverResponse res;
    socktServer->listensock(5); //Estabelecimento da quantidade máxima de conexões que podem ser estabelecidas
    int i =0;
    while(true){
        int socktFd = socktServer->acceptsk(); //Aceite da conexão
        socktServer->setTimeOut(socktFd, 5); //Estabelecimento de tempo para recebimento de requisições par aquela conexão
        thread(res, i++, socktFd, socktServer->getClientAddr(), dir).detach(); //Passagem do atendimenot para uma thread
    }
}
