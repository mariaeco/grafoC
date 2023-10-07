//mainpilha
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "pilha.h"

int main(){
     

    Pilha* minhaPilha = criaPilha();
    empilhar(minhaPilha, "PB");
    empilhar(minhaPilha, "CG");
    empilhar(minhaPilha, "POMBAL");

    mostraPilha(minhaPilha);
    desempilhar(minhaPilha);
    mostraPilha(minhaPilha);
    limparPilha(minhaPilha);
    mostraPilha(minhaPilha);
    
    system("pause");


    return 0;
}

