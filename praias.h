#ifndef PRAIAS_INCLUDED
#define PRAIAS_INCLUDED
#include <string>
#include <vector>
#include <ostream>

using namespace std;


class GPS {

	unsigned int graus;
	unsigned int minutos;
	unsigned int segundos;

	GPS(unsigned int graus, unsigned int minutos, unsigned int segundos);
	double distance(const GPS & gps2);

};
	ostream& operator <<(ostream & os,const GPS & input);


class CoordenadasErradas {
	
	GPS input;

public:

	CoordenadasErradas(GPS input);

	GPS getGPS()
	{
		return input;
	}


};


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
	praiaFluvial(string concelho, string gps, bool bandeirazul, unsigned int capacidade, bool servicos, vector<Servicos> servicosdapraia);
	string concelho;
	string GPS;
	bool bandeiraazul;
	unsigned int capacidade;
	vector<Servicos> servicosdapraia;
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