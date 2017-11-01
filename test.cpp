#include <iostream>
#include "praias.h"
#include "GPS.h"

using namespace std;

int main()
{
	cout << "\n";
	praiaFluvial ola;


	GPS coisas(65,32,12);

	cout << "Coordenadas : " << coisas;


	cout << "\n\n";
	return 0;
}