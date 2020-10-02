/*
 * quicksort.cpp
 *
 *  Created on: 2018. 10. 15.
 *      Author: harry
 */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
/*
int randomRange(int n1, int n2) {
	return (int) (rand() % (n2 - n1 + 1)) + n1;
}
int n;

 int partition(int a[], int first, int mid, int last) {
 int index = randomRange(first, last);
 int pivot = a[index];
 cout << "pivot : " << pivot << endl;
 int pivotpoint = first - 1;
 int i;
 for (i = first; i <= last; i++) {
 if (a[i] < pivot) {
 pivotpoint++;
 if (pivotpoint == index) //pivot 위치가 바뀔 때 pivot이 어느 위치로 바꿨는지 알려줘야함
 index = i;
 cout << "i : " << i << " pivotpoint : " << pivotpoint << endl;
 int temp = a[i];
 a[i] = a[pivotpoint];
 a[pivotpoint] = temp;
 }
 }
 int temp2 = a[index];
 a[index] = a[pivotpoint + 1];
 a[pivotpoint + 1] = temp2;
 for (int i = first; i <= last; i++)
 cout << a[i] << " ";
 cout << endl;
 return pivotpoint + 1;
 }

int partition(int a[], int first, int last) {
	int index = randomRange(first, last);
	int pivot = a[index];
	int left = first;
	int right = last;
	while (left <= right) {
		while (left <= last && a[left] <= pivot)
			left++;
		while (right >= first && a[right] > pivot)
			right--;
		if (left <= right) {
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			if (index == right)
				index = left;
			left++;right--;
		}
	}
	int temp2 = a[right];
	a[right] = a[index];
	a[index] = temp2;
	return right;

}
void quicksort(int a[], int first, int last) {
	if (first < last) {
		int pivotpoint = partition(a, first, last);
		quicksort(a, first, pivotpoint - 1);
		quicksort(a, pivotpoint + 1, last);
	}
}
int main() {
	srand(GetTickCount());
	n = randomRange(4, 7);
	int arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = randomRange(1, 10);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}*/



