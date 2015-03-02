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

	int helperLeft = low;
	int helperRight = middle + 1;
	int current = 0;

	/* Take care of case of two-element array */
	if ((low - high) == 1) {
		if (data[high] < data[low]) {
			swap(data[high], data[low]);
		}
		return;
	}

	/* Iterate through helper array. Compare the left and right
	 * half, copying back the larger element from the two halves
	 * into the original array. */
	 while (helperLeft	<= middle && helperRight <= high) {
	 	if (data[helperRight].compare(data[helperLeft]) < 0){
	 		helper[current] = data[helperRight];
	 		helperRight++;
	 	} else { // If the left element is smaller the right element
	 		helper[current] = data[helperLeft];
	 		helperLeft++;
	 	}
	 	current++;
	 }

	/* Copy the rest of the right side into the target array */
	 for (; current <= high && helperLeft <= middle; current++,helperLeft++)
	 	helper[current] = data[helperLeft];

	 for (; current <= high && helperRight <= high; current++, helperRight++)
	 	helper[current] = data[helperRight];

	 /* Shift elements into data[] */
	 for (current = 0, helperLeft = low; current < ((high - low) + 1) && low <= high; current++,helperLeft++)
	 	swap(data[helperLeft], helper[current]);
	 

}

void MergeSort::swap(string& s1, string& s2) {
    string tmp;
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}
