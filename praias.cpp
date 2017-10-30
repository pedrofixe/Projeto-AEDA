#include "praias.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//---------------------------GPS//---------------------------



GPS::GPS(unsigned int graus, unsigned int minutos, unsigned int segundos) : grau(grau), minutos(minutos), segundos(segundos){
	if (0 > graus > 90 || 0 > minutos > 60 || 0 > segundos > 60)
		throw CoordenadasErradas(*this);
}

ostream & operator<< (ostream & os,const GPS & input) {

	return (o << input.graus << 'º' << input.minutos << '\'' << input.segundos << '\"');
}


praiaFluvial::praiaFluvial(string Concelho, string GPS, bool bandeiraAzul, unsigned int capacidade, bool Servicos, vector<Servicos> ServicosDaPraia) {}
