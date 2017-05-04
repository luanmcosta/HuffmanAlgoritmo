#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include "funcoes.h"
#include "no.h"


using namespace std;

int main()
{
    // Variaveis
    string msgCodificada = "";
    string msgString = carregarArquivo("./dados.txt");
    vector<char> msgChar;
    vector<char> caracteres;
    vector<int> frequenciaChar;
    priority_queue<No *, vector<No *>, CompararNo> filaNos;
    No * raiz;

    // Ler Caracteres da String e transformar em Char
    msgChar = lerCaracteres(msgString);

    // Obter a lista de todos os caracteres presentes na msg
    // Sem repetir caracteres
    for(unsigned int i = 0; i < msgChar.size(); i++)
        if(!verificarCaractere(caracteres, msgChar[i]))
            caracteres.push_back(msgChar[i]);

    // Realizar contagem da frequencia
    frequenciaChar = contarCaracteres(msgChar, caracteres);

    // Ordenar frequencias dos caracteres
    ordenarCaracteresFreq(caracteres, frequenciaChar);

    // Gerar fila (Nos)
    filaNos = montarFila(caracteres, frequenciaChar);

    // Montar árvore
    raiz = montarArvore(filaNos);

    cout << raiz->direita->direita->direita->getCaractere() << endl;

    return 0;
}


