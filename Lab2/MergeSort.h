/*
 *	Definition of class MergeSort
 *
 *	author: J. P. Oakes
 *	date: 3/1/2015
 *
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortAlgorithm.h"

// MergeSort implements the SortAlgorithm interface
class MergeSort : public SortAlgorithm {

public:
	void sort(string*, int); // Implementation of sort function
private:
	void mergesort(string*, int, int);
	void merge(string*, int, int, int);
};


#endif MERGESORT_H
