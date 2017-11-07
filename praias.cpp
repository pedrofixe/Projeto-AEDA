#include "praias.h"

using namespace std;



praiaFluvial::praiaFluvial()
{}


praiaFluvial::praiaFluvial(string concelho, GPS gps, bool bandeirazul, unsigned int capacidade, vector<Servico> servicosdapraia) : concelho(concelho), gps(gps), bandeiraazul(bandeiraazul), capacidade(capacidade), servicosdapraia(servicosdapraia)
{}


//metodos get praia fluvial
string praiaFluvial::getPraiaName()
{
	return this->nome;
}

GPS praiaFluvial::getGPS()
{
	return this->gps;
}
string praiaFluvial::getConcelho()
{
	return this->concelho;
}

bool praiaFluvial::getBandeiraAzul()
{
	return bandeiraazul;
}
unsigned int praiaFluvial::getCapacidade()
{
	return capacidade;
}


// Gestor
void GestorPraias::praiaInfo(string praia)
{
	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if (praia == praias[i].getPraiaName())
		{
			cout << "Nome da Praia: " << praias[i].getPraiaName() << " \n ";
			cout << "Concelho onde a praia se situa: " << praias[i].getConcelho() << " \n ";
			cout << "Capacidade da praia: " << praias[i].getCapacidade() << " \n ";
			if (praias[i].getBandeiraAzul() == true)
			{
				cout << "A praia possui bandeira azul \n";
			}
			else
			{
				cout << "A praia nao possui bandeira azul \n";
			}

		}
	}


}