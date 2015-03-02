/*
 * Implementation of class Data.
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#include "Data.h"
#include <fstream> 
#include <math.h>
#include <algorithm>
#include <assert.h>

using namespace std;

// Constructor 
// ------------------------------------------------------------------------
Data::Data(string filename) {
    std = 1.0/8;	// Default standard deviation for Gaussian function

    // Read text data from filename, one line at the time
    ifstream infile(filename);
    string line;    
    if (!infile.is_open()) {
        cout << "Error opening file " << filename << endl;
        assert(0);
    }
    cout << "Reading data from file...\n";
    while ( getline(infile, line) ) {
        array.push_back(line);		// Save into array
        original.push_back(line);	// and also in original
    }
    cout << "\tRead " << array.size() << " lines\n";
    infile.close();
}

// setStd(double s): s must not be 0
// ------------------------------------------------------------------------
void Data::setStd(double s) {
   std = s;
}

// refresh(): reset array to original values. Assignment is overloaded 
//   with vector<string> so data is actually copied.
// ------------------------------------------------------------------------
void Data::refresh() {
    array = original;
}

// reduceFactor(int size): calculate percentage between 0 and 1 for given
//   value of size. The larger size is, the closer percentage is to 0. The 
//   smaller size is, the closer percentage is to 1. 
// ------------------------------------------------------------------------
double Data::reduceFactor(int size) {
   double f = 5 * (double)size / array.size();  // value between 0 and 5
   return exp(-(f*f) / std);  // Value of Gaussian weight function
}

// print(int start, int size): print array[start] to array[start+size] to
//   the screen.
// ------------------------------------------------------------------------
void Data::print(int start, int size) {
   cout << endl;
   for (int i = start; i < start+size; i++) {
      cout << array[i] << endl;
   }
}

// shuffle(): shuffle data in the array. 
// ------------------------------------------------------------------------
void Data::shuffle() {
   random_shuffle( array.begin(), array.end() );
}

// writeToFile(string filename): write array to given filename
// ------------------------------------------------------------------------
void Data::writeToFile(string filename) {
    ofstream outfile(filename); 

    if ( !outfile.is_open() ) {
               cout << "Error opening file " << filename << endl;
        assert(0);
    }

    cout << "Writing data to file...\n";
    for (int i = 0; i < array.size(); i++) {
        outfile << array[i] << endl;
    }
    outfile.close();
}
