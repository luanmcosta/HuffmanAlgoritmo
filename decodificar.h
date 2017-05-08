#ifndef DECODIFICAR_H
#define DECODIFICAR_H

#include "huffman.h"

string decodificarTexto(string arquivo);

/*
 * Realizar decodificação, buscando caractere à caractere correspondente ao código lido
 *
*/
string decodificarMensagem(vector<No *> & dicionario, string msg);

#endif // DECODIFICAR_H
