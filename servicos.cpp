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
nadadorSalvador::nadadorSalvador(string nome) servico(nome,GPS(0,0))
{
	this->nome = nome;
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

campoDesportivo::campoDesportivo()
{}

campoDesportivo::campoDesportivo(string nome, GPS gps) : servico(nome, gps)
{}

campoDesportivo::~campoDesportivo()
{}