/*
 * Definition of class Data
 * Data encapsulates all methods for reading and processing words 
 * from a given text data file. 
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Data {
private:
    string dataFile;
    double std;		// Standard deviation for Gaussian weight function
    vector<string> original; // Original copy of the input data
    
public:
    vector<string> array;	// Data that can be modified
    Data(string);		// Reads input file into array
    void refresh();		// Restores array to original values
    double reduceFactor(int);   // Gaussian weight function value 
    void setStd(double);	// Set the STD of the Gaussian function
    void print(int, int);	// Print part of the array
    void shuffle();		// Shuffle the array
    void writeToFile(string filename); // Write the array to filename
};

#endif
