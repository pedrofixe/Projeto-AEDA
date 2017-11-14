#include "algoritmos.h"

template<class T>
int algoritmos::sequentialSearch(const std::vector<T> & v, const T & target) const {

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == target)
			return i;
	}

	return -1;
}

template<class T>
void algoritmos::selectionSort(std::vector<T> & v) {

	int smallest = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		smallest = v[i];

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < smallest)
				smallest = v[j];
		}

		std::swap(smallest, v[i]);
	}

}