#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include<thread>
#include "Socket.h"
#include "serverResponse.h"

    class httpServer
{
    public:
        httpServer(int port, string host, string dir); //Criação do socket de conexão do servidor
        virtual ~httpServer(); //Destrutor do socket de conexão
        void startServer(); //Inicialização do servidor
    private:
        Socket *socktServer; //Ponteiro para o socket do servidor
        string dir; //Diretório do servidor
};

#endif // HTTPSERVER_H
