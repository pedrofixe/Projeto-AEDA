#include "servicos.h"
#include <string>

using namespace std;


//------------------------------SERVICO------------------------------

servico::servico()
{}

servico::servico(string nome, GPS gps) : nome(nome), gps(gps)
{}

servico::~servico()
{}

GPS servico::getGPS() const
{
	return gps;
}

string servico::getNome() const
{
	return nome;
}


//------------------------------NADADOR------------------------------

nadadorSalvador::nadadorSalvador()
{}

nadadorSalvador::nadadorSalvador(string nome, GPS gps) : servico(nome, gps) 
{}

nadadorSalvador::~nadadorSalvador()
{}

//------------------------------CAFE------------------------------

cafe::cafe()
{}

cafe::cafe(string nome, GPS gps) : servico(nome, gps)
{}

cafe::~cafe()
{}

//------------------------------RESTAURANTE------------------------------

restaurante::restaurante()
{}

restaurante::restaurante(string nome, GPS gps) : servico(nome, gps)
{}

restaurante::~restaurante()
{}

//------------------------------CAMPO------------------------------

campo::campo()
{}

campo::campo(string nome, GPS gps) : servico(nome, gps)
{}

campo::~campo()
{}