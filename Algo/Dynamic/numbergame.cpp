/*
 * numbergame.cpp
 *
 *  Created on: 2019. 1. 19.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int EMPTY = -987654321;
vector<vector<int> > cache(MAX, vector<int>(MAX, EMPTY));
vector<int> board;

int canwin(int L, int R){
	if(L>R) return 0;
	int& ret = cache[L][R];
	if(ret != EMPTY) return ret;
//	int left = board[L]-canwin(board, L+1, R);
//	int right = board[R]-canwin(board, L, R-1);
//	cout << L << " , " << R << endl;
//	cout << "left : " << left << " , " << "right : " << right << endl;
	ret = max(board[L]-canwin(L+1, R), board[R]-canwin(L, R-1));
	if(R-L+1 >= 2 ){
//		int ldelete = -canwin(board, L+2, R);
//		cout << L << " , " << R << endl;
//		cout << "ldelete : " << ldelete << endl;
		ret = max(ret, -canwin(L+2, R));
//		int rdelete = -canwin(board, L, R-2);
//		cout << L << " , " << R << endl;
//		cout << "rdelete : " << rdelete << endl;
		ret = max(ret, -canwin(L, R-2));
	}
	return ret;
}

int main(){
	int n; cin >> n;
	for(int i =0; i<n; i++){
		int temp; cin >> temp;
		board.push_back(temp);
	}
	cout << canwin(0, n-1);
	return 0;
}



