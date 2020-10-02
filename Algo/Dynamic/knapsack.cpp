/*
 * knapsack.cpp
 *
 *  Created on: 2019. 1. 13.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int stuff, volume;
vector<vector<int> > cache(102, vector<int>(1002, -1));

typedef struct info{
	string name;
	int vol;
	int p;//이익
}info;
vector<info> lug;

int knapsack(int start, int volume) {
	int ret = 0;
	if(volume > 0 && start < stuff){
		int temp1 = knapsack(start+1, volume-lug[start].vol)+lug[start].p, temp2 = knapsack(start+1, volume);
		//cout << temp1 << "," << temp2 << endl;

		return ret = max(temp1, temp2);
	}
	else return 0; // volume <= 0 || start > stuff
}
int knapsack(int start, int volume) {
	int& ret = cache[start][volume];
	if(start == stuff)
		return 0;
	if(ret != -1) return ret;
	ret = 0;
	ret = knapsack(start+1, volume);
	if(volume - lug[start].vol >= 0){
		ret = max(ret, knapsack(start+1, volume-lug[start].vol)+lug[start].p);
	}
	return ret;
}

void get(int start, int volume, vector<string>& answer){
	if(start == stuff) return;
	if(knapsack(start+1, volume) == knapsack(start, volume))
			get(start+1, volume, answer);
	else{
		answer.push_back(lug[start].name);
		get(start+1, volume-lug[start].vol, answer);
	}

}

int main(){
	cin >> stuff >> volume;
	vector<string> answer;
	for(int i =0; i< stuff; i++){
		info temp; cin >> temp.name >> temp.vol >> temp.p;
		lug.push_back(temp);
	}
	get(0, volume, answer);
	int p = knapsack(0, volume);
	cout << p << " " << answer.size() << endl;
	vector<string>::iterator iter = answer.begin();
	while(iter != answer.end()){
		cout << *iter << " ";
		iter++;
	}
	return 0;
}



