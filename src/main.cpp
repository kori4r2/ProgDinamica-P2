#include <cstdio>
#include <iostream>
#include "myStrings.hpp"
#include "wordWrapper.hpp"

int main(int argc, char *argv[]){

	int L, N, i;
	char **wordList;

	// Le os valores de L e N
	std::cin >> L >> N;
	// Aloca a memoria necessaria para armazenar as palavras
	wordList = (char**)malloc(sizeof(char*) * N);

	// Le as palavras da entrada padrao
	for(i = 0; i < N; i++){
		wordList[i] = myGetLine(stdin);
	}

	// Cria o wordWrapper
	wordWrapper *wrapper = new wordWrapper(N, L, wordList);

	// Escreve na saida o resultado do word wrap utilizando minima soma de quadrados
	wrapper->wrapSquaresSum();

	// Libera a memoria alocada
	delete(wrapper);

	return 0;
}
