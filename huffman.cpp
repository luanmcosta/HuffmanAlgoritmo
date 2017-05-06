#include "huffman.h"

string codificarCaractere(No * no){

    No * atual;
    string codigo = "";

    // Percorrer arvore de cima para baixo, a partir do filho até o pai
    while(no->pai != NULL){
        atual = no;
        no = no->pai;

        // Verificar se sou o filho da direita ou da esquerda
        if(no->esquerda == atual)
            codigo += "0";
        else
            codigo += "1";
    }

    // Inverter código (Já que estou gerando de baixo pra cima)
    reverse(codigo.begin(), codigo.end());

    return codigo;
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

void codificarNos(vector<No *> nos){
    No * auxNo, * refNo;

    // Ler todos os filhos(caracteres) e gerar o código
    for(unsigned int i = 0; i < nos.size(); i++){
        auxNo = nos[i];
        refNo = nos[i];
        refNo->codigo = codificarCaractere(auxNo);
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
