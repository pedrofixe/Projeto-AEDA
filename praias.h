#ifndef PRAIAS_INCLUDED
#define PRAIAS_INCLUDED
#include <string>

using namespace std;


class praiaFluvial
{
	string Concelho;
	string GPS;
	bool bandeiraAzul;
	unsigned int capacidade;
	//pontos turisticos

}


class rio : public praiaFluvial
{
	unsigned int larguraMax;
	unsigned int caudalMax;
	unsigned int profundidadeMax;


}


class albufeira : public praiaFluvial
{
	unsigned int area;


}


#endif