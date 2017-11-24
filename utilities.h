#ifndef __UTILITIES_INCLUDED__
#define __UTILITIES_INCLUDED__

#include <string>

namespace utilities{

	template <class T>

	void swap(T&, T&);
	void trimString(std::string &input);
	int intSize(int);
	bool isNumeric(std::string input);
	
};


#endif