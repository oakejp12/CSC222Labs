/*
 * Driver function for the sorting experiment
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#include <iostream>
#include <string>
#include "Data.h"
#include "Experiment.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
    
    // Read file web2random which contains 235886 word entries
    Data data("web2random");

    // Set the standard deviation for the Gaussian weight function to be
    // small so that the number of trials decays quickly as problem size
    // increases.
    data.setStd(1.0/1024);
 
    Experiment experiment(&data);

    // Add the algortithms to the experiment
    experiment.addAlgorithm(new SelectionSort());
    experiment.addAlgorithm(new MergeSort());
    experiment.addAlgorithm(new QuickSort());
    
    // Run 98 timing experiments w/ list sizes between
    // 2 and 100, 2048 is maximum number of trials to do
    // for each problem size
    experiment.run(5000, 10000, 50, 100);
    experiment.save("Results.txt");
}


