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
GPS servico::getGPS() const {
	return gps;
}

/**
 * @brief      Gets the name of servico
 *
 * @return     The name.
 */
string servico::getNome() const {
	return nome;
}
string servico::getTipo() const {
	return tipo;
}

//2 parte trabalho

bool servico::getAberto() const
{
	return aberto;
}

data servico::getData() const
{
	return dt;
}

string servico::getInfo() const
{
	string info;

	info += "Tipo do servico: " + tipo + ", ";
	info += "nome do servico: " + nome + ", ";
	info += "data da ultima inspecao: " + dt.getInfo();

	return info;
}

void servico::setTipo(string tipo)
{
	this->tipo = tipo;
}

void servico::makeInspection(bool state, data dt)
{
	this->aberto = state;
	this->dt = dt;
}

void servico::open(data dt)
{
	makeInspection(true, dt);
}

void servico::close(data dt)
{
	makeInspection(false, dt);
}

bool operator<(const servico& srvc1, const servico& srvc2) {
	return (srvc2.getData() < srvc2.getData());
}

std::ostream& operator<<(std::ostream& os, const servico& srvc){
	return (os << srvc.getInfo());
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
	setTipo("nadadorSalvador");
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


//------------------------------SERVICOFORADAPRAIA------------------------------


servicoForaDaPraia::servicoForaDaPraia()
{}

servicoForaDaPraia::servicoForaDaPraia(string nome, GPS gps) : servico(nome, gps)
{}

servicoForaDaPraia::~servicoForaDaPraia()
{}

//------------------------------PONTOTURISTICO------------------------------



pontoTuristico::pontoTuristico()
{}

pontoTuristico::pontoTuristico(string nome, GPS gps) : servicoForaDaPraia(nome, gps)
{
	setTipo("pontoTuristico");
}

pontoTuristico::~pontoTuristico()
{}

//------------------------------ALOJAMENTO------------------------------


alojamento::alojamento()
{}

alojamento::alojamento(string nome, GPS gps) : servicoForaDaPraia(nome, gps)
{
	setTipo("alojamento");
}

alojamento::~alojamento()
{}

