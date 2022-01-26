#include <iostream>

// The rank of an element in a list is the number of all the bigger elements
// and all the elements of the same value on its left;
// For example : a = [4,3,9,3,7], 
// the rank of all the elements in a is [2,0,4,1,3];
template<class T>
void rank(const T a[], int size, int r[]) {
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
void in_placeRearrange(T a[], int size, int r[]) {
	rank(a, size, r);
	for (int i = 0; i < size; i++) {
		while (r[i] != i) {
			int t = r[i];
			std::swap(a[i], a[t]);
			std::swap(r[i], r[t]);
		}
	}

}

template<class T>
void selectionSort(T a[], int n) {
	bool sorted = false;
	for (int size = n; !sorted && (size > 1); size--) {
		int indexOfMax = 0;
		sorted = true;
		// get the index of the largest element
		for (int i = 1; i < size; i++) {
			if (a[indexOfMax] < a[i]) {
				indexOfMax = i;
			}
			// if the array is already sorted, then end the sort
			else {
				sorted = false;
			}
		}
		// move the largest element to the end of the array
		std::swap(a[indexOfMax], a[size - 1]);
	}
}

template<class T>
void bubbleSort(T a[], int size) {
	bool swapped = true; // True as initialization.
	for (int i = 0; swapped && (i > size - 1); i++) {
		// Till now the there has been no swapped element.
		swapped = false;
		// Move the largest element in a[i:size-1] to the end of the array.
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				std::swap(a[j], a[j + 1]);
				// Two elements are swapped shows that the array is unsorted.
				swapped = true;
			}
		}
	}
}

template<class T>
void insertionSort(T a[], int size) {
	for (int i = 1; i < size; i++) {
		T t = a[i];
		int j;
		// Insert a[i] into a[0:i-1].
		// Keep moving a[j] to a[j+1] until t >= a[j],
		// and then assign t (the value of origin a[i]) to a[j+1].
		for (j = i - 1; j >= 0 && t < a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
}