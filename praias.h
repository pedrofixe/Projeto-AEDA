#ifndef PRAIAS_H
#define PRAIAS_H

#include <vector>
#include <string>
#include "GPS.h"
#include "servicos.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>

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
	std::vector<servico*> servicosdapraia;
	std::string tipo;

public:
	praiaFluvial();
	praiaFluvial(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico*> servicosdapraia);
	praiaFluvial(const praiaFluvial& praia);
	~praiaFluvial();

	std::string getNome() const;
	GPS getGPS() const;
	std::string getConcelho() const;
	bool getBandeiraAzul() const;
	unsigned int getCapacidade() const;
	std::vector<servico*> getServicos() const;
	std::string getTipo() const;
	virtual std::string getInfo() const;

	void setNome(std::string nome);
	void setGPS(GPS gps);
	void setBandeira(bool bandeiraazul);
	void setTipo(std::string tipo);

	void listServicos() const;

	bool operator<(const praiaFluvial& praia1) const;
	bool operator==(const praiaFluvial& praia1) const;

	virtual unsigned int getLargura() const;
	virtual unsigned int getCaudal() const;
	virtual unsigned int getProfundidade() const;

	virtual unsigned int getArea() const;

	void print(std::ostream& os) const;

};
std::ostream& operator<<(std::ostream & os, const praiaFluvial& praia); 


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
	rio(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico*> servicosdapraia, unsigned int larguraMax, unsigned int caudalMax, unsigned int profundidadeMax);
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
	albufeira(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico*> servicosdapraia, unsigned int area);
	~albufeira();

	unsigned int getArea() const;
	std::string getInfo() const;
};



struct comparePraia
{
  bool operator() (const praiaFluvial* lhs, const praiaFluvial* rhs) const
  {
  	return *lhs<*rhs;
  }

};

struct compareServico
{
	bool operator() (const servico* lhs, const servico* rhs) const
  {
  	return !(*lhs<*rhs);
  }
};

struct servicoHash
{
	int operator() (const servicoForaDaPraia* srvc) const
	{
		return static_cast<int>(std::hash<std::string>()(srvc->getNome())); //Mudar para GPS
	}

	bool operator() (const servicoForaDaPraia* srvc1, const servicoForaDaPraia* srvc2) const
	{
		return (srvc1->getNome() == srvc2->getNome());
	}
};


//2
typedef std::unordered_set<servicoForaDaPraia*, servicoHash, servicoHash> tabHS;

/**
* @brief      Class for GestorPraias.
*/
class GestorPraias
{
	std::set<praiaFluvial*, comparePraia> praias; // BST
	std::vector<servicoForaDaPraia*> servicosdefora;
	std::vector<std::priority_queue<servico*, std::vector<servico*>, compareServico>> inspecoes; // 0 = nadadorSalvador, 1 = cafe, 2 = restaurante, 3 = campoDesportivo
	tabHS servicosnaoativos;

public:
	GestorPraias();
	GestorPraias(std::set<praiaFluvial*, comparePraia> praias, std::vector<servicoForaDaPraia*> servicosdefora);
	~GestorPraias();

	int praiaInfo(std::string praia);
	int praiaInfoGPS(GPS gps);

	void addPraia(praiaFluvial praia);
	void removePraia(std::set<praiaFluvial*, comparePraia>::iterator it);
	void setPraias(std::set<praiaFluvial*, comparePraia> input);

	std::set<praiaFluvial*, comparePraia> getPraias();
	std::vector<servicoForaDaPraia*> getServicos();

	praiaFluvial getPraia(std::set<praiaFluvial*, comparePraia>::iterator it);

	std::set<praiaFluvial*, comparePraia>::iterator getClosestPraia(GPS gps);
	std::set<praiaFluvial*, comparePraia>::iterator findPraia(std::string nome);
	std::set<praiaFluvial*, comparePraia>::iterator findPraia(GPS gps);
	bool isEnd(std::set<praiaFluvial*, comparePraia>::iterator &it);

	void makePraiaInspection(std::string srvcname, std::string tipo, data dt);

	bool closeService(std::string srvcname, bool permanente, data dt);
	bool openService(std::string srvcname, data dt);

	void listPraias() const;
	void listServicosDeFora() const;
	void listServicosNaoAtivos() const;

	void servicosInfo(praiaFluvial praia);

	bool LoadPraias(std::string filename);
	bool SavePraias(std::string filename);

	//2
	tabHS getServicosNaoAtivos() const;

};


class BadFileInput {

	std::string filename;
public:
	BadFileInput() {}
	BadFileInput(std::string filename) : filename(filename) {}

	std::string getFilename() { return filename; }

};

#endif