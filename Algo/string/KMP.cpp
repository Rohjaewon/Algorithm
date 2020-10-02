/*
 * KMP.cpp
 *
 *  Created on: 2019. 2. 10.
 *      Author: harry
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string N, M;
int n, m;

vector<int> partial(string N){
	n = N.size();
	vector<int> pi(n, 0);
	int begin = 1, matched = 0;
	while(begin+matched < n){
		if(N[begin+matched] == N[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		}
		else{
			if(matched ==0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> KMP(string N, string M){
	m = M.size();
	vector<int> ret;
	vector<int> pi = partial(N);
	int begin = 0, matched = 0;
	while(begin <= m-n){
		if(matched < n && M[begin+matched] == N[matched]){
			matched++;
			if(matched == n)
				ret.push_back(begin);
		}
		else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}

int main(){
	cin >> M >> N;
	vector<int> answer = KMP(N, M);
	for(unsigned int i =0; i< answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}

