/*
 * suffixArray.cpp
 *
 *  Created on: 2019. 2. 18.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1<<10;

string s;
int group[MAX], sa[MAX];//sa : 접미사의 사전식 순서
int t, n;

bool comp(int a, int b){
	if(group[a] != group[b]){
		return group[a] < group[b];
	}
	return group[a+t] < group[b+t];
}

int* suffix(){
	n = s.size();
	for(int i =0; i<n; i++){
		group[i] = s[i];
		sa[i] = i;
	} group[n] = -1;
	t = 1;
	while(t<=n){

		sort(sa, sa+n, comp);//첫 t글자에 대해 사전순 정렬

		vector<int> temp(n+1); temp[n] = -1;
		temp[sa[0]] = 0;
		for(int i = 1; i<n; i++){
			if(comp(sa[i-1], sa[i]))
			temp[sa[i]] = temp[sa[i-1]] + 1;
			else
				temp[sa[i]] = temp[sa[i-1]];
		}
		for(int i =0; i< n; i++)
			group[i] = temp[i];
		t *= 2;
	}
	return sa;
}


int main(){
	cin >> s;
	int * arr = suffix();
	for(int i =0; i<n; i++){
		cout << s.substr(arr[i]) << endl;
	}
}*/







