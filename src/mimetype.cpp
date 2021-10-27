#include "mimetype.h"

mimetype::mimetype() //Construtor padrão
{

}

string mimetype::getType(string tipo){

    for (int i=0; i<13;i++) { //Laço utilizado para retornar o tipo de arquivo
        if(tipo == types[i][0]){
            return types[i][1]; //Retorno a tipo correspondente à solicitação
                                // viabilizando o corregamento pelo servidor
        }
    }
    return "aplication/"+tipo; //Caso o tipo de arquivo não esteja presente esse return permite baixar
                            //o arquivo solictado
}
