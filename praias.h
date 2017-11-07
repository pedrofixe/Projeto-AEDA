#ifndef PRAIAS_H
#define PRAIAS_H

#include <vector>
#include <string>
#include "GPS.h"


class Servico
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

	std::string nome;
	std::string concelho;
	GPS gps;
	bool bandeiraazul;
	unsigned int capacidade;
	std::vector<Servico> servicosdapraia;
public:
	praiaFluvial();
	praiaFluvial(std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<Servico> servicosdapraia);
	string getPraiaName();
	GPS getGPS();
	string getConcelho();
	bool getBandeiraAzul();
	unsigned int getCapacidade();


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

class GestorPraias : public praiaFluvial
{
	std::vector<praiaFluvial> praias;
public:
	void praiaInfo(string praia);


};

#endif