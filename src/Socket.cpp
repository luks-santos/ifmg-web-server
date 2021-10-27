#include "Socket.h"

Socket::Socket(int port, string host) { //Construtor do socket de conexão

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Criação do socket

    int yes = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) { //Caso o socket não seja criado de forma adequada é retornada uma mensagem para o usuário
        cout << "erro setsockopt" << endl;
    }

    createcfg(serverAddr, port, host); //Criação da configuração do socket

    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) { //Caso o estebelecimento da conexão não tenha sucesso é enviada uma mensagem ao usuário
        cout << "erro bind, verifique se a porta está ocupada." << endl;
        close(sockfd);
    }
    cout << "ouvindo na porta: " << port << endl;
}

void Socket::createcfg(struct sockaddr_in& server,int port, string host) { //Criação da configuração do socket

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_aton(host.c_str(), &server.sin_addr);
    memset(server.sin_zero, '\0', sizeof(server.sin_zero));
}

int Socket::bindsock(int& sockfd, struct sockaddr_in& server) { //Estabelecimento da conexão

    return bind(sockfd, (struct sockaddr*)&server, sizeof(server));
}

int Socket::listensock(int maxconn) { //Ouve uma quantidade maxconn de requisição do socket

    return listen(sockfd, maxconn);
}

int Socket::acceptsk() { //Aceite de conexão

    return accept(sockfd, (struct sockaddr*)&clientAddr, &clientAddrSize);
}

databuff Socket::sockrecv(int &sockfd){ //Obtém a requisição solicitada

    databuff datarec;
    datarec.bufflen = recv(sockfd, datarec.dataChar, maxSizeRecv, 0); //adiciona ao buffer a requisição realizada
    return datarec;
}

int Socket::socksendk(int &sockfd, string str) { //Envio de resposta `a solicitação do cliente

    return send(sockfd, str.c_str(), str.size(), 0);
}

void Socket::setTimeOut(int &sockfd, int time) { //Determinação do timer de conexão

    timeval tv;
    tv.tv_sec = time;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,(char *)&tv,sizeof(struct timeval));
}

sockaddr_in Socket::getClientAddr() {

    return clientAddr; //Retorna o endereço do cliente
}

void Socket::closesock(int &sockfd) {

    close(sockfd); //Fecha a conexão
}

Socket::~Socket(){
    closesock();
}

void Socket::closesock() {

    close(this->sockfd); //Fecha a conexão do socket embutido
}
