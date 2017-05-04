#ifndef NO_H
#define NO_H

#include<iostream>
#include<vector>
#include<string>
#include<array>

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

    char caractere;
    int frequencia;
    No * esquerda;
    No * direita;
};

class CompararNo{
public:
    bool operator() (No * esquerda, No * direita){
        return esquerda->getFrequencia() > direita->getFrequencia();
    }
};

#endif // NO_H
