/*
 * Definition of Interface SortAlgorithm
 *   All sorting algorithms must inherit from this class and implement
 *   sort() exactly as specified below.
 *
 * author: V. P. Pauca
 * date:   2/24/2015
 */

#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <string>

using namespace std;

// SortAlgorithm is an interface (or abstract class).
// Any algorithm inheriting from this class must implement function sort() 
class SortAlgorithm {
public:
    // Define sort() as a pure virtual function. That is, it must be 
    // implemented by a subclass.
    virtual void sort(string*, int) = 0; 
};

#endif
