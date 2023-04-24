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

tabelaHash Map[M]; // Criação da tabela hash

// Função para inicializar a tabela hash
void inicializarTabHash(tabelaHash TH){
    for(int i = 0; i < 701; i++){
        TH.Str = NULL; // Inicializa todas as posições com NULL
    }
}

// Função que converte uma string em um número inteiro
int ConverterString(char Str[]){
    int tamanho = strlen(Str);
    int J = 0;
    for(int i = 0; i < tamanho; i++){
        J += Str[i] * (i + 1);
    }
    return J % M; // Retorna o resultado da divisão do número inteiro obtido pelo tamanho da tabela hash
}

// Funções de hash utilizadas para inserção e busca na tabela hash
int Hash_1(int J){
    return J % M;
}

int Hash_2(int K){
    return 1 + (K % (M - 1));
}

// Função de hash duplo que utiliza as duas funções de hash anteriores para inserção na tabela hash
int Hash_Duplo(int K, int i){
    return (Hash_1(K) + i * Hash_2(K)) % M;
}

// Função que insere um elemento na tabela hash
int Insere_Elemento_TabHash(char String[]){
    int K = ConverterString(String); // Converte a string em um número inteiro
    int j = 0, i = 0;
    while(i < M){
        j = Hash_Duplo(K, i); // Utiliza a função de hash duplo para calcular a posição do elemento na tabela hash
        if(Map[j].Str == NULL){ // Verifica se a posição está vazia
            Map[j].Str = String; // Insere a string na posição
            return 1; // Retorna 1 para indicar que a inserção foi bem sucedida
        }
        else i++; // Caso contrário, incrementa a variável i e calcula novamente a posição do elemento
    }
    return 0; // Retorna 0 para indicar que a inserção falhou
}

// Função que busca um elemento na tabela hash
int BuscaTabHash(char Key[]){
    int K = ConverterString(Key); // Converte a string em um número inteiro
    int i = 0, j = 0;
    while(i < M){
        j = Hash_Duplo(K, i); // Utiliza a função de hash duplo para calcular a posição do elemento na tabela hash
        if(strcmp(Map[j].Str, Key) == 0){ // Verifica se a string armazenada na posição é igual à string buscada
            return j; // Retorna a posição do elemento na tabela hash
        }
        else i++; // Caso contrário, incrementa a variável i e calcula novamente a posição do elemento
    }
    return -1; // Retorna -1 para indicar que o elemento não foi encontrado
}

// Função que remove um elemento da tabela hash
int Remove_Elemento_TabHash(char Key[]){
    int K = BuscaTabHash(Key); // Busca a posição do elemento na tabela hash
    if(K != -1){ // Verifica se o elemento foi encontrado
