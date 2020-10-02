/*
 * picnic.cpp
 *
 *  Created on: 2019. 1. 12.
 *      Author: harry
 */
#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
void make_pair(vector<vector<int> > f_pair, int num, vector<bool> picked) {
	int start = -1;
	for (int i = 0; i < num; i++) {
		if (!picked[i]) {
			start = i;
			break;
		}
	}
	if (start == -1){
		cnt++;
		cout << cnt << endl;
	}
	else {
		vector<int>::iterator iter = f_pair[start].begin();
		picked[start] = true;
		while (iter != f_pair[start].end()) {
			if (!picked[*iter]) {
				picked[*iter] = true;
				cout << start << "," << *iter << " ";
				make_pair(f_pair, num, picked);
				picked[*iter] = false;
			}
			iter++;
		}
	}
}

int main(){
	int num, pair; cin >> num >> pair;
	vector<vector<int> > f_pair(num);
	for(int i =0; i< pair; i++){
		int p1, p2; cin >> p1 >> p2;
		if(p1 < p2)
			f_pair[p1].push_back(p2);
		else
			f_pair[p2].push_back(p1);
	}
	vector<bool> picked(num , 0);
	make_pair(f_pair, num, picked);
	cout << cnt;
}


