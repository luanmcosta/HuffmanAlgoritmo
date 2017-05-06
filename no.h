#ifndef NO_H
#define NO_H

#include<iostream>

using namespace std;

class No
{
public:
    No();
    No(No * esquerda, No * direita);
    No(char caractere, int frequencia);
    bool isFolha();
    int getFrequencia();
    char getCaractere();

    bool operator < (No& no)
    {
        return (this->getFrequencia() < no.getFrequencia());
    }

    char caractere;
    int frequencia;
    string codigo = "";
    No * esquerda;
    No * direita;
    No * pai;
};

class CompararNo{
public:
    bool operator() (No * esquerda, No * direita){
        return esquerda->getFrequencia() > direita->getFrequencia();
    }
};

#endif // NO_H
