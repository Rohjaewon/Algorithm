/*
 * LIS.cpp
 *
 *  Created on: 2018. 11. 2.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int n =0;
int LIS(vector<int> a){
	int Length[n] = {0};
	int smallest = -1; int largest = -1;
	int maxlength = 0;
	for(int i =0; i<n; i++){
		cout << "a : " << a[i];
		if(i==0){
			Length[i] = 1;
			largest = i;
			smallest = i;
			cout << endl;
		}
		else if(a[i] > a[largest]){
			if (Length[largest] > Length[smallest]){
				Length[i] = Length[largest] + 1;
				cout << " largest : " << largest;
			}
			else{
				Length[i] = Length[smallest] + 1;
				cout << " smallest : " << smallest;
			}
			largest = i;
			cout << " length : " << Length[i]<< endl;
		}
		else{//a[i] <= largest
			if(a[i] < a[smallest]){
				Length[i] = 1;
			}
			else{ //a[i] > a[smallest]
				Length[i] = Length[smallest] +1;
			}
			cout << " smallest : " << smallest;
			smallest = i;
			cout  << " length : " << Length[i] << endl;
		}
	}
	for(int i =0; i<n; i++){
		if(maxlength < Length[i])
			maxlength = Length[i];
	}cout << "Length : ";
	for(int i =0; i<n; i++)
		cout << Length[i] << " ";
	cout << endl;
	return maxlength;
}
int main(){
	srand((int)time(0));
	while(1){
	cin >> n;
	vector<int> arr(n);
	for(int i =0; i<n; i++)
		arr[i]= rand()%10+1;
		//cin >> arr[i];

	for(int i =0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << LIS(arr) << endl;
	}
}

