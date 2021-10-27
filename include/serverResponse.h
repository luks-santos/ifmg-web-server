#ifndef SERVERRESPONSE_H
#define SERVERRESPONSE_H

#include "Socket.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "mimetype.h"

using namespace std;

class serverResponse
{
    public:
        serverResponse() {};
        virtual ~serverResponse() {};
        //Função para estabelecimento da conexão com o cliente
        void handleRequest(int thread_id, int clientSockfd, sockaddr_in clientAddr, string dir);
        //Função de fornecimento de arquivos solicitados
        int handleGet(int thread_id, int clientSockfd, sockaddr_in clientAddr, string root, string extension, string dir);
        vector<string> split(string str, char del);//Carregamento dos dados do arquivo
        bool arqStream(string root, int &len, string &n); //Abertura do arquivo solicitado
        void readFile(fstream &file, string &n, int len); //Leitura dos dados
        string getStatus(int resp, int len, string extension); //Definição do status de resposta
        int	operator()(int thread_id, int clientSockfd, sockaddr_in clientAddr, string dir) //Operador de threads
        {
            handleRequest(thread_id, clientSockfd, clientAddr, dir);
            return (0);
        }
    private:
        Socket socli;
};

#endif // SERVERRESPONSE_H
