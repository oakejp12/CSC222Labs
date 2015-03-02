/*
 * Definition of class Experiment
 * Contains pointers to a data object as well as a vector of SortAlgorithms
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "Data.h"
#include "SortAlgorithm.h"
#include <vector>

typedef unsigned long long timestamp_t;

class Experiment {
private:
    Data* data;				// Ptr to Data object
    vector<SortAlgorithm*> algorithm;	// Vector of SortAlgorithms
    double** timings;			// 2D array of timing results
    int* probSize;			// 1D array of problem sizes
    int num;				// Number of problems in the experimen
    timestamp_t get_timestamp ();	// Get timestamp
 
public:
    Experiment( Data* );		// Constructor
    void run(int, int, int, int);	// Run the experiment
    void addAlgorithm(SortAlgorithm*);	// Add an algorithm to the experiment
    void save(string);			// save the timings to a file
};

#endif
