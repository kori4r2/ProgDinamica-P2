#include "wordWrapper.hpp"
#include <string.h>
#include <iostream>
#include <climits>

void wordWrapper::printSolution(){
	int cost = _cost[0];
	int wordCount = _N;
	// Percorre os vetores de memoizacao
	for(int i = 0; (i < _N) && (cost >= 0); i++){
		// Se o elemento tiver custo total e numero de palavras restantes igual ao atual, ele faz parte da resposta final e deve ser impresso
		if(_cost[i] == cost && wordCount == _totalWordCount[i]){
			// Imprime a solucao encontrada e atualiza os valores das variaveis
			std::cout << _solution[i];
			cost -= ( (_L - (strlen(_solution[i]) - 1)) * (_L - (strlen(_solution[i]) - 1)) );
			wordCount -= _wordCount[i];
		}
	}
}

wordWrapper::wordWrapper(int N, int L, char **wordList){ // Construtor da classe
	// Aloca a memoria necessaria e inicializa as variaveis necessarias nos vetores de memoizacao
	_N = N;
	_L = L;
	_wordList = wordList;
	_cost = (int*)malloc(sizeof(int) * (_N + 1));
	_cost[N] = 0;
	_totalWordCount = (int*)malloc(sizeof(int) * (_N + 1));
	_totalWordCount[N] = 0;
	_wordCount = (int*)malloc(sizeof(int) * (_N));
	_solution = (char**)calloc(_N, sizeof(char*));
}

void wordWrapper::wrapSquaresSum(){ // Realiza o word wrap utilizando soma de quadrados para calcular o custo
	// Percorre a lista de palavras de tras pra frente, testando linhas que iniciam com cada palavra
	for(int i = _N-1; i >= 0; i--){
		// size armazena o tamanho em caracteres da linha sendo testada
		int size = strlen(_wordList[i]);
		// _cost[i] e inicializado com INT_MAX para garantir que ao menos um resultado sera encontrado
		_cost[i] = INT_MAX;
		// Enquanto for possivel testar com palavras de modo que a concatenacao das demais caiba na linha, tenta
		for(int j = 0; (i + j < _N) && (size <= _L); j++){
			// Calcula o custo da linha sendo testada
			int curCost = (_L - size) * (_L - size);
			curCost += _cost[i + j + 1];
			// Se o custo for menor do que o encontrado anteriormente
			if(curCost < _cost[i]){
				// Atualiza as variaves relevantes
				_cost[i] = curCost;
				_wordCount[i] = j + 1;
				_totalWordCount[i] = j + 1 + (_totalWordCount[i + j + 1]);
				// E armazena a string correspondente a linha completa, colocando um \n no final
				_solution[i] = (char*)realloc(_solution[i], sizeof(char) * (size+2));
				_solution[i][0] = '\0';
				strcat(_solution[i], _wordList[i]);
				for(int k = 1; k <= j; k++){
					strcat(_solution[i], " ");
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
	free(_wordCount);
	free(_totalWordCount);
	free(_solution);
}
