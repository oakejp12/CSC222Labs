#include "SelectionSort.h"


void SelectionSort::sort(string* data, int n) {

	int i, j, min;

	/* Advance position through the entire array */
	for (j = 0; j < n-1; j++) {

		/* Assume that min the first element */
		min = j;

		/* Test against elements after j to find the smallest */
		for (i = j + 1; i < n; i++) {

			/* If less, then element is the new minimum */
			if (data[i] < data[min])
				min = i;
		}

		/* Swap the new smallest with current element */
		if ( min != j) {
			swap(data[j], data[min]);
		}
	}   
}

void SelectionSort::swap(string& s1, string& s2) {
    string tmp;
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}
