#include "MergeSort.h"


void MergeSort::sort(string* data, int n) {
	mergesort(data, 0, n-1);
}

void MergeSort::mergesort(string* data, int low, int high) {
	if (low < high) {
		int middle = (low + high) / 2;
		mergesort(data, low, middle);
		mergesort(data, middle+1, high);
		merge(data, low, middle, high);
	}
}

void MergeSort::merge(string* data, int low, int middle, int high) {

	// Create the helper array
	string* helper = new string[(high-low)+1];

	for (int i = low; i <= high; i++)
		helper[i] = data[i];

	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;

	/* Iterate through helper array. Compare the left and right
	 * half, copying back the smaller element from the two halves
	 * into the original array. */
	 while (helperLeft	<= middle && helperRight <= high) {
	 	if (helper[helperLeft] <= helper[helperRight]){
	 		data[current] = helper[helperLeft];
	 		helperLeft++
	 	} else { // If the right element is smaller the left element
	 		data[current] = helper[helperRight];
	 		helperRight++;
	 	}
	 	current++
	 }

	/* Copy the rest of the left side into the target array */
	int remaining = middle - helperLeft;
	for (int i = 0; i <= remaining; i++) {
		data[current + i] = helper[helperLeft + i];
	}

}

