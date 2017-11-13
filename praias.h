#ifndef PRAIAS_H
#define PRAIAS_H

#include <vector>
#include <string>
#include "GPS.h"




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
	std::vector<Servico> servicosdapraia;
public:
	praiaFluvial();
	praiaFluvial(std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<Servico> servicosdapraia);
	std::string getNome();
	GPS getGPS();
	std::string getConcelho();
	bool getBandeiraAzul();
	unsigned int getCapacidade();


};

/**
 * @brief      Class for rio.
 */
class rio : public praiaFluvial
{
	unsigned int larguraMax;
	unsigned int caudalMax;
	unsigned int profundidadeMax;

};

/**
 * @brief      Class for albufeira.
 */
class albufeira : public praiaFluvial
{
	unsigned int area;


};

class GestorPraias : public praiaFluvial
{
	std::vector<praiaFluvial> praias;
public:
	void praiaInfo(std::string praia);


};

#endif