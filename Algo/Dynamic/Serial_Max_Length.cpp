/*
 * Serial_Max_Length.cpp
 *
 *  Created on: 2018. 11. 12.
 *      Author: harry
 */
#include <iostream>
#include <algorithm>
using namespace std;

int find(int* board, int* length, int n, int i){
	int index = 0, max = 0;
	for(int j = 0; j <i; j++){
		if(board[j] < board[i]){
			if(max < length[j]){
				max = length[j];
				index = j;
			}
		}
	}
	return index;
}

int LIS(int* board, int* length, int n){
	int* route = new int[n];
	for(int i =0; i<n; i++)
		route[i] = -1;
	for(int i =0; i<n; i++){
		if(i != 0){
			int j = find(board,length, n, i);
			length[i] = length[j] + 1;
			route[i] = j;
		}
	}
	int maxlength = 0, index = 0;
	for(int j = 0; j <n; j++){
		if(maxlength < length[j]){
			maxlength = length[j];
			index = j;
		}
	}
	while(index != -1){
		cout << index << " ";
		index = route[index];
	}cout << endl;
	return maxlength;
}

int main(){
	int n; cin >> n;
	int* board = new int[n];
	int* length = new int[n];
	for(int i =0; i<n; i++){
		cin >> board[i];
		length[i] = 0;
	}
	cout << LIS(board, length, n);
}



