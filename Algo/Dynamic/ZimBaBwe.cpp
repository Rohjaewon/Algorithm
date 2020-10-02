/*
 * ZimBaBwe.cpp
 *
 *  Created on: 2019. 1. 11.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;
const int MOD = 1000000007;
int count = 0;

void C(vector<int> cnt, string str, string num, int m){
	bool check = true;
	for(unsigned int k = 0; k < cnt.size(); k++){
		if(cnt[k] != 0){
			check = false;
			break;
		}
	}
	if(check){
		long long int n1 = _atoi64(str.c_str());
		//cout << n1 <<"," << str << endl;
		//int n2 = atoi(num.c_str());

		if(str < num){
			//cout << str << "," << num << endl;
			if(n1 % m == 0){
				//cout << n1 << endl;
				count++;
				count %= MOD;
			}
		}
//		cout << str << endl;
//		count++;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (cnt[i] > 0) {
				cnt[i] -= 1;
				string s = to_string(i);
				C(cnt, str + s, num, m);
				cnt[i] += 1;
			}
		}
	}
}

int main(){
	string num; cin >> num;
	int m; cin >> m;
	//cout << num;
	vector<int> cnt (10, 0);
	int size = num.size();
	for(int i =0; i< size; i++){
		int value = num[i]-48;
		cnt[value] += 1;
	}
	string str;
	time_t start = clock();
	C(cnt, str, num, m);
	time_t end = clock();
	cout << count << endl;
	cout << (end-start)/CLOCKS_PER_SEC << endl;
}

