#ifndef SERVICOS_H
#define SERVICOS_H

#include <string>
#include "GPS.h"

class servico
{	
	std::string nome;
	GPS gps;
public:
	servico();
	servico(std::string nome, GPS gps);
	~servico();
	GPS getGPS() const;
	std::string getNome() const;

};


class nadadorSalvador : public servico
{

public:
	nadadorSalvador();
	nadadorSalvador(std::string nome, GPS gps);
	~nadadorSalvador();

};

class cafe : public servico
{
public:
	cafe();
	cafe(std::string nome, GPS gps);
	~cafe();
	
};

class restaurante : public servico
{
public:
	restaurante();
	restaurante(std::string nome, GPS gps);
	~restaurante();
	
};

class campo : public servico
{
public:
	campo();
	campo(std::string nome, GPS gps);
	~campo();

};


#endif