#ifndef PRAIAS_H
#define PRAIAS_H

#include <vector>
#include <string>
#include "GPS.h"
#include "servicos.h"
#include <iostream>

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
	std::string tipo;
public:
	praiaFluvial();
	praiaFluvial(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia);
	~praiaFluvial();

	std::string getNome() const;
	GPS getGPS() const;
	std::string getConcelho() const;
	bool getBandeiraAzul() const;
	unsigned int getCapacidade() const;
	std::vector<servico> getServicos() const;
	std::string getTipo() const;

	virtual std::string getInfo() const;

	void setGPS(GPS gps);
	void setNome(std::string nome);
	void setTipo(std::string tipo);

	virtual unsigned int getLargura() const;
	virtual unsigned int getCaudal() const;
	virtual unsigned int getProfundidade() const;

	virtual unsigned int getArea() const;

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
	rio();
	rio(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia, unsigned int larguraMax, unsigned int caudalMax, unsigned int profundidadeMax);
	~rio();

	unsigned int getLargura() const;
	unsigned int getCaudal() const;
	unsigned int getProfundidade() const;
	std::string getInfo() const;
};


/**
* @brief      Class for albufeira. Derivates from praiaFluvial.
*/
class albufeira : public praiaFluvial
{
	unsigned int area;
public:
	albufeira();
	albufeira(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia, unsigned int area);
	~albufeira();

	unsigned int getArea() const;
	std::string getInfo() const;
};

/**
* @brief      Class for GestorPraias.
*/
class GestorPraias
{
	std::vector<praiaFluvial*> praias;
	std::vector<servicoForaDaPraia*> servicosdefora;
public:
	GestorPraias();
	GestorPraias(std::vector<praiaFluvial*> praias, std::vector<servicoForaDaPraia*> servicosdefora);
	~GestorPraias();

	int praiaInfo(std::string praia);
	int praiaInfoGPS(GPS gps);

	void addPraia(praiaFluvial praia);
	void setPraias(std::vector<praiaFluvial*> input);

	std::vector<praiaFluvial*> getPraias();

	praiaFluvial * getClosestPraia(GPS gps);
	praiaFluvial * findPraia(std::string nome);
	praiaFluvial * findPraia(GPS gps);

	void sortByConcelho();
	void servicosInfo(praiaFluvial praia);

	void LoadPraias(std::string filename);
	void SavePraias(std::string filename);

};


class BadFileInput {

	std::string filename;
public:
	BadFileInput() {}
	BadFileInput(std::string filename) : filename(filename) {}

	std::string getFilename() { return filename; }

};

#endif