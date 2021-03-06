/* Nilton Miguel Guimarães de Souza - UTFPR - 2022

implementação de uma fila de elementos encadeados.

*/

# include <stdio.h>
# include <stdlib.h>

typedef struct elemento_fila{

    int valor;
    struct elemento_fila * calouro;
}Elemento_fila;

typedef struct fila{

    Elemento_fila * entrada;
    Elemento_fila * saida;
}Fila;

Fila * inicia_fila(){

    Fila * nova_fila = (Fila*)malloc(sizeof(Fila));
    nova_fila -> entrada = nova_fila -> saida = NULL;
    return nova_fila;
}

void insere_fila(Fila * fila, int valor){

    Elemento_fila * novo = (Elemento_fila*)malloc(sizeof(Elemento_fila));
    novo -> valor = valor;
    novo -> calouro = NULL;

    if (fila -> entrada == NULL){
        fila -> entrada = fila -> saida = novo;
    }
    else{
        fila -> entrada -> calouro = novo;
        fila -> entrada = novo;
    }
}

// retorna 0 se eu tento esvaziar uma fila já vazia
int retira_fila(Fila * fila){

    int valor = 0;

    if (fila -> entrada != NULL){

        valor = fila -> saida -> valor;
        Elemento_fila * antiga_saida = fila -> saida;

        if (fila -> saida -> calouro == NULL){
            fila -> saida = fila -> entrada = NULL;
        }
        else{
            fila -> saida = fila -> saida -> calouro;
        }
        free(antiga_saida);
    }

    return valor;
}

int main(void){

    Fila * fila1 = inicia_fila();
    insere_fila(fila1, 5);
    insere_fila(fila1, 6);
    insere_fila(fila1, 7);
    retira_fila(fila1);
    retira_fila(fila1);
    retira_fila(fila1);
    retira_fila(fila1);

    return 0;
}
