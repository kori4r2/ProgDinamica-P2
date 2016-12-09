#include "wordWrapper.hpp"
#include <string.h>

wordWrapper::wordWrapper(int N, int L, char **wordList){ // Construtor da classe
	_N = N;
	_L = L;
	_wordList = wordList;
	_cost = (int*)malloc(sizeof(int) * (_N + 1));
	_solution = (char**)calloc(_N, sizeof(char*));
}

const char *wordWrapper::wrapSquaresSum(){ // Realiza o word wrap utilizando soma de quadrados para calcular o custo
	return "LUL";
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
}
