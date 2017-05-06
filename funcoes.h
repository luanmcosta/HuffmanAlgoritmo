#ifndef FUNCOES_H
#define FUNCOES_H

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

// Funções

// Ler arquivo e armazenar dados em string
string carregarArquivo(string arquivo);

// Salvar string em arquivo
void salvarArquivo(string nomeArquivo, string texto);

// Salvar em arquivo binário
void salvarArquivoBin(string arquivo, string texto);

// Converter String de Binário para String ASCII
string converterStringBinario(string texto);

// Ler caracteres (passar de String para um vetor de char)
vector<char> lerCaracteres(string texto);

// Contar ocorrencias de caracteres (Obter frequencia)
vector<int> contarCaracteres(vector<char> msgChar, vector<char> caracteres);

// Ordenar em ordem decrescente os vetores (Utilizando SelectionSort)
void ordenarCaracteresFreq(vector<char> & caracteres, vector<int> & frequencia);

// Ordenar vetor de nós
vector<No *> ordenarVetorNos(vector<No *> & referenciasNos);

// Verificar se há uma letra no vetor
bool verificarCaractere(vector<char> letras, char letra);

// Gerar fila de Nos das frequencias
priority_queue<No *, vector<No *>, CompararNo> montarFila(vector<char> & caracteres, vector<int> & frequencia);

// Montar arvore binária
No * montarArvore(priority_queue<No *, vector<No *>, CompararNo> & fila, vector<No *> & referenciasNos);

// Codificar caractere
string codificarCaractere(No * pai);

// Codificar nós
void codificarNos(vector<No *> nos);

// Gerar mensagem codificada
string codificarTexto(string msg, vector<No *> & dicionario);

#endif // FUNCOES_H
