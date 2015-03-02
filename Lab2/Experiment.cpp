/*
 * Implementation of class Experiment
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#include <sys/time.h>
#include <fstream>
#include <assert.h>
#include "Experiment.h"

// Constructor 
// ------------------------------------------------------------------------
Experiment::Experiment(Data* d) {
    assert( d != 0 );
    data = d;		// Save Data object
}

// addAlgorithm(alg): Add SortAlgorithm alg to the experiment
// ------------------------------------------------------------------------
void Experiment::addAlgorithm(SortAlgorithm* alg) {
    assert( alg != 0 );
    algorithm.push_back(alg); 	// Save ptr into vector
}

// get_timestamp(): returns current time stamp in seconds
// ------------------------------------------------------------------------
timestamp_t Experiment::get_timestamp () {
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

// Experiment(low, high, n, maxTrials): runs a timing experiment for all 
// the algorithms added to the experiment.
// Preconditions:
//   low: smallest size of array to sort
//   high: approximate largest size of array to sort
//   n: number of sorting problems to perform between low and high
//   trials: maximum number of repetitions for first problem size
// Postcondition:
//   - For n problems of increasing size between low and high, the function
//       computes the average time in seconds taken to sort the corresponding
//       array over a number of trials
//   - The timing results are stored in the 2D array timings[alg][prob. size]
// ------------------------------------------------------------------------
void Experiment::run(int low, int high, int n, int maxTrials) {
    assert( n > 1 );  
    int interval = (high - low) / (n-1);// fixed step size between problems
    int size = low;			// initial problem size
    timestamp_t startTime;		// start time
    timestamp_t endTime;		// end time
    int trials = maxTrials;		// number of trials for initial size
    
    cout << "Running a timing experiment with parameters:" << endl;
    cout << "==========================================================\n";
    cout << "Number of algorithms to test: " << algorithm.size() << endl;
    cout << "number of problems to run per algorithm: " << n << endl;
    cout << "\tsmallest problem size: " << low << endl;
    cout << "\tlargest problem size: " << high << endl;
    cout << "maximum trials per problem size: " << maxTrials << endl << endl;
    cout << "==========================================================\n";

    // Allocate storage for the timing output and problem size
    timings = new double* [algorithm.size()];
    for (int i = 0; i < algorithm.size(); i++) {
        timings[i] = new double[n];
    }
    probSize = new int[n];
    num = n;  // save also the number of time data points
    
    // For each algorithm in this experiment...
    for (int k = 0; k < algorithm.size(); k++) {
        cout << "Running algorithm " << k+1 << " out of " << algorithm.size() 
		<< "...\n";
        size = low;   // Reset the initial problem size
        // For each problem size...
        for (int i = 0; i < n; i++) {
	    printf("\tproblem size: %6d  trials: %4d", size, trials);
            // refresh the data to its original unsorted order
            data->refresh();
            
            // Time the sorting algorithm "trial" times and then calculate
            // the average. 
   	    trials = 1 + (int)(maxTrials * data->reduceFactor(size));
            startTime = get_timestamp();	  // start the timer
            for (int j = 0; j < trials; j++) {
                (algorithm[k])->sort(&(data->array[j*size]), size);
#ifdef PRINT
                data->print(j*size, size);
#endif
            }
            endTime = get_timestamp();	  // stop the timer
            // Average number of elapsed seconds over the trials
            timings[k][i] = (endTime - startTime) / 1000000.0L / trials;
            probSize[i] = size;		  // save the problem size
            size += interval;		  // problem size for next iteration
	    printf(" avg. time (s): %4.8f\n", timings[k][i]);
        }
    }
    
}

// save(filename): save all timing results to filename
// file format is:
// problemSize  timing-Alg0  timing-Alg1 ...
// ------------------------------------------------------------------------
void Experiment::save(string filename) {
    ofstream outfile;
    outfile.open(filename);
    if ( !outfile.is_open() ) {
        cout << "Error opening file " << filename << endl;
        assert(0);        
    }

    cout << "Writing results to file " << filename << endl;
    for (int i = 0; i < num; i++) {
        outfile << probSize[i];
        for (int k = 0; k < algorithm.size(); k++) {
            outfile << " " << timings[k][i];
        }
        outfile << endl;
    }
    outfile.close();
}
