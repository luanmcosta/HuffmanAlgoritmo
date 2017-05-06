#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<fstream>
#include<bitset>
#include<array>
#include<queue>
#include"no.h"

using namespace std;

/*
 *  Codificar caractere
 *
*/
string codificarCaractere(No * no);

/*
 * Percorre o dicionário em busca do código referente ao caractere repassado
 *
*/
string buscarCodigo(vector<No *> & dicionario, char caractere);


/*
 *  Gerar mensagem codificada
 *
*/
string codificarTexto(string msg, vector<No *> & dicionario);

/*
 *  Codificar nós
 *
*/
void codificarNos(vector<No *> nos);

/*
 * Ordenar vetor de nós
 *
*/
vector<No *> ordenarVetorNos(vector<No *> & referenciasNos);

/*
 *  Gerar fila de Nos das frequencias
 *
*/
priority_queue<No *, vector<No *>, CompararNo> montarFila(vector<char> & caracteres, vector<int> & frequencia);

/*
 *  Montar arvore binária
 *
*/
No * montarArvore(priority_queue<No *, vector<No *>, CompararNo> & fila, vector<No *> & referenciasNos);


#endif // HUFFMAN_H
