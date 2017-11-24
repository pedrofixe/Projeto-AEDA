#ifndef __UI_UTILITIES_INCLUDED__
#define __UI_UTILITIES_INCLUDED__

#include <iostream>
#include <string>

using namespace std;

class ui_utilities{

	unsigned int width = 100;
	unsigned int height = 35;

public:
	
	static void ClearScreen();
	static bool SetWindow(const int&, const int&);

};


#endif