#ifndef FUNCOES_H
#define FUNCOES_H

#include"huffman.h"

using namespace std;

/*
 *  Ler arquivo e armazenar dados em string
 *
*/
string carregarArquivo(string arquivo);

/*
 *  Converter String de Binário para String ASCII
 *
*/
string converterStringBinario(string texto);

/*
 *  Verificar se há uma letra no vetor
 *
*/
bool verificarCaractere(vector<char> letras, char letra);

/*
 *  Salvar string em arquivo
 *
*/
void salvarArquivo(string nomeArquivo, string texto);

/*
 * Salvar em arquivo binário
 *
*/
void salvarArquivoBin(string arquivo, string texto);

/*
 *  Ordenar em ordem decrescente os vetores (Utilizando SelectionSort)
 *
*/
void ordenarCaracteresFreq(vector<char> & caracteres, vector<int> & frequencia);


/*
 *  Ler caracteres (passar de String para um vetor de char)
 *
*/
vector<char> lerCaracteres(string texto);

/*
 *  Contar ocorrencias de caracteres (Obter frequencia)
 *
*/
vector<int> contarCaracteres(vector<char> msgChar, vector<char> caracteres);





#endif // FUNCOES_H
