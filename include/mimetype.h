#ifndef MIMETYPE_H
#define MIMETYPE_H


using namespace std;
#include<string>

class mimetype //Classe criada para auxiliar no fornecimento de arquivos de determinados tipos a partir da requisição
{
 public:
    mimetype();
    string getType(string tipo); //Método para retorno do tipo de arquivo da requisição
    // Matriz de tipos de arquivos
    string types[14][2]={{"jpeg","image/jpeg"},{"png","image/png"},{"html","text/html"},{"jpg","image/jpg"},
    {"gif","image/gif"}, {"css","text/css"}, {"au","audio/basic"}, {"wav","audio/wav"}, {"avi","video/x-msvideo"},
    {"mp3","audio/mpeg"}, {"txt","text/txt"}, {"js","text/js"}, {".ico", "image/x-icon"}, {"pdf", "application/pdf"}};
};

#endif // MIMETYPE_H
