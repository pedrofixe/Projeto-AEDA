#include "menu.h"
#include "ui_utilities.h"
#include <fstream>

using namespace std;

menu::menu()
{}

menu::menu(unsigned int width, unsigned int height) : width(width), height(height)
{}


void menu::MainMenu()
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
		cout << "5- See the services of a beach \n";

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
	 			Menu1();
	 		}

	 		case 2:
	 		{
	 			Menu2();
	 		}
			
			case 3:
			{
				Menu3();
			}
			
			case 4:
			{
				Menu4();
			}

			case 5:
			{
				Menu5();
			}

	 	}	
}

void menu::Menu1()
{
	char c;
	string praia;
	cout << "Enter the name of the fluvial beach that you want to get info !\n";
    cout << "Name of the beach: ";
	getline(cin, praia);

	praiaFluvial * temp = gestor.findPraia(praia);

	 if (temp == NULL)
	 {
	 	cout << " We couldn't find the beach you were searching for :( \n";
	 }

	 cout << "Do you wanna try again ? (Y/N) \n";
	 if (c == 'Y')
	 {
	 	Menu1();
	 }
	 else 
	 	MainMenu();

}

void menu::Menu2()
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

void menu::Menu3()
{
	double latitude, longitude;

	cout << "Please enter the latitude of the position you want to calculate the nearest beach ! \n";
	cout << "Latitude: ";
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please write a valid number ! \n";
		cin >> latitude;
	}

	cout << "Now please enter the longitude ! \n";
	cout << "Longitude: ";
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please write a valid number ! \n";
		cin >> longitude;
	}

	GPS gps(latitude, longitude);

	praiaFluvial *pf;
	pf = gestor.getClosestPraia(gps);

	cout << "The nearest beach is " << pf->getNome();
}

void menu::Menu4()
{
	string county;

	cout << "Please input the county ! \n";
	cout << "County: ";
	getline(cin, county);


}

void menu::Menu5()
{
	string praia;
	cout << "Enter the name of the fluvial beach that you want to get info !\n";
	cout << "Name of the beach: ";
	getline(cin, praia);

	praiaFluvial * temp = gestor.findPraia(praia);

}

unsigned int menu::getWidth()
{
	return width;
}

unsigned int menu::getHeight()
{
	return height;
}


void menu::setWidth(unsigned int width)
{
	this->width = width;
}

void menu::setHeight(unsigned int height)
{
	this->height = height;
}

void menu::setBanner(string filename) {

}


void LoadPraias(std::string filename) {

	ifstream file(filename); //nome concelho latitude longitude bandeiraazul capacidade (tipo1 nome1 latutude1 longitude1 tipo2 nome2 latitude2 longitude2 ...)




}