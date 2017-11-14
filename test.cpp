#include <iostream>
#include <string>
#include <vector>
#include "GPS.h"
#include "praias.h"
#include "servicos.h"

using namespace std;

GestorPraias gestor;

void fluvial_name();
void fluvial_gps();

void menu()
{
	unsigned int option;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|        Welcome to our guide of Praias Fluviais in Portugal !  :D        |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Enter a number to choose the sub-menu that you want to go !\n";
	cout << "1- See a fluvial beach by inserting name \n";
	cout << "2- See a fluvial beach by inserting GPS \n";
	cout << "3- Discover the nearest beach around your GPS coordenates	\n";
	cout << "4- See the beaches of a county \n";

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
			fluvial_name();
		}

		case 2:
		{
			fluvial_gps();
		}


	}
}


 void fluvial_name()
 {
	 char c;
 	string praia;
 	cout << "Enter the name of the fluvial beach that you want to get info !" << endl;
	cout << "Name of the beach: ";
	getline(cin, praia);

	gestor.praiaInfo(praia);

	if (gestor.praiaInfo(praia) == 1)
	{
		cout << " We couldn't find the beach you were searching :( \n";
	}

	cout << "Do you wanna try again ? (Y/N) \n";
	if (c == 'Y')
	{
		fluvial_name();
	}
	else 
		menu();



 }

 void fluvial_gps()
 {
	 double latitude, longitude;
	 
	 cout << "Please enter the latitude of the beach ! \n";
	 cout << "Latitude: ";
	 while (cin.fail() )
	 {
		 cin.clear();
		 cin.ignore(1000, '\n');
		 cout << "Please write a valid number ! \n";
		 cin >> latitude;
	 }
	 
	 cout << "Now please enter the longitude ! \n";
	 cout << "Longitude: ";
	 while (cin.fail() )
	 {
		 cin.clear();
		 cin.ignore(1000, '\n');
		 cout << "Please write a valid number ! \n";
		 cin >> longitude;
	 }

	 gestor.praiaInfoGPS( GPS(latitude, longitude) );



 }

int main()
{
	menu();
	GPS gps1(2.3213, 4.312312);
	cout << "\n" << gps1 << "\n\n";
	return 0;
}