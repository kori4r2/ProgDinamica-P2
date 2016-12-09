#pragma once
#include <cstdlib>

class wordWrapper{
	private:
		int _N; // Numero de palavras armazenadas
		int _L; // Numero maximo de caracteres por linha
		char **_wordList; // Armazena a lista de palavras para realizar o wrapping
		int *_cost; // Armazena os custos totais das solucoes comecando a frase em cada palavra
		int *_wordCount; // Armazena o numero de palavras contidas na linha de resultado com custo mini comecando com essa palavra
		int *_totalWordCount; // Armazena o numero de palavras utilizadas na melhor solucao que comeca com cada palavra
		char **_solution; // Armazena a linha do resultado com custo minimo comecando com cada palavra
		void printSolution(); // Imprime a solucao encontrada (so deve ser chamada apos a solucao desejada ser calculada, dentro da funcao correspondente)
	public:
		wordWrapper(int, int, char**); // Construtor da classe
		void wrapSquaresSum(); // Realiza o word wrap utilizando soma de quadrados para calcular o custo
		~wordWrapper(); // Destrutor da classe
};
