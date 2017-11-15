#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class menu {

	unsigned int widht;
	unsigned int height;
	std::vector<std::string> banner;

public:
	menu();
	menu(unsigned int widht, unsigned int height);

	void MainMenu();
	void Menu1();
	void Menu2();

	unsigned int getWidth();
	unsigned int getHeight();

	void setWidth(unsigned int width);
	void setHeight(unsigned int height);
	
	void LoadBanner(std::string filename);
	void LoadPraias(std::string filename);

};


#endif