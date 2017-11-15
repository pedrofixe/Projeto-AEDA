 #include "servicos.h"

using namespace std;


//------------------------------SERVICO------------------------------

/**
 * @brief      Constructs servico.
 */
servico::servico()
{}

/**
 * @brief      Constructs servico.
 *
 * @param[in]  nome  The name
 * @param[in]  gps   The gps
 */
servico::servico(string nome, GPS gps) : nome(nome), gps(gps)
{}

/**
 * @brief      Destroys servico.
 */
servico::~servico()
{}

/**
 * @brief      Gets the gps coordinates of servico.
 *
 * @return     The gps.
 */
GPS servico::getGPS() const
{
	return gps;
}

/**
 * @brief      Gets the name of servico
 *
 * @return     The name.
 */
string servico::getNome() const
{
	return nome;
}
string servico::getTipo() const
{
	return tipo;
}

void servico::setTipo(string tipo)
{
	this->tipo = tipo;
}

servicoForaDaPraia::servicoForaDaPraia()
{}

servicoForaDaPraia::servicoForaDaPraia(string nome, GPS gps)
{
	this->nome = nome;
	this->gps = gps;
}

string servicoForaDaPraia::getNome() const
{
	return nome;
}

GPS servicoForaDaPraia::getGPS() const
{
	return gps;
}

pontosTuristicos::pontosTuristicos()
{}

pontosTuristicos::pontosTuristicos(string nome, GPS gps)
{
	this->nome = nome;
	this->gps = gps;
}

string pontosTuristicos::getNome() const
{
	return nome;
}

GPS pontosTuristicos::getGPS() const
{
	return gps;
}


alojamento::alojamento()
{}

alojamento::alojamento(string nome, GPS gps)
{
	this->nome = nome;
	this->gps = gps;
}

string alojamento::getNome() const
{
	return nome;
}

GPS alojamento::getGPS() const
{
	return gps;
}

//------------------------------NADADOR------------------------------

/**
 * @brief      Constructs lifeguard.
 */
nadadorSalvador::nadadorSalvador()
{}

/**
 * @brief      Constructs lifeguard with nome as name and gps as its GPS coordinates.
 *
 * @param[in]  nome  The name
 * @param[in]  gps   The GPS coordinates
 */
nadadorSalvador::nadadorSalvador(string nome): servico(nome,GPS(0,0))
{
	setTipo("nadador");
}

/**
 * @brief      Destroys lifeguard.
 */
nadadorSalvador::~nadadorSalvador()
{}

//------------------------------CAFE------------------------------

/**
 * @brief      Constructs cafe.
 */
cafe::cafe()
{}

/**
 * @brief      Constructs cafe.
 *
 * @param[in]  nome  The name
 * @param[in]  gps   The GPS coordinates
 */
cafe::cafe(string nome, GPS gps) : servico(nome, gps)
{
	setTipo("cafe");
}

cafe::~cafe()
{}

//------------------------------RESTAURANTE------------------------------

restaurante::restaurante()
{}

restaurante::restaurante(string nome, GPS gps) : servico(nome, gps)
{
   setTipo("restaurante");
}

restaurante::~restaurante()
{}

//------------------------------CAMPO------------------------------

campoDesportivo::campoDesportivo()
{}

campoDesportivo::campoDesportivo(string nome, GPS gps) : servico(nome, gps)
{
	setTipo("campoDesportivo");
}

campoDesportivo::~campoDesportivo()
{}

