#ifndef PRAIAS_H
#define PRAIAS_H

#include <vector>
#include <string>
#include "GPS.h"
#include "servicos.h"
#include <iostream>
//#include <typeinfo>

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
	praiaFluvial(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia);

	std::string getNome() const;
	GPS getGPS() const;
	std::string getConcelho() const;
	bool getBandeiraAzul() const;
	unsigned int getCapacidade() const;
	virtual std::string getInfo() const;

	void setGPS(GPS gps);
};
std::ostream& operator<<(std::ostream & os, praiaFluvial praia); 


/**
 * @brief      Class for rio. Derivates from praiaFluvial.
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
	std::string getInfo() const;
};


/**
* @brief      Class for albufeira. Derivates from praiaFluvial.
*/
class albufeira : public praiaFluvial
{
	unsigned int area;
public:
	unsigned int getArea() { return this->area; }
	std::string getInfo() const;
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
	int praiaInfoGPS(GPS gps);
	praiaFluvial * getClosestPraia(GPS gps);
	praiaFluvial * findPraia(std::string name) const;

};

#endif