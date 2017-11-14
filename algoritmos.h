#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>


class algoritmos
{
public:
	template <class T>
	int sequentialSearch(const std::vector<T> & v, const T & target) const;
	template <class T>
	void selectionSort(std::vector<T> & v);
	
};



#endif