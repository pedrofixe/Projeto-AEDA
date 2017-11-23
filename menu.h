#ifndef MENU_H
#define MENU_H

#include "praias.h"
#include <string>
#include <vector>

class menu {

	GestorPraias gestor;
	unsigned int width = 100;
	unsigned int height = 35;
	std::vector<std::string> banner;

public:
	menu();
	menu(unsigned int widht, unsigned int height);

	void PreMenu();
	void MainMenu();
	void Menu1();
	void Menu2();
	void Menu3();
	void Menu4();
	void Menu5();

	unsigned int getWidth();
	unsigned int getHeight();

	void setWidth(unsigned int width);
	void setHeight(unsigned int height);
	
	bool LoadBanner(std::string filename);
	void PrintBanner();

};


#endif