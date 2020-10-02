/*
 * Habit.cpp
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

int prefix(int i, int j){
	int cnt = 0;
	//cout << s.substr(i) << ", " << s.substr(j) << endl;
	while(i < s.size() && j < s.size() && s[i] == s[j]){
		//cout  << s[i];
		i++; j++; cnt++;
	}//cout << endl;
	return cnt;
}

int main(){
	int k, n;
	cin >> k >> s;
	n = s.size();
	int * arr = suffix();
	if(k == 1){
		cout << n;
		return 0;
	}

	vector<int> answer;
	for(int i =0; i<n; i++){
		int length = -1, cnt = 1;
		for(int j =i+1; j<n; j++){
			int temp = prefix(arr[i], arr[j]);
			//cout << length << ", " << temp  << ", " << cnt << endl;
			if(temp == 0) break;
			if(length < 0){
				length = temp; cnt++;
			}
			else if(length == temp)
				cnt++;
		}
		if(cnt >= k){
			answer.push_back(length);
		}
	}
	int maxnum = 0;
	for(int i =0; i<answer.size(); i++){
		maxnum = max(maxnum, answer[i]);
	}
	cout << maxnum;
}



