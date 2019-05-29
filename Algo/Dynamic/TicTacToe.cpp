/*
 * TicTacToe.cpp
 *
 *  Created on: 2019. 1. 16.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20000;
char board[3][3];
int cache[MAX];

bool IsFinished(char board[3][3]){
	bool check1 = true;
	for(int i =0; i<3; i++){
		char temp = board[i][0];
		for(int j =0; j<3; j++){
			if(temp != board[i][j])
				check1 = false;
		}
	}
	bool check2 = true;
	char temp = board[0][0];
	int i=0, j=0;
	while(i < 3 && j <3){
		if(temp != board[i][j])
			check2 = false;
		i++; j++;
	}
	bool check3 = true;
	temp = board[2][0];
	i = 2; j = 0;
	while(i>=0 && j < 3){
		if(temp != board[i][j])
			check3 = false;
		i--; j++;
	}
	bool check4 = true;
	for(j=0; j <3; j++){
		temp = board[0][j];
		for(i = 0; i < 3; i++){
			if(temp != board[i][j])
				check4 = false;
		}
	}
	return check1 || check2 || check3 || check4;
}

int memo(char board[3][3]){
	int ret = 0;
	for(int i =0; i<3; i++){
		for(int j =0; j<3; j++){
			ret *= 3;
			if(board[i][j] == 'O')
				ret += 1;
			else if(board[i][j] == 'X')
				ret +=2;
		}
	}
	return ret;
}

int canwin(char turn) {
	if (IsFinished(board))
		return -1;
	int& ret = cache[memo(board)];
	if (ret != -2)
		return ret;
	int minvalue = 2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if(board[i][j] == '.'){
				board[i][j] = turn;
				minvalue = min(minvalue, canwin('O'+'X' -turn));
				board[i][j] = '.';
			}
		}
	}
	if(minvalue == 2 || minvalue == 0) return ret = 0;
	return ret = -minvalue;
}

int main(){
	for(int i =0; i<3; i++){
		for(int j =0; j<3; j++){
			board[i][j] = '.';
		}
	}
	for(int i =0; i<MAX; i++){
		for(int j =0; j<MAX; j++){
			cache[i][j] = -2;
		}
	}

}
*/


