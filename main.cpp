/*********************************************************
 * Trabalho Final da disciplina de Redes de Computadores *
 *           Servidor web multithreaded                  *
 *                                                       *
 * Curso: Bacharelado em Engenharia da Computação        *
 * Professor: Samuel Dias                                *
 *                                                       *
 * Autores:                                              *
 * Jorge Luís Vieira Murilo - 0027752                    *
 * Lucas Batista dos Santos - 0048505                    *
 * Marco Antônio da Silva   - 0040396                    *
 ********************************************************/

#include <iostream>
#include "Socket.h"
#include "httpServer.h"

using namespace std;

int main()
{
    string dir;
    cout<<"Digite o caminho (./pasta): ";

    //exemplos de entrada:
    //1 - pasta dentro do servidor: ./pasta ou pasta
    //2 - pasta na máquina: /home/marco/Documentos/JorgeMurilo-LucasBatista-MarcoAntonio

    cin >> dir; //recebimento da raiz do servidor, informada pelo usuário.
    httpServer* http = new httpServer(5005, "0.0.0.0", dir); //instanciação do servidor na porta 5000, com endereço 0.0.0.0 e raiz dir
    http->startServer(); //inicialização do servidor
    delete http;
    http = nullptr;
    return 0;
}
