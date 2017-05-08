#include <iostream>
#include "huffman.h"
#include "funcoes.h"
#include "decodificar.h"

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
    sort(referenciasNos.begin(), referenciasNos.end(), CompararNo());

    // Codificar mensagem
    msgCodificada = codificarTexto(msgString, referenciasNos);

    // Gerar dicionario em texto
    stringstream dicionario;
    for(unsigned int i = 0; i < caracteres.size(); i++)
        dicionario << referenciasNos.at(i)->getCaractere() << "=" << referenciasNos.at(i)->codigo << ";";

    // Concatenar dados adicionaris, dicionário e mensagem codificada
    string textoArquivoBin = "";
    int padding = (8 - (msgCodificada.size() % 8));
    textoArquivoBin += to_string(caracteres.size()); // informar qtd de caracteres
    textoArquivoBin += ";";
    textoArquivoBin += dicionario.str(); // imprimir dicionario
    textoArquivoBin += to_string(padding); // informar o padding (bits restantes para formar o ultimo byte)
    textoArquivoBin += ";";
    // Completar padding
    for(int i = 0; i < padding; i++)
        msgCodificada.push_back('0');
    textoArquivoBin += converterStringBinario(msgCodificada);

    // Salvar arquivo com dicionário e mensagem
    salvarArquivoBin("./saida.bin", textoArquivoBin);

    // Decodificar arquivo
    string textoDecodificado = decodificarTexto("./saida.bin");

    cout << textoDecodificado << endl;

    // Salvar binario original para comparação posterior
    salvarArquivo("./binariocodificacao.txt", msgCodificada);

    return 0;
}


