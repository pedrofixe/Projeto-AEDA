#include "praias.h"
#include "algoritmos.h"

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
praiaFluvial::praiaFluvial(string nome, string concelho, GPS gps, bool bandeirazul, unsigned int capacidade, vector<servico> servicosdapraia) : concelho(concelho), gps(gps), bandeiraazul(bandeiraazul), capacidade(capacidade), servicosdapraia(servicosdapraia)
{}


/**
 * @brief      Gets the praia's name.
 *
 * @return     The praia's name.
 */
string praiaFluvial::getNome() const
{
	return this->nome;
}

/**
 * @brief      Gets the gps.
 *
 * @return     The gps.
 */
GPS praiaFluvial::getGPS() const
{
	return this->gps;
}
/**
 * @brief      Gets the praia's concelho.
 *
 * @return     The praia's concelho.
 */
string praiaFluvial::getConcelho() const
{
	return this->concelho;
}
/**
 * @brief      Gets the praia's bandeira azul.
 *
 * @return     The praia's bandeira azul.
 */
bool praiaFluvial::getBandeiraAzul() const
{
	return bandeiraazul;
}
/**
 * @brief      Gets the praia's capacidade.
 *
 * @return     The praia's capacidade.
 */
unsigned int praiaFluvial::getCapacidade() const
{
	return capacidade;
}

/**
 * @brief      Constructs the Gestor .
 */
GestorPraias::GestorPraias()
{}

/**
 * @brief      Gets the information from a praiaFluvial.
 *
 * @return     The information.
 */
string praiaFluvial::getInfo() const
{
	string info;

	info += "Nome da Praia: " + nome + " \n ";
	info += "Concelho onde a praia se situa: " + concelho + " \n ";
	info += "Capacidade da praia: " + to_string(capacidade) + "\n ";
	if (bandeiraazul == true)
	{
		info += "Bandeira azul: A praia possui bandeira azul\n";
	}
	else
	{
		info += "Bandeira azul: A praia nao possui bandeira azul\n";
	}

	return info;
}

void praiaFluvial::setGPS(GPS gps) {
	this->gps = gps;
}

/**
 * @brief      { operator_description }
 *
 * @param      os     The operating system
 * @param[in]  praia  The praia
 *
 * @return     { description_of_the_return_value }
 */
std::ostream& operator<<(std::ostream & os, praiaFluvial praia) {
	os << praia.getInfo();
}


string rio::getInfo() const
{
	string info_rio = praiaFluvial::getInfo();

	info_rio += " A praia numa praia fluvial de rio\n";
	info_rio += "Largura Minima da praia: " + to_string(larguraMax);
	info_rio += "Caudal Maximo da praia: " + to_string(caudalMax);
    info_rio += "Profundidade Maximo da praia: " + to_string(profundidadeMax);

	return info_rio;
}

string albufeira::getInfo() const
{
	string info_albufeira = praiaFluvial::getInfo();

	info_albufeira += "A praia ?uma praia fluvial de albufeira \n";
	info_albufeira += "?rea da albufeira: " + to_string(area)  + "\n";
	
	return info_albufeira;
}


int GestorPraias::praiaInfo(string praia)
{

	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if (praia == praias[i]->getNome())
		{
			cout << praias[i]->getInfo();
			return 0;
		}

	}
	
	return 1;
}


/**
 * @brief      { function_description }
 *
 * @param[in]  gps   The gps
 *
 * @return     { description_of_the_return_value }
 */
int GestorPraias::praiaInfoGPS(GPS gps)
{
	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if ( gps == praias[i]->getGPS())
		{
			cout << praias[i]->getInfo();
			break;
			return 0;
		}


	}

	return 1;
}


/**
 * @brief      Gets the closest praia.
 *
 * @param[in]  gps   The GPS coordinates
 *
 * @return     The closest praia to gps.
 */

bool equalGPS(praiaFluvial praia1, praiaFluvial praia2) {
	return (praia1.getGPS() == praia2.getGPS());
}
praiaFluvial * GestorPraias::getClosestPraia(GPS gps) {

	if (praias.size() == 0)
		return NULL;

	vector<int> ola = {2,3,1,4};

	algoritmos::selectionSort(ola);

	return NULL;
}
