// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho da tabela hash
#define M 701

// Estrutura que representa cada elemento da tabela hash
typedef struct{
    char *Str; // String armazenada na tabela hash
} tabelaHash;

tabelaHash Map[M]; // Cria��o da tabela hash

// Fun��o para inicializar a tabela hash
void inicializarTabHash(tabelaHash TH){
    for(int i = 0; i < 701; i++){
        TH.Str = NULL; // Inicializa todas as posi��es com NULL
    }
}

// Fun��o que converte uma string em um n�mero inteiro
int ConverterString(char Str[]){
    int tamanho = strlen(Str);
    int J = 0;
    for(int i = 0; i < tamanho; i++){
        J += Str[i] * (i + 1);
    }
    return J % M; // Retorna o resultado da divis�o do n�mero inteiro obtido pelo tamanho da tabela hash
}

// Fun��es de hash utilizadas para inser��o e busca na tabela hash
int Hash_1(int J){
    return J % M;
}

int Hash_2(int K){
    return 1 + (K % (M - 1));
}

// Fun��o de hash duplo que utiliza as duas fun��es de hash anteriores para inser��o na tabela hash
int Hash_Duplo(int K, int i){
    return (Hash_1(K) + i * Hash_2(K)) % M;
}

// Fun��o que insere um elemento na tabela hash
int Insere_Elemento_TabHash(char String[]){
    int K = ConverterString(String); // Converte a string em um n�mero inteiro
    int j = 0, i = 0;
    while(i < M){
        j = Hash_Duplo(K, i); // Utiliza a fun��o de hash duplo para calcular a posi��o do elemento na tabela hash
        if(Map[j].Str == NULL){ // Verifica se a posi��o est� vazia
            Map[j].Str = String; // Insere a string na posi��o
            return 1; // Retorna 1 para indicar que a inser��o foi bem sucedida
        }
        else i++; // Caso contr�rio, incrementa a vari�vel i e calcula novamente a posi��o do elemento
    }
    return 0; // Retorna 0 para indicar que a inser��o falhou
}

// Fun��o que busca um elemento na tabela hash
int BuscaTabHash(char Key[]){
    int K = ConverterString(Key); // Converte a string em um n�mero inteiro
    int i = 0, j = 0;
    while(i < M){
        j = Hash_Duplo(K, i); // Utiliza a fun��o de hash duplo para calcular a posi��o do elemento na tabela hash
        if(strcmp(Map[j].Str, Key) == 0){ // Verifica se a string armazenada na posi��o � igual � string buscada
            return j; // Retorna a posi��o do elemento na tabela hash
        }
        else i++; // Caso contr�rio, incrementa a vari�vel i e calcula novamente a posi��o do elemento
    }
    return -1; // Retorna -1 para indicar que o elemento n�o foi encontrado
}

// Fun��o que remove um elemento da tabela hash
int Remove_Elemento_TabHash(char Key[]){
    int K = BuscaTabHash(Key); // Busca a posi��o do elemento na tabela hash
    if(K != -1){ // Verifica se o elemento foi encontrado
