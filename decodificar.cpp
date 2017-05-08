#include "decodificar.h"
#include "huffman.h"
#include <string.h>

/*
 * Ler uma linha, separar o caractere do codigo, instanciar uma estrututa Caractere e retornar
 *
*/
No * separarDicionario(string token){
    // Instanciar caractere
    No * carac = new No();

    // Atribuir caractere respectivo
    carac->caractere = token.at(0);

    // Ler resto da linha | iniciar 2 pra pular o =
    for(unsigned int i = 2; i < token.size(); i++)
        carac->codigo += token.at(i);


    return carac;
}

/*
 * Ler token (de 0 até encontrar o caractere sentinela)
 *
*/
string obterToken(string &msg, char sentinela){
    string token = "";
    int i;

    // Percorrer mensagem e concatenar ao token até achar a sentinela
    for(i = 0; msg.size(); i++){
        if(msg.at(i) == sentinela)
            break;
        token += msg.at(i);
    }

    // Apagar inicio à sentinela e + 1 pra que ele apague a sentinela do token
    msg.erase(0, i + 1);

    return token;
}

/*
 * Remover sentilas de tokens desnecessários no resto da mensagem codificada
 *
*/
string removerSentinelasToken(string msgOriginal, char sentinela){
    string msg;

    // Percorrer mensagem original em busca de sentinelas
    for(unsigned int i = 0; i < msgOriginal.size(); i++)
        if(msgOriginal.at(i) != sentinela)
            msg.push_back(msgOriginal.at(i));


    return msg;
}


/*
 *  Transformar a mensagem codificada em binário novamente (baseada nos códigos)
 *
*/
string binarizarCodigo(string msg, int padding){
    string codigoBin = "";
    stringstream sstream;

    // Converter string caractere a caractere para binario
    for (std::size_t i = 0; i < msg.size(); ++i)
        sstream << bitset<8>(msg.c_str()[i]);

    // Converter stringstream em string
    codigoBin = sstream.str();

    // Remover padding (bits descartaveis)
    //codigoBin.erase(codigoBin.size(), codigoBin.size());

    return codigoBin;
}

/*
 * Buscar caractere baseado no código passado
 *
*/
string buscarCaractere(vector<No *> & dicionario, string cod){
    No * auxNo;
    char auxChar;
    string auxString;

    // Percorrer dicionário
    for(unsigned int i = 0; i < dicionario.size(); i++){

        // Verificar se há o caractere no dicionario e retornar o código
        auxNo = dicionario[i];
        if(auxNo->codigo == cod){
            auxChar = auxNo->caractere;
            auxString = "";
            auxString.push_back(auxChar);

            return auxString;
        }
    }

    return "-na";
}

/*
 * Realizar decodificação, buscando caractere à caractere correspondente ao código lido
 *
*/
string decodificarMensagem(vector<No *> & dicionario, string msg){
    string msgDecodificada = "";
    string msgCodificada = msg;
    string codigoAtual = "";
    string caractereAtual = "";
    bool buscando = true;
    int bits = 0;

    // Percorrer todos os códigos
    while(msgCodificada.size() > 0){
        buscando = true;
        codigoAtual = "";
        bits = 0;

        // Realizar busca no dicionário
        while(buscando){
            // Capturar qtd de bits na busca
            if(msgCodificada.size() > bits)
                codigoAtual += msgCodificada.at(bits++);
            else
                break;

            // Verificar se há um caracter com o código gerado e concatena se achar o caractere
            caractereAtual = buscarCaractere(dicionario, codigoAtual);
            if(caractereAtual != "-na"){
                // concatenar caractere localizado
                msgDecodificada += caractereAtual;
                //cout << msgDecodificada << endl;
                // Caractere localizado, flag de busca negada e reiniciar processo com os bits restantes
                buscando = false;
            }

        }
        // Remover os bits usados para achar o caractere atual
        if(bits < msgCodificada.size())
            msgCodificada.erase(0, bits);
        else
            msgCodificada.erase(0, msgCodificada.size());

    }

    return msgDecodificada;
}

string decodificarTexto(string arquivo){

    // Variaveis auxiliares
    int totalDicionario = 0;
    int totalPadding = 0;
    vector<No *> dicionario;

    string textoCodificado = "";
    string textoDecodificado = "";
    string msgCodificada = "";
    string token = "";

    // Carregar arquivo
    ifstream arq(arquivo, ios::binary);

    // Verifica se arquivo foi encontrado
    if(!arq.is_open()){
        cout << "Arquivo não encontrado! Verifique o caminho." << endl;
        exit(0);
    }

    // Ler dados do arquivo
    stringstream strStream;
    strStream << arq.rdbuf();//lê o arquivo
    textoCodificado = strStream.str();//converter stringstream para string

    // Fechar arquivo
    arq.close();

    // ---------------------------------   Começar a extrair os tokens

    // Extrair informação de quantos caracteres existem no dicionario
    token = obterToken(textoCodificado, ';');
    totalDicionario = stoi(token);

    // Extrair dicionario
    for(int i = 0; i < totalDicionario; i++){
        token = obterToken(textoCodificado, ';');
        No * no = separarDicionario(token);
        dicionario.push_back(no);
    }

    // Extrair informação de quantos bits serão desconsiderados (padding)
    token = obterToken(textoCodificado, ';');
    totalPadding = stoi(token);

    // Remover sentinelas desnecessárias
    //msgCodificada = removerSentinelasToken(textoCodificado, ';');
    msgCodificada = textoCodificado;

    // Binarizar mensagem codificada
    string codigoBinarizado = binarizarCodigo(msgCodificada, totalPadding);

    // Decodificar mensagem a partir da mensagem binarizada
    string mensagemDecodificada = decodificarMensagem(dicionario, codigoBinarizado);

    // Salvar binario da decodificação
    ofstream arqp("./binariodecodificacao.txt");
    arqp << codigoBinarizado;
    arqp.close();

    return mensagemDecodificada;
}
