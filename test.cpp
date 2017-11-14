#include <iostream>
#include <string>
#include <vector>
#include "GPS.h"
#include "praias.h"

using namespace std;

GestorPraias gestor;

void menu()
{
	unsigned int option;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|        Welcome to our guide of Praias Fluviais in Portugal !          |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Enter a number to choose the sub-menu that you want to go !\n";
	cout << "1- See a fluvial beach by inserting name \n";
	cout << "2- See a fluvial beach by inserting GPS \n";
	cout << "3- Discover the nearest beach around your GPS coordenates	\n";

	cout << "Choose an option : "; cin >> option; cout << endl;
	while (cin.fail() || option < 1 || option > 6)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please write a valid number ! \n";
		cin >> option;
	}

	switch (option)
	{

	case 1:
	{
		fluvial();
	}
	}
}


 void fluvial()
 {
	 char c;
 	string praia;
 	cout << "enter the name of the fluvial beach that you want to get info !" << endl;
 	getline(cin, praia);

	gestor.praiaInfo(praia);

	if (gestor.praiaInfo() == 1)
	{
		cout << " We couldn't find the beach you were searching :( \n";
	}

	cout << "Do you wanna try again ? (Y/N) \n";
	if (c == 'Y')
	{
		fluvial();
	}
	else menu();



 }



int main()
{
	
	menu();

	GPS Porto(41.157352, -8.628255);
	GPS Lisboa(38.722330, -9.139089);

	cout << "\n" << Porto.distance(Lisboa) << "\n\n";


	return 0;
}