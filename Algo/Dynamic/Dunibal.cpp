/*
 * Dunibal.cpp
 *
 *  Created on: 2019. 1. 13.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int village, days, jail;

void Get_P(vector<vector<int> > connect, vector<double>& probability, int num){
	for(int i =0; i<num; i++){
		probability[i] = (double)1/connect[i].size();
	}
}

double path(vector<vector<int> > connect, vector<double> probability, int start, int finish, int current){
	if(current == days){
		if(start == finish){
			return 1;
		}
		else return 0;
	}
	else{
		vector<int>::iterator iter = connect[start].begin(); double answer = 0;
		while(iter != connect[start].end()){
			answer += probability[start]*path(connect, probability, *iter, finish, current+1);
			iter++;
		}
		return answer;
	}
}

void Dunibal(vector<vector<int> > connect,vector<double>& answer, vector<int> P){
	vector<int> cnt(village, 0); vector<double> probability(village, 0);
	Get_P(connect, probability, village);
	for(unsigned int i =0; i<P.size(); i++){
		answer[i] = path(connect, probability, jail, P[i], 0);
	}
}

int main(){
	cin >> village >> days>> jail;
	vector<vector<int> > connect(village);
	for(int i =0; i<village; i++){
		for(int j =0; j<village; j++){
			int temp; cin >> temp;
			if(temp == 1)
				connect[i].push_back(j);
		}
	}
	int num; cin >> num;
	vector<int> P(num, 0);
	for(int i =0; i<num; i++){
		int temp; cin >> temp;
		P[i] = temp;
	}
	vector<double> answer(num, 0);
	Dunibal(connect, answer, P);
	for(int i =0; i< num; i++)
		cout << answer[i] << " ";
	return 0;
}



