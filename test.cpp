#include <iostream>
#include <string>
#include <vector>
#include "GPS.h"
#include "praias.h"
#include "servicos.h"

using namespace std;

// void fluvial()
// {
// 	string praia;
// 	cout << "Enter the name of the fluvial beach that you want to get info !" << endl;
// 	getline(cin, praia);

// 	for (unsigned int i = 0; i < praias.get; i++)
// 	{

// 	}



// }



int main()
{
	// unsigned int option;
	// cout << "-------------------------------------------------------------------------" << endl;
	// cout << "|        Welcome to our guide of Praias Fluviais in Portugal !          |" << endl;
	// cout << "-------------------------------------------------------------------------" << endl;
	// cout << "Enter a number to choose the sub-menu that you want to go ! " << endl;
	// cout << "1- See a fluvial beach ";

	// cout << "Choose an option : "; cin >> option; cout << endl;
	// while (cin.fail() || option < 1 || option > 6)
	// {
	// 	cin.clear();
	// 	cin.ignore(1000, '\n');
	// 	cout << "Please write a valid number ! \n";
	// 	cin >> option;
	// }

	// switch (option)
	// {

	// case 1:
	// {
	// 	fluvial();
	// }





	// }


	GPS gps1(2.3213, 4.312312);



	cout << "\n" << gps1 << "\n\n";
	return 0;
}