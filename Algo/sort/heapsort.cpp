/*
 * heapsort.cpp
 *
 *  Created on: 2018. 10. 15.
 *      Author: harry
 */

#include <iostream>
#include <time.h>
using namespace std;

int n;
void rebuild(int a[], int root, int size){
	//int L = a[root];
	int current = root;
	while(2*current+1< size){
		int leftchild = 2*current+1;
		int rightchild = leftchild+1;
		int largerchild;
		if(rightchild < size && a[rightchild] > a[leftchild]){//오른쪽 자식이 왼쪽 자식보다 클 때
			largerchild = rightchild;
		}
		else{
			largerchild = leftchild;
		}
		if (a[current] < a[largerchild]) {
			int temp = a[current];
			a[current] = a[largerchild];
			a[largerchild] = temp;
			current = largerchild;
		}
		else break;
	}//while
}

void maxheap(int a[]){
	for(int i = (n/2)-1; i >= 0; i--)
		rebuild(a, i, n);
}

int heap_size;

void heapsort(int a[]){
	for(int i = n-1; i>0; i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heap_size--;
		rebuild(a, 0, heap_size);
	}
}

int main(){
	srand((int)time(0));
	n = 5;
	heap_size=n;
	int arr[n];
	for(int i =0; i<n; i++)
		arr[i] = rand() % 10;
	for(int i =0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	maxheap(arr);
	cout << "After max heap : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	heapsort(arr);
	cout << "After heapsort : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

//minheap
/* 
#include <iostream>
#include <time.h>
using namespace std;

int n;
void rebuild(int a[], int root, int size){
	//int L = a[root];
	int current = root;
	while(2*current+1< size){
		int leftchild = 2*current+1;
		int rightchild = leftchild+1;
		int lowerchild;
		if(rightchild < size && a[rightchild] < a[leftchild]){//오른쪽 자식이 왼쪽 자식보다 클 때
			lowerchild = rightchild;
		}
		else{
			lowerchild = leftchild;
		}
		if (a[current] > a[lowerchild]) {
			int temp = a[current];
			a[current] = a[lowerchild];
			a[lowerchild] = temp;
			current = lowerchild;
		}
		else break;
	}//while
}

void minheap(int a[]){
	for(int i = (n/2)-1; i >= 0; i--)
		rebuild(a, i, n);
}

int heap_size;

void heapsort(int a[]){
	for(int i = n-1; i>0; i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heap_size--;
		rebuild(a, 0, heap_size);
	}
}

int main(){
	srand((int)time(0));
	n = 5;
	heap_size=n;
	int arr[n];
	for(int i =0; i<n; i++)
		arr[i] = rand() % 10;
	for(int i =0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	minheap(arr);
	cout << "After min heap : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
*/





