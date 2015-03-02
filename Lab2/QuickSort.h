/*
 * Definition of class QuickSort
 *
 * author: Johan P. Oakes
 * date:   3/1/2015
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H	

#include "SortAlgorithm.h"

// QuickSort implements the SortAlgorithm interface
class QuickSort : public SortAlgorithm {
public:
    void sort(string*, int);	// implementation of sort function
private:
	void quickSort(string*, int, int);
	int partition(string*, int, int);
    void swap(string&, string&); // it's own private function, not part of
				 // the interface
};

#endif