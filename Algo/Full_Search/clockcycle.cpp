/*
 * clockcycle.cpp
 *
 *  Created on: 2019. 1. 11.
 *      Author: harry
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 const int INF = 987654321;

bool check(vector<int> clock){
	for(int i =0; i<16; i++){
		if(clock[i] != 0)
			return false;
	}
	return true;
}

void push(vector<int> &clock, vector<vector<int> > t_switch, int swtch){
	vector<int>::iterator iter = t_switch[swtch].begin();
	while(iter != t_switch[swtch].end()){
		clock[*iter] += 3;
		clock[*iter] %= 12;
		iter++;
	}
}

int cycle(vector<int> &clock, vector<vector<int> > t_switch,int swtch) {
	if(swtch == 10){
		return check(clock)?0:INF;
	}
	int answer = INF;
	for(int cnt = 0; cnt < 4; cnt++){
		answer = min(answer, cnt+cycle(clock, t_switch, swtch+1));
		push(clock, t_switch, swtch);
	}
	return answer;
}

int main(){
	vector<int> clock(16, 0);
	for(int i =0; i< 16; i++){
		int time; cin >> time;
		clock[i] = time%12;
	}
	vector<vector<int> > t_switch(10);
	int order = 1;
	for(int i =0; i<10; i++){
		switch(order){
		case 1:
			for(int k = 0; k < 3; k++)
				t_switch[i].push_back(k);
			break;
		case 2:
			t_switch[i].push_back(3); t_switch[i].push_back(7);
			t_switch[i].push_back(9); t_switch[i].push_back(11);
			break;
		case 3:
			t_switch[i].push_back(4); t_switch[i].push_back(10);
			t_switch[i].push_back(14); t_switch[i].push_back(15);
			break;
		case 4:
			t_switch[i].push_back(0); t_switch[i].push_back(4);
			t_switch[i].push_back(5); t_switch[i].push_back(6);
			t_switch[i].push_back(7);
			break;
		case 5:
			t_switch[i].push_back(6); t_switch[i].push_back(7);
			t_switch[i].push_back(8); t_switch[i].push_back(10);
			t_switch[i].push_back(12);
			break;
		case 6:
			t_switch[i].push_back(0); t_switch[i].push_back(2);
			t_switch[i].push_back(14); t_switch[i].push_back(15);
			break;
		case 7:
			t_switch[i].push_back(3); t_switch[i].push_back(14);
			t_switch[i].push_back(15);
			break;
		case 8:
			t_switch[i].push_back(4); t_switch[i].push_back(5);
			t_switch[i].push_back(14); t_switch[i].push_back(7);
			t_switch[i].push_back(15);
			break;
		case 9:
			t_switch[i].push_back(1); t_switch[i].push_back(2);
			t_switch[i].push_back(3); t_switch[i].push_back(4);
			t_switch[i].push_back(5);
			break;
		case 10:
			t_switch[i].push_back(3); t_switch[i].push_back(4);
			t_switch[i].push_back(5); t_switch[i].push_back(9);
			t_switch[i].push_back(13);
			break;
		}
		order++;
	}
	cout << cycle(clock, t_switch, 0);
}

