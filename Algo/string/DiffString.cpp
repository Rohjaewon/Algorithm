/*
 * DiffString.cpp
 *
 *  Created on: 2019. 2. 19.
 *      Author: harry
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1<<10;


int group[MAX], sa[MAX];//sa : 접미사의 사전식 순서
int t, n;

bool comp(int a, int b){
	if(group[a] != group[b]){
		return group[a] < group[b];
	}
	return group[a+t] < group[b+t];
}

int* suffix(const string s){
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
	string s;
	cin >> s;
	int n = s.size();
	int * s_arr = suffix(s);
	int s_length[n];//접미사의 길이 저장
	for(int i =0; i<n; i++){
		s_length[i] = n-s_arr[i];
	}
	vector<string> answer;
	answer.push_back(s.substr(s_arr[0]));
	for(int i =1; i<n; i++){
		int start = 1;
		if(s[s_arr[i-1]] == s[s_arr[i]]){
			start = s_length[i-1]+1;
		}
		while(start <= s_length[i]){
			answer.push_back(s.substr(s_arr[i], start));
			start++;
		}
	}
	vector<string>::iterator iter = answer.begin();
	while(iter != answer.end()){
		cout << *iter << endl;
		iter++;
	}
	cout << answer.size() << endl;
	return 0;
}



