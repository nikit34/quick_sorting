#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXARR 10

void quicksort(int arr[], int low, int high);

int main(void) {
	int array[MAXARR] = { 0 };
	int i = 0;

	for (i; i < MAXARR; i++)
		array[i] = rand() % 100 - 10;

	for (i=0;i<MAXARR;i++)
		cout << array[i] << ' ';
	cout << endl;

	quicksort(array, 0, (MAXARR - 1));

	for (i = 0; i < MAXARR; i++)
		cout << array[i] << ' ';
	cout << endl;


	return 0;
}

void quicksort(int arr[], int low, int high) {
	int low_c = low;
	int high_c = high;
	int tmp = 0;

	int z = arr[(low + high) / 2];

	do {
		while (z > arr[low_c]) low_c++;
		while (z < arr[high_c]) high_c--;
	
		if (low_c <= high_c) {
			tmp = arr[low_c];
			arr[low_c] = arr[high_c];
			arr[high_c] = tmp;
			low_c++;
			high_c--;
		}
	} while (low_c <= high_c);

	if (low < high_c)
		quicksort(arr, low, high_c);

	if (high < low_c)
		quicksort(arr, high, low_c);
}
