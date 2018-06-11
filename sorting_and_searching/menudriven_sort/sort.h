#ifndef SORT_H
#define SORT_H

	void selectionSort(int *array, int size);
	void bubbleSort(int *array, int size);
	void insertionSort(int *array, int size);
	void partition(int array[], int result[], int min, int max);
	void merge(int array[], int result[], int min, int mid, int max);
	void quicksort(int *array, int lb, int ub);
#endif
