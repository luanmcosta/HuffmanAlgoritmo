#include "no.h"

No::No()
{

}

No::No(No * esquerda, No * direita){
    this->esquerda = esquerda;
    this->direita = direita;
    this->frequencia = esquerda->getFrequencia() + direita->getFrequencia();
    this->caractere = '+';
}

No::No(char caractere, int frequencia){
    this->caractere = caractere;
    this->frequencia = frequencia;
    this->direita = NULL;
    this->esquerda = NULL;
}


bool No::isFolha(){
    if(direita == NULL && esquerda == NULL)
        return true;
    return false;
}

int No::getFrequencia(){
    if(isFolha())
        return this->frequencia;
    return esquerda->getFrequencia() + direita->getFrequencia();
}

char No::getCaractere(){
    return this->caractere;
}
