#pragma once
#include <cstdlib>

class wordWrapper{
	private:
		int _N;
		int _L;
		char **_wordList; // Armazena a lista de palavras para realizar o wrapping
		int *_cost; // Armazena os custos totais das solucoes comecando a frase em cada palavra
		char **_solution; // Armazena a linha do resultado com custo minimo comecando com cada palavra
		int *_solutionSize; // Armazena a quantidade de palavras da linha do resultado atual
		void printSolution();
	public:
		wordWrapper(int, int, char**); // Construtor da classe
		void wrapSquaresSum(); // Realiza o word wrap utilizando soma de quadrados para calcular o custo
		~wordWrapper(); // Destrutor da classe
};
