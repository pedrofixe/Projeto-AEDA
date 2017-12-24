#include <iostream>
#include "menu.h"
#include "data.h"

using namespace std;

int main()
{
	cout << "\n";

	menu main;
	main.Begin();

	cout << "\n\n";
	return 0;
}


// TO DO:
// 1 - Fazer a priority_queue ordenada pela data da ultima inspecao de cada tipo de servico
// 2 - Adicionar um submenu para registar uma inspecao, atualizando a data da ultima inspecao desse tipo de servico
// 3 - Passar os servicos de fora que nao estao ativos de momento para um unordered_set e registar a data de encerramento (temporario ou permanente). Quando passarem a estar disponiveis voltam para o vetor