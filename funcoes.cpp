#include "funcoes.h"

vector<char> lerCaracteres(string texto)
{
    vector<char> letras;
    letras.resize(0);
    // Percorrer vetor e armazenar letras
    for (unsigned int i = 0; i < texto.length(); ++i)
        letras.push_back(texto[i]);
    return letras;
}


bool verificarCaractere(vector<char> letras, char letra){

    for(unsigned int i = 0; i < letras.size(); i++)
        if(letras[i] == letra)
             return true;

    return false;
}

vector<int> contarCaracteres(vector<char> msgChar, vector<char> caracteres){
    // Vetor de ocorrencias
    vector<int> frequenciaChar;
    frequenciaChar.resize(caracteres.size());

    // Resetar vetor de frequencia
    for(unsigned int i = 0; i < frequenciaChar.size(); i++)
        frequenciaChar[i] = 0;

    // Percorrer vetor de caracteres
    for(unsigned int i = 0; i < caracteres.size(); i++){

        // Vefirifcar se há ocorrencia do caractere na msg
        char verificador = caracteres[i];
        for(unsigned int j = 0; j < msgChar.size(); j++)
            if(verificador == msgChar[j])
                frequenciaChar[i]++;
    }

    return frequenciaChar;
}

void ordenarCaracteresFreq(vector<char> & caracteres, vector<int> & frequencia){

    int auxFreq, menor;
    char auxChar;

    for(unsigned int i =0; i < frequencia.size(); i++){ // Ordenar com SelectionSort
        menor = i;

        for(unsigned int j = i+1; j < frequencia.size(); j++)
            if(frequencia[j] > frequencia[menor]) // Ordem inversa
                menor = j;

        auxFreq = frequencia[menor];
        frequencia[menor] = frequencia[i];
        frequencia[i] = auxFreq;

        auxChar = caracteres[menor];
        caracteres[menor] = caracteres[i];
        caracteres[i] = auxChar;

    }

}

priority_queue<No *, vector<No *>, CompararNo> montarFila(vector<char> & caracteres, vector<int> & frequencia){
    priority_queue<No *, vector<No *>, CompararNo> fila;

    // Percorrer todos os caracteres e frequencias, criar um nó com as informações e adicionar à lista
    for (unsigned int i = 0; i < frequencia.size(); ++i)
        fila.push(new No(caracteres[i], frequencia[i]));

    return fila;
}

No * montarArvore(priority_queue<No *, vector<No *>, CompararNo> & fila){

    No * no1, * no2, * pai;

    while(true){

        no1 = fila.top(); fila.pop();
        no2 = fila.top(); fila.pop();

        pai = new No(no1, no2);

        if(fila.empty())
            return pai;

        fila.push(pai);
    }
}

string carregarArquivo(string arquivo){
    // Dados
    string dados;

    // Instanciar arquivo
    ifstream arq;
    arq.open(arquivo);

    // Verifica se arquivo foi encontrado
    if(!arq.is_open())
        exit(0);

    // Ler dados da matriz
    stringstream strStream;
    strStream << arq.rdbuf();//lê o arquivo
    dados = strStream.str();//converter stringstream para string
    // Fechar arquivo
    arq.close();

    return dados;
}


/*
stringstream percorrerArvore(No * no, stringstream codigo, char caractere){

    // Caso encontre a folha e essa folha corresponda ao caractere
    if(no->isFolha() && no->getCaractere() == caractere)
        return codigo;

    // Percorrer o resto dos nós
    // Percorrer caso for à esquerda
    percorrerArvore(no->esquerda, (codigo.putback('0')), caractere);

    // Percorrer caso for à direita
    percorrerArvore(no->direita, (codigo.putback('1')), caractere);

}


string buscarLetra(No *raiz, char letra){
    stringstream cod;
    cod.flush();

    cod = percorrerArvore(raiz, cod, letra);

    string codigo = cod.str();

    return codigo;
}
*/
