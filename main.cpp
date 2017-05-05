#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>
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
    vector<No *> referenciasNos;
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
    raiz = montarArvore(filaNos, referenciasNos);

    // Gerar codificação dos nós
    codificarNos(referenciasNos);

    // Ordenar referencias por frequencia
    sort(referenciasNos.begin(), referenciasNos.end());

    // Codificar mensagem
    msgCodificada = codificarTexto(msgString, referenciasNos);

    // Gerar dicionario em texto
    stringstream dicionario;
    for(unsigned int i = 0; i < caracteres.size(); i++)
        dicionario << referenciasNos.at(i)->getCaractere() << " = " << referenciasNos.at(i)->codigo << "\n";

    // Concatenar dicionário e mensagem codificada
    string textoArquivo = "";
    textoArquivo += dicionario.str();
    textoArquivo += msgCodificada;

    // Salvar arquivo com dicionário e mensagem
    salvarArquivo("./saida.txt", textoArquivo);

    // Exibir caracteres, frequencias e códigos
    cout << textoArquivo << endl;

    return 0;
}


