#include <iostream>
template<class T>
void selectionSort(T a[], int n) {
	for (int size = n; size > 1; size--) {
		int indexOfMax = 0;
		// get the index of the largest element
		for (int i = 1; i < size; i++)
			if (a[indexOfMax] < a[i])
				indexOfMax = i;
		std::swap(a[indexOfMax], a[size - 1]);
	}
}

template<class T>
void bubbleSort(T a[], int n) {
	for (int i = n; i > 1; i--)
		for (int j = 0; j < i - 1; j++)
			if (a[j] > a[j + 1])
				std::swap(a[j], a[j + 1]);
}