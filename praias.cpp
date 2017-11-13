#include "praias.h"

using namespace std;


/**
 * @brief      Constructs the object.
 */
praiaFluvial::praiaFluvial()
{}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  concelho         The concelho
 * @param[in]  gps              The gps
 * @param[in]  bandeirazul      The bandeirazul
 * @param[in]  capacidade       The capacidade
 * @param[in]  servicosdapraia  The servicosdapraia
 */
praiaFluvial::praiaFluvial(string concelho, GPS gps, bool bandeirazul, unsigned int capacidade, vector<Servico> servicosdapraia) : concelho(concelho), gps(gps), bandeiraazul(bandeiraazul), capacidade(capacidade), servicosdapraia(servicosdapraia)
{}


/**
 * @brief      Gets the praia's name.
 *
 * @return     The praia's name.
 */
string praiaFluvial::getNome()
{
	return this->nome;
}

/**
 * @brief      Gets the gps.
 *
 * @return     The gps.
 */
GPS praiaFluvial::getGPS()
{
	return this->gps;
}
/**
 * @brief      Gets the praia's concelho.
 *
 * @return     The praia's concelho.
 */
string praiaFluvial::getConcelho()
{
	return this->concelho;
}
/**
 * @brief      Gets the praia's bandeira azul.
 *
 * @return     The praia's bandeira azul.
 */
bool praiaFluvial::getBandeiraAzul()
{
	return bandeiraazul;
}
/**
 * @brief      Gets the praia's capacidade.
 *
 * @return     The praia's capacidade.
 */
unsigned int praiaFluvial::getCapacidade()
{
	return capacidade;
}


/**
 * @brief      { function_description }
 *
 * @param[in]  praia  The praia
 */

GestorPraias::GestorPraias()
{}

void GestorPraias::praiaInfo(string praia)
{
	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if (praia == praias[i].getNome())
		{
			cout << "Nome da Praia: " << praias[i].getNome() << " \n ";
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