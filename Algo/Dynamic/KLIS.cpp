/*
 * KLIS.cpp
 *
 *  Created on: 2019. 1. 14.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int n =0, k, cnt = 0;

int get(vector<int> arr, int index, vector<vector<int>>& path, vector<int> length){
	int maxlength = 0, maxindex = -1;
	for(int i =0; i< index; i++){
		if (arr[i] < arr[index]){
			if (maxlength < length[i]) {
				maxlength = length[i];
				maxindex = i;
			}
		}
	}
	for(int i =0; i< index; i++){
		if (arr[i] < arr[index]) {
			if (maxlength == length[i])
				path[index].push_back(i);
		}
	}
	return maxindex;
}

void LIS(vector<int> arr, vector<vector<int>>& path, vector<int>& length){
	for(int i = 0; i<n; i++){
		if(i==0){
			length[i] =1;
			path[i].push_back(-1);
		}
		else{
			int index = get(arr, i, path, length);
			if(index != -1)
				length[i] = length[index] + 1;
			else{
				length[i] = 1;
				path[i].push_back(-1);
			}
		}
	}
}

void answer(vector<int> arr, vector<vector<int>> path, string str, int start, vector<string>& L){
	if (start == -1) {
		//cout << str << endl;
		L.push_back(str);
	}
	else// (start != -1)
		{
		//cout << start << endl;
		vector<int>::iterator iter = path[start].begin();
		while (iter != path[start].end()) {
			answer(arr, path, to_string(arr[start]) + str, *iter, L);
			iter++;
		}
	}
}



int main(){
	cin >> n >> k;
	vector<int> arr(n); vector<int> i_arr(n+1, -1);
	for(int i =0; i<n; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		i_arr[arr[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << i_arr[i] << " ";
	cout << endl;
	vector<vector<int> > path(n);
	vector<int> length(n, 0);

	LIS(arr, path, length);
	for (int i = 0; i < n; i++) {
		vector<int>::iterator iter = path[i].begin();
		while (iter != path[i].end()) {
			cout << *iter << " ";
			*iter++;
		}
		cout << endl;
	}
	for(int i =0; i<n; i++)
		cout << length[i] << " ";
	cout << endl;

	int max = 0;
	for(int i =0; i<n; i++){
		if(max < length[i])
			max = length[i];
	}
	cout << "max : " << max << endl;
	vector<int> S;
	for(int i =0; i<n; i++){
		if(length[i] == max)
			S.push_back(i);
	}
	sort(S.begin(), S.end());
	for(unsigned int i =0; i<S.size(); i++)
		cout << S[i] << " ";
	cout << endl;
	string str; vector<string> L;
	for(unsigned int i =0; i<S.size(); i++)
		answer(arr, path, str, S[i], L);
	sort(L.begin(), L.end());
	for(unsigned int i =0; i<L.size(); i++)
		cout << L[i] << " ";
	cout << endl;
	cout<< "답 : " << L[k-1] << endl;
}
*/


