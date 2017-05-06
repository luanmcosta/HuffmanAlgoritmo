#include "funcoes.h"

string carregarArquivo(string arquivo){
    // Dados
    string dados;

    // Instanciar arquivo
    ifstream arq;
    arq.open(arquivo);

    // Verifica se arquivo foi encontrado
    if(!arq.is_open()){
        cout << "Arquivo não encontrado! Verifique o caminho." << endl;
        exit(0);
    }

    // Ler dados da matriz
    stringstream strStream;
    strStream << arq.rdbuf();//lê o arquivo
    dados = strStream.str();//converter stringstream para string
    // Fechar arquivo
    arq.close();

    return dados;
}


string converterStringBinario(string texto){
    stringstream sstream(texto);
    string saida;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        saida += c;
    }

    return saida;
}


bool verificarCaractere(vector<char> letras, char letra){

    for(unsigned int i = 0; i < letras.size(); i++)
        if(letras[i] == letra)
             return true;

    return false;
}


void salvarArquivo(string nomeArquivo, string texto){
    // Instanciar arquivo
    ofstream arq(nomeArquivo);

    // Atribuir dados ao arquivo
    arq << texto;

    // fechar arquivo
    arq.close();

}


void salvarArquivoBin(string arquivo, string texto){
    // Instanciar arquivo em modo binário
    ofstream arq(arquivo);

    // Atribuir dados ao arquivo
    arq << texto;

    // fechar arquivo
    arq.close();

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


vector<char> lerCaracteres(string texto)
{
    vector<char> letras;
    letras.resize(0);
    // Percorrer vetor e armazenar letras
    for (unsigned int i = 0; i < texto.length(); ++i)
        letras.push_back(texto[i]);
    return letras;
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
