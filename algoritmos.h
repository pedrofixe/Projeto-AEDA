#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>

namespace algoritmos {

	template <class T>
	static int sequentialSearch(const std::vector<T> & v, T target);
	template <class T>
	static int sequentialSearch(const std::vector<T> & v, T target, bool f(T a, T b));
	template <class T>
	static void selectionSort(std::vector<T> & v);
	template<class T>
	static void selectionSort(std::vector<T> & v, bool f(T a, T b));

}


#endif