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