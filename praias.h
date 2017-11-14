#ifndef PRAIAS_H
#define PRAIAS_H

#include <vector>
#include <string>
#include "GPS.h"
#include "servicos.h"
#include <typeinfo>

/**
 * @brief      Class for praias fluviais.
 */
class praiaFluvial
{
	std::string nome;
	std::string concelho;
	GPS gps;
	bool bandeiraazul;
	unsigned int capacidade;
	std::vector<servico> servicosdapraia;
public:
	praiaFluvial();
	praiaFluvial(std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia);
	std::string getNome();
	GPS getGPS();
	std::string getConcelho();
	bool getBandeiraAzul();
	unsigned int getCapacidade();
	virtual string getInfo() const;
};

/**
 * @brief      Class for rio.
 */
class rio : public praiaFluvial
{
	unsigned int larguraMax;
	unsigned int caudalMax;
	unsigned int profundidadeMax;
public:
	unsigned int getLargura() { return this->larguraMax; }
	unsigned int getCaudal() { return this->caudalMax; }
	unsigned int getProfundida() { return this->profundidadeMax; }
	string getInfo() const;
};


/**
* @brief      Class for albufeira.
*/
class albufeira : public praiaFluvial
{
	unsigned int area;
public:
	unsigned int getArea() { return this->area; }
	string getInfo() const;
};

/**
* @brief      Class for GestorPraias.
*/
class GestorPraias
{
	std::vector<praiaFluvial*> praias;
public:
	GestorPraias();
	int praiaInfo(std::string praia);
	int praiaInfoGPS(GPS(double x, double y));
	praiaFluvial * getClosestPraia(const GPS & gps) const;
};

#endif