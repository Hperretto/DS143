#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct arvore arvore;
struct arvore {
    int num;
    arvore *esquerda;
    arvore *direita;
};

arvore *inicializa();
arvore *cria_arvore();
arvore *insere(arvore *raiz, int num);
void imprime(arvore *raiz);
void libera_arvore(arvore *raiz);
int arv_bin_check(struct arvore *raiz);


void main() {
    arvore *raiz = inicializa();
    raiz = insere(raiz, 13);
    raiz = insere(raiz, 18);
    raiz = insere(raiz, 23);
    raiz = insere(raiz, 15);
    raiz = insere(raiz, 8);

    imprime(raiz);
    printf("\n");

    if (arv_bin_check(raiz))
        printf("e binaria de busca\n");
    else
        printf("nao e binaria de busca\n");

    free(raiz);
}


arvore *inicializa() {
    return NULL;
}

arvore *cria_arvore() {
    arvore* raiz = (arvore*) malloc(sizeof(arvore));
    raiz->num = 0;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    return raiz;
}

arvore *insere(arvore *raiz, int num) {
    if(raiz == NULL) {
        arvore* raiz = (arvore*) malloc(sizeof(arvore));
        raiz->num = num;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        return raiz;
    }
    else {
        if(num > raiz->num)
            raiz->direita = insere(raiz->direita, num);
        if(num < raiz->num)
            raiz->esquerda = insere(raiz->esquerda, num);
    }
    return raiz;
}

void imprime(arvore *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz->num);
        imprime(raiz->esquerda);
        imprime(raiz->direita);
    }
}

void libera_arvore(arvore *raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esquerda);
        libera_arvore(raiz->direita);
        libera_arvore(raiz);
    }
}

int arv_bin_check(struct arvore *raiz) {
    arvore *anterior = NULL;
    if (raiz) {
        if (!arv_bin_check(raiz->esquerda))
            return false;
        if (anterior != NULL && raiz->num <= anterior->num)
            return false;
        anterior = raiz;
        return arv_bin_check(raiz->direita);
    }
    return true;
}
