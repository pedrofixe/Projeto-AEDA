#ifndef PRAIAS_INCLUDED
#define PRAIAS_INCLUDED
#include <string>
#include <vector>

using namespace std;

class Servicos
{
	bool Restaurantes;
	unsigned int Nrestaurantes;
	bool AluguerDeBarcos;
};



class Turismo
{
	bool CamposDeJogos;
	bool Alojamentos;

};

class praiaFluvial
{
	string Concelho;
	string GPS;
	bool bandeiraAzul;
	unsigned int capacidade;
	bool ServicosPraia;
	vector<Servicos> ServicosDaPraia;
};


class rio : public praiaFluvial
{
	unsigned int larguraMax;
	unsigned int caudalMax;
	unsigned int profundidadeMax;

};


class albufeira : public praiaFluvial
{
	unsigned int area;


};

#endif