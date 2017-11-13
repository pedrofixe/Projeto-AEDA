#include "servicos.h"
#include <string>
#include "GPS.h"

class servico
{	
	std::string nome;
	GPS gps;
};


class nadadorSalvador : public servico
{

public:
	nadadorSalvador();
	~nadadorSalvador();

}

class cafe : public servico
{
public:
	cafe();
	~cafe();
	
};

class restaurante : public servico
{
public:
	restaurante();
	~restaurante();
	
};

class campo : public servico
{
public:
	servico();
	~servico();

}