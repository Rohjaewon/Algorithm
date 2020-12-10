#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<int> arr;

void swap(int left, int right) {
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void quicksort(int lo, int hi) {
	if (lo >= hi) return;
	int pivot = arr[lo];
	int mid = (lo+hi)/2;
	int left = lo+1;
	int right = hi;
	while (left <= right) {
		while (left <= hi && arr[left] < pivot) left++;
		while (right > lo && arr[right] > pivot) right--;
		if (left == right) {
			right--; left++;
		}
		if (left <= right) swap(left, right);
	}
	swap(lo, right);
	quicksort(lo, right-1);
	quicksort(right+1, hi);
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = dis(gen);
		arr.push_back(temp);
		cout << temp << " ";
	} cout << endl;
	quicksort(0, n-1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
