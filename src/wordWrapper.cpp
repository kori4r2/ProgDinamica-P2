#include "wordWrapper.hpp"
#include <string.h>
#include <iostream>
#include <climits>

void wordWrapper::printSolution(){
	int cost = _cost[0];
	int i = 0;
	while((i < _N) && (cost > 0)){
		if(_cost[i] == cost){
			std::cout << _solution[i];
			cost -= ((strlen(_solution[i]) - 1) * (strlen(_solution[i]) - 1));
		}
		i++;
	}
}

wordWrapper::wordWrapper(int N, int L, char **wordList){ // Construtor da classe
	_N = N;
	_L = L;
	_wordList = wordList;
	_cost = (int*)malloc(sizeof(int) * (_N + 1));
	_cost[N] = 0;
	_solution = (char**)calloc(_N, sizeof(char*));
	_solutionSize = (int*)malloc(sizeof(int) * (_N));
}

void wordWrapper::wrapSquaresSum(){ // Realiza o word wrap utilizando soma de quadrados para calcular o custo
	// Percorre a lista de palavras de tras pra frente, testando linhas que iniciam com cada palavra
	for(int i = _N-1; i >= 0; i--){
		// size armazena o tamanho em caracteres da linha sendo testada
		int size = strlen(_wordList[i]);
		// minCost armazena o custo minimo encontrado ate agora
		_cost[i] = INT_MAX;
		// Enquanto for possivel testar com palavras de modo que a concatenacao das demais caiba na linha, tenta
		for(int j = 0; (i + j < _N) && (size <= _L); j++){
			// Calcula o custo da linha sendo testada
			int curCost = (_L - size) * (_L - size);
			curCost += _cost[i + j + 1];
			// Se o custo for menor do que o encontrado anteriormente
			if(curCost < _cost[i]){
				// Atualiza as variaveis relevantes
				_cost[i] = curCost;
				_solutionSize[i] = j+1;
				// E armazena a string correspondente a linha completa
				_solution[i] = (char*)realloc(_solution[i], sizeof(char) * (size+2));
				_solution[i][0] = '\0';
				for(int k = 0; k <= j; k++){
					strcat(_solution[i], _wordList[i+k]);
				}
				_solution[i][size] = '\n';
				_solution[i][size+1] = '\0';
			}

			// Atualiza size (o if evita seg fault)
			if((i + j + 1) < _N)
				size += strlen(_wordList[i+j+1]) + 1;
		}
	}

	// Imprime o resultado encontrado na tela
	printSolution();
}

wordWrapper::~wordWrapper(){ // Destrutor da classe
	free(_cost);
	for(int i = 0; i < _N; i++){
		free(_wordList[i]);
		if(_solution[i] != NULL)
			free(_solution[i]);
	}
	free(_wordList);
	free(_solution);
	free(_solutionSize);
}
