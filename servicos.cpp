#include "servicos.h"
#include <string>
#include "GPS.h"

class servico
{	
	std::string nome;
	GPS gps;
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