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

vector<No *> ordenarVetorNos(vector<No *> & referenciasNos){
    vector<No *> nos;

    int menor;
    No * auxJ, * auxMenor;

    for(unsigned int i =0; i < referenciasNos.size(); i++){ // Ordenar com SelectionSort
        menor = i;

        for(unsigned int j = i+1; j < referenciasNos.size(); j++){
            auxJ = referenciasNos[i];
            auxMenor = referenciasNos[menor];
            if(auxJ->getFrequencia() < auxMenor->getFrequencia())
                menor = j;
        }

        nos.push_back(referenciasNos[menor]);
    }

    return nos;
}

priority_queue<No *, vector<No *>, CompararNo> montarFila(vector<char> & caracteres, vector<int> & frequencia){
    priority_queue<No *, vector<No *>, CompararNo> fila;

    // Percorrer todos os caracteres e frequencias, criar um nó com as informações e adicionar à lista
    for (unsigned int i = 0; i < frequencia.size(); ++i)
        fila.push(new No(caracteres[i], frequencia[i]));

    return fila;
}

No * montarArvore(priority_queue<No *, vector<No *>, CompararNo> & fila, vector<No *> & referenciasNos){

    No * no1, * no2, * pai;

    while(true){

        no1 = fila.top(); fila.pop();
        no2 = fila.top(); fila.pop();

        if(no1->isFolha())
            referenciasNos.push_back(no1);
        if(no2->isFolha())
            referenciasNos.push_back(no2);


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

void salvarArquivo(string nomeArquivo, string texto){
    // Instanciar arquivo
    ofstream arq(nomeArquivo);

    // Atribuir dados ao arquivo
    arq << texto;

    // fechar arquivo
    arq.close();

}

string codificarCaractere(No * pai){

    No * atual;
    string codigo = "";

    // Percorrer arvore de cima para baixo, a partir do filho até o pai
    while(pai->pai != NULL){
        atual = pai;
        pai = pai->pai;

        // Verificar se sou o filho da direita ou da esquerda
        if(pai->esquerda == atual)
            codigo += "0";
        else
            codigo += "1";
    }

    // Inverter código (Já que estou gerando de baixo pra cima)
    reverse(codigo.begin(), codigo.end());

    return codigo;
}

void codificarNos(vector<No *> nos){
    No * auxNo, * refNo;

    // Ler todos os filhos(caracteres) e gerar o código
    for(unsigned int i = 0; i < nos.size(); i++){
        auxNo = nos[i];
        refNo = nos[i];
        refNo->codigo = codificarCaractere(auxNo);
    }
}

string buscarCodigo(vector<No *> & dicionario, char caractere){
    No * auxNo;

    // Percorrer dicionário
    for(unsigned int i = 0; i < dicionario.size(); i++){
        // Verificar se há o caractere no dicionario e retornar o código
        auxNo = dicionario[i];
        if(auxNo->getCaractere() == caractere)
            return auxNo->codigo;
    }

    return "";
}

string codificarTexto(string msg, vector<No *> & dicionario){
    string msgCodificada = "";
    char caractereAtual;

    // Percorrer mensagem completa
    for(unsigned int i = 0; i < msg.size(); i++){
        caractereAtual = msg.at(i);

        // Buscar código do caractere atual
        msgCodificada += buscarCodigo(dicionario, caractereAtual);
    }

    return msgCodificada;
}

