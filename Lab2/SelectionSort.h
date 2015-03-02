/*
 * Definition of class SelectionSort
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortAlgorithm.h"

// SelectionSort implements the SortAlgorithm interface
class SelectionSort : public SortAlgorithm {
public:
    void sort(string*, int);	// implementation of sort function
private:
    void swap(string&, string&); // it's own private function, not part of
				 // the interface
};

#endif
