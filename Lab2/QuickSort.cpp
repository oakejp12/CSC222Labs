#include "QuickSort.h"


void QuickSort::sort(string* data, int n) {
	quickSort(data, 0, n-1);
}

void QuickSort::quickSort(string* data, int left, int right) {
	int index = partition(data, left, right);

	if (left < index - 1) 
		quickSort(data, left, index - 1); // Sort left half

	if (index < right)
		quickSort(data, index, right); // Sort right half
} 

int QuickSort::partition(string* data, int left, int right) {

	// Pick the pivot point
	string pivot = data[(left+right)/2];

	while (left <= right) {
		// Find element on the left that should be on the right
		while(data[left] < pivot) left++;

		// Find element on the right that should be on the left
		while(data[right] > pivot) right--;

		if (left <= right) {
			swap(data[left], data[right]);
			left++;
			right--;
		}
	}

	return left;
}


void QuickSort::swap(string& s1, string& s2) {
    string tmp;
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}
