/*
 * BLOCKGAME.cpp
 *
 *  Created on: 2019. 1. 19.
 *      Author: harry
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool> > board(5, vector<bool>(5));
int coverType[2][2][2] = {
		{{0,0}, {0,1}},
		{{0,0}, {1,0}}
};
int coverType2[4][3][2] = {
		{{0,0}, {0,1}, {1,0}},
		{{0,0}, {0,1}, {1,1}},
		{{0,0}, {1,0}, {1,1}},
		{{0,0}, {1,0}, {1,-1}}
};

bool range(int i, int j){
	//cout << i <<"," << j << endl;
	if(i>=5 || i <0 || j >= 5 || j<0)
		return false;
	else{
		if(board[i][j] == true)
			return false;
		else return true;
	}
}

void cover(vector<vector<bool> >& board, int i, int j, int type){
	if(type < 2){
		for(int k =0; k<2; k++){
			//cout << "cover : " <<  i+coverType2[type][k][0] << "," << j+coverType2[type][k][1] << endl;
			board[i+coverType[type][k][0]][j+coverType[type][k][1]] = 1;
		}
	}
	else{
		for(int k =0; k<3; k++){
			//cout << "cover : " <<i+coverType2[type][k][0] << "," << j+coverType2[type][k][1] << endl;
				board[i+coverType2[type][k][0]][j+coverType2[type][k][1]] = 1;
		}
	}
}

void uncover(vector<vector<bool> >& board, int i, int j, int type){
	if(type < 2){
		for(int k =0; k<2; k++){
			//cout << "uncover : " << i+coverType2[type][k][0] << "," << j+coverType2[type][k][1] << endl;
				board[i+coverType[type][k][0]][j+coverType[type][k][1]] = 0;
		}
	}
	else{
		for(int k =0; k<3; k++){
			//cout << "uncover : " << i+coverType2[type][k][0] << "," << j+coverType2[type][k][1] << endl;
				board[i+coverType2[type][k][0]][j+coverType2[type][k][1]] = 0;
		}
	}
}



int canwin(int turn){
	cout << "turn : " << turn << endl;
	for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << endl;

	int index =-1, index2 = -1;
	for(int i =0; i< 5; i++){
		for(int j =0; j<5; j++){
			if(board[i][j] == 0){
				index = i; index2 = j;
				break;
			}//if
		}//for
		if(index != -1)
			break;
	}//for
	if(index == -1){
		cout << (turn+1)%2 << endl;
		return (turn+1)%2;
	}
	int ret = -1;
	bool check = false;
	for (int type = 0; type < 6; type++) {
		//cout <<"start : " << index << ", " << index2 << endl;

		bool cancover = true;
		if (type < 2) {
			for (int k = 0; k < 2; k++) {
				if (!range(index + coverType[type][k][0], index2 + coverType[type][k][1])) {
					cancover = false;
				}//if
				//cout << "k : " << k << endl;
			}//for
		} else {
			for (int k = 0; k < 3; k++) {
				if (!range(index + coverType2[type][k][0], index2 + coverType2[type][k][1])) {
					cancover = false;
				}//if
				//cout << "k2 : " << k << endl;
			}//for
		}//else
		if (cancover) {
			cout << "turn : " << turn << endl;
			cover(board, index, index2, type);
			for (int i = 0; i < 5; i++) {
									for (int j = 0; j < 5; j++) {
										cout << board[i][j];
									}
									cout << endl;
								}
								cout << endl;
			ret *= canwin((1 + turn) % 2);
			uncover(board, index, index2, type);
			for (int i = 0; i < 5; i++) {
						for (int j = 0; j < 5; j++) {
							cout << board[i][j];
						}
						cout << endl;
					}
					cout << endl;
			check = true;
		}
	} //for
	if(!check){
		cout << (turn+1)%2 << endl;
		return (turn+1)%2;
	}
	return ret;
}

int main(){
	for(int i=0; i<5; i++){
		for(int j =0; j<5; j++){
			bool temp; cin >> temp;
			board[i][j] = temp;
		}
	}


	int turn = 0;
	int result = canwin(turn);
	if(result == 0)
		cout << "WINNING" << endl;
	else cout << "LOSING" << endl;

}



