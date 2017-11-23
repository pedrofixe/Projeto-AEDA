#include "menu.h"
#include "ui_utilities.h"

using namespace std;

menu::menu()
{}

menu::menu(unsigned int width, unsigned int height) : width(width), height(height)
{}

void menu::PreMenu()
{

	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	string tempstr;

	while(1)
	{
		cout <<"\n Insert input filename (leave empty for default: \"inputfile\"): ";

		getline(cin, tempstr);
		if (tempstr == "")	tempstr = "inputfile";

		if (gestor.LoadPraias(tempstr))
			break;
		else
			cout << "File doesn't exist!";

	}
	cout << "\n";

	while (1)
	{
		cout <<"\n Insert banner filename (leave empty for default: \"bannerfile\"): ";

		getline(cin, tempstr);
		if (tempstr == "")	tempstr = "bannerfile";

		if (LoadBanner(tempstr))
			break;
		else
			cout << "File doesn't exist!";
	}

	cout << "\n\n   All files have been loaded with success. Press enter to continue...";
	getchar();
}


void menu::MainMenu()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();

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
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

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
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

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
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

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
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();

	string county;

	cout << "Please input the county ! \n";
	cout << "County: ";
	getline(cin, county);


}

void menu::Menu5()
{
	ui_utilities::SetWindow(width, height);
	ui_utilities::ClearScreen();
	PrintBanner();
	
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

bool menu::LoadBanner(string filename) {

	ifstream file(filename);

	if (!file.is_open())
		return false;

	string tempstr;

	while(getline(file, tempstr, '\n'))
	{
		banner.push_back(tempstr);
	}

	return true;
}

void menu::PrintBanner() {

	for (int i = 0; i < banner.size(); ++i)
	{
		cout << banner[i];
	}

	cout << '\n';
}