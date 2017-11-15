#include "praias.h"
#include "algoritmos.h"
#include <sstream>
#include <fstream>

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

std::vector<servico> praiaFluvial::getServicos() const
{
	return servicosdapraia;
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

void praiaFluvial::setNome(string nome) {
	this->nome = nome;
}


std::ostream& operator<<(std::ostream & os, praiaFluvial praia) {
	os << praia.getInfo();
}


string rio::getInfo() const
{
	string info_rio = praiaFluvial::getInfo();

	info_rio += " A praia trata-se de uma praia fluvial de rio\n";
	info_rio += "Largura Minima da praia: " + to_string(larguraMax);
	info_rio += "Caudal Maximo da praia: " + to_string(caudalMax);
    info_rio += "Profundidade Maximo da praia: " + to_string(profundidadeMax);

	return info_rio;
}

string albufeira::getInfo() const
{
	string info_albufeira = praiaFluvial::getInfo();

	info_albufeira += "A praia trata-se de uma praia fluvial de albufeira \n";
	info_albufeira += "Area da albufeira: " + to_string(area)  + "\n";
	
	return info_albufeira;
}

rio::rio(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia, unsigned int larguraMax, unsigned int caudalMax, unsigned int profundidadeMax): praiaFluvial(nome,concelho,gps,capacidade,servicosdapraia)
{
	this->larguraMax = larguraMax;
	this->caudalMax = caudalMax;
	this->profundidadeMax = profundidadeMax;
}


albufeira::albufeira(std::string nome, std::string concelho, GPS gps, bool bandeiraazul, unsigned int capacidade, std::vector<servico> servicosdapraia, unsigned int area) : praiaFluvial(nome, concelho, gps, bandeiraazul, capacidade, servicosdapraia)
{
	this->area = area;
}

int GestorPraias::praiaInfo(std::string praia) {

	praiaFluvial * temp = this->findPraia(praia);

	if (temp != NULL)
	{
		cout << temp->getInfo();
		return 0;
	}

	return 1;
}

int GestorPraias::praiaInfoGPS(GPS gps) {

	praiaFluvial * temp = this->findPraia(gps);

	if (temp != NULL)
	{
		cout << temp->getInfo();
		return 0;
	}

	return 1;
}

void GestorPraias::addPraia(praiaFluvial praia) {
	praias.push_back(&praia);
}


/**
 * @brief      Gets the closest praia.
 *
 * @param[in]  gps   The GPS coordinates
 *
 * @return     The closest praia to gps.
 */

void GestorPraias::setPraias(std::vector<praiaFluvial*> input) {
	praias = input;
}

std::vector<praiaFluvial*> GestorPraias::getPraias() {
	return praias;
}

praiaFluvial * GestorPraias::getClosestPraia(GPS gps) {

	if (praias.size() == 0)
		return NULL;

	int index = 0;
	int min = praias[0]->getGPS().distance(gps);

	for (int i = 0; i < praias.size(); ++i)
	{
		if (praias[i]->getGPS().distance(gps) < min)
		{
			index = i;
			min = praias[i]->getGPS().distance(gps);
		}
	}

	return praias[index];
}

bool equalNome(praiaFluvial praia1, praiaFluvial praia2) {
	return (praia1.getNome() == praia2.getNome());
}

praiaFluvial * GestorPraias::findPraia(string nome) {

	if (praias.size() == 0)
		return NULL;

	praiaFluvial foo;
	foo.setNome(nome);

	int index = sequentialSearch(praias, foo, equalNome);

	if (index == -1)
		return NULL;

	return praias[index];
}


bool equalGPS(praiaFluvial praia1, praiaFluvial praia2) {
	return (praia1.getGPS() == praia2.getGPS());
}

praiaFluvial * GestorPraias::findPraia(GPS gps) {

	if (praias.size() == 0)
		return NULL;

	praiaFluvial foo;
	foo.setGPS(gps);

	int index = sequentialSearch(praias, foo, equalNome);

	if (index == -1)
		return NULL;

	return praias[index];
}


bool lesserConcelho(praiaFluvial praia1, praiaFluvial praia2) {
	return (praia1.getConcelho() < praia2.getConcelho());
}

void GestorPraias::sortByConcelho() {

	selectionSort(praias, lesserConcelho);
}


void GestorPraias::servicosInfo(praiaFluvial praia)
{
	string nome;
	GPS gps;
	string cafes, restaurantes, nadador, campos;
	int c = 0, r = 0, ns = 0, cd = 0;

	for (unsigned int i = 0; i < praias.size(); i++)
	{
		if (praia.getNome() == praias[i]->getNome() )
		{
			for (unsigned int u = 0; u < praias[i]->getServicos().size(); u++)
			{
				gps = praias[i]->getServicos().at(u).getGPS();

				if (praias[i]->getServicos().at(u).getTipo() == "restaurante")
				{
					r++;
				}
				else if (praias[i]->getServicos().at(u).getTipo() == "cafe")
				{
					c++;
				}
				else if (praias[i]->getServicos().at(u).getTipo() == "campoDesportivo")
				{
					cd++;
				}
				else if (praias[i]->getServicos().at(u).getTipo() == "nadador")
				{
					ns++;
				}
			}
		}
	}
	
	cout << "A praia possui " << c << " cafes, " << r << "restaurantes, " << cd << " campos desportivos e " << ns << " nadadores salvadores\n" ;

}




void GestorPraias::LoadPraias(std::string filename) 
{

	ifstream file(filename); //tipo nome concelho latitude longitude bandeiraazul capacidade (tipo1 nome1 latitude1 longitude1 tipo2 nome2 latitude2 longitude2 ...)
	string temp;

	while (getline(file, temp, '\n'))
	{
		temp += ',';
		stringstream ss(temp);
		string type;
		getline(ss, type, ',');
		string nome;
		getline(ss, nome, ',');
		string concelho;
		getline(ss, concelho, ',');
		string GPS1;
		getline(ss, GPS1, ',');
		string GPS2;
		getline(ss, GPS2, ',');
		string bandeiraazul;
		getline(ss, bandeiraazul, ',');
		string capacidade;
		getline(ss, capacidade, ',');

		string largura;
		string caudal;
		string profundidade;
		string area;

		if (type == "rio")
		{
			getline(ss, largura, ',');
			getline(ss, caudal, ',');
			getline(ss, profundidade, ',');
		}
		else if (type == "albufeira")
		{
			getline(ss, area, ',');
		}
		else
			throw BadFileInput(filename);


		vector<servico> foo;
		string tiposervico;
		string nomeservico;
		string GPSservico1;
		string GPSservico2;

		while (getline(ss, tiposervico, ',') && getline(ss, nomeservico, ',' ) && getline(ss , GPSservico1, ',') && getline(ss, GPSservico2, ','))
		{
			if (tiposervico == "nadadorSalvador")
				foo.push_back(nadadorSalvador(nomeservico));
			else if (tiposervico == "cafe")
				foo.push_back(cafe(nomeservico, GPS(stod(GPSservico1), stod(GPSservico2))));
			else if (tiposervico == "restaurante")
				foo.push_back(restaurante(nomeservico, GPS(stod(GPSservico1), stod(GPSservico2))));
			else if (tiposervico == "campoDesportivo")
				foo.push_back(campoDesportivo(nomeservico, GPS(stod(GPSservico1), stod(GPSservico2))));
			else
				throw BadFileInput(filename);
		}

		if (type == "rio")
			praias.push_back(new rio(nome, concelho, GPS(stod(GPSservico1), stod(GPSservico2)), (bool)stoi(bandeiraazul), stoi(capacidade),  foo, stoi(largura), stoi(caudal), stoi(profundidade)));
		else
			praias.push_back(new albufeira(nome, concelho, GPS(stod(GPSservico1), stod(GPSservico2)), (bool)stoi(bandeiraazul), stoi(capacidade),  foo, stoi(largura), stoi(caudal), stoi(profundidade)));
	}
}


void GestorPraias::SavePraias(std::string filename) {

	
}
