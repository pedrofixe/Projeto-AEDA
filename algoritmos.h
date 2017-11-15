#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>


template<class T>
int sequentialSearch(std::vector<T> & v, T target) {

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == target)
			return i;
	}

	return -1;
}

template<class T>
int sequentialSearch(std::vector<T> & v, T target, bool (*f)(T, T)) {

	for (int i = 0; i < v.size(); ++i)
	{
		if (f(v[i], target))
			return i;
	}

	return -1;
}

template<class T>
int sequentialSearch(std::vector<T*> & v, T target, bool (*f)(T, T)) {

	for (int i = 0; i < v.size(); ++i)
	{
		if (f(*v[i], target))
			return i;
	}

	return -1;
}


template<class T>
void selectionSort(std::vector<T> & v) {

	T smallest;
	int index;

	for (int i = 0; i < v.size(); ++i)
	{
		smallest = v[i];
		index = i;

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < smallest)
			{
				smallest = v[j];
				index = j;
			}
		}

		std::swap(v[index], v[i]);
	}

}

template<class T>
void selectionSort(std::vector<T> & v, bool (*f)(T a, T b)) {

	T smallest;
	int index;

	for (int i = 0; i < v.size(); ++i)
	{
		smallest = v[i];
		index = i;

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (f(v[j], smallest))
			{
				smallest = v[j];
				index = j;
			}
		}

		std::swap(v[index], v[i]);
	}


}

template<class T>
void selectionSort(std::vector<T*> & v, bool (*f)(T a, T b)) {

	T smallest;
	int index;

	for (int i = 0; i < v.size(); ++i)
	{
		smallest = *v[i];
		index = i;

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (f(*v[j], smallest))
			{
				smallest = *v[j];
				index = j;
			}
		}

		std::swap(*v[index], *v[i]);
	}


}


<<<<<<< HEAD


=======
>>>>>>> 229f7aac023730b9e7d2c4edbe770f95fbb936db
#endif