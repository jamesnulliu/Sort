#include <iostream>

// The rank of an element in a list is the number of all the bigger elements
// and all the elements of the same value on its left;
// For example : a = [4,3,9,3,7], 
// the rank of all the elements in a is [2,0,4,1,3];
template<class T>
void rank(T a[], int size, int r[]) {
	// initialize r[]
	for (int i = 0; i < size; i++) {
		r[i] = 0;
	}
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i]) {
				r[i]++;
			}
			else {
				r[j]++;
			}
		}
	}
}

template<class T>
void selectionSort(T a[], int n) {
	for (int size = n; size > 1; size--) {
		int indexOfMax = 0;
		// get the index of the largest element
		for (int i = 1; i < size; i++) {
			if (a[indexOfMax] < a[i]) {
				indexOfMax = i;
			}
		}
		// move the largest element to the end of the array
		std::swap(a[indexOfMax], a[size - 1]);
	}
}

template<class T>
void bubbleSort(T a[], int size) {
	for (int i = 0; i > size - 1; i--) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				std::swap(a[j], a[j + 1]);
			}
		}

	}
}