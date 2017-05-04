#ifndef FUNCOES_H
#define FUNCOES_H

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<array>
#include<queue>
#include"no.h"

using namespace std;

// Funções

// Ler arquivo e armazenar dados em string
string carregarArquivo(string arquivo);

// Ler caracteres (passar de String para um vetor de char)
vector<char> lerCaracteres(string texto);

// Contar ocorrencias de caracteres (Obter frequencia)
vector<int> contarCaracteres(vector<char> msgChar, vector<char> caracteres);

// Ordenar em ordem decrescente os vetores (Utilizando SelectionSort)
void ordenarCaracteresFreq(vector<char> & caracteres, vector<int> & frequencia);

// Verificar se há uma letra no vetor
bool verificarCaractere(vector<char> letras, char letra);

// Gerar fila de Nos das frequencias
priority_queue<No *, vector<No *>, CompararNo> montarFila(vector<char> & caracteres, vector<int> & frequencia);

// Montar arvore binária
No * montarArvore(priority_queue<No *, vector<No *>, CompararNo> & fila);

// Buscar código da letra
string buscarLetra(No * raiz, char letra);

#endif // FUNCOES_H
