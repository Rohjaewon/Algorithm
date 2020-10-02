/*
 * wildcard.cpp
 *
 *  Created on: 2019. 1. 3.
 *      Author: harry
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAX = 100;
int cache[MAX][MAX];
bool Iswildcard(string w, string s, int w_ptr, int s_ptr){
	int w_size = w.size(), s_size = s.size();
	cout << s[s_ptr] << "," << w[w_ptr] << endl;
	if (s_ptr < s_size && w_ptr < w_size &&
				(s[s_ptr] == '?' || s[s_ptr] == w[w_ptr])){
			s_ptr++; w_ptr++;
			return Iswildcard(w,s,w_ptr,s_ptr);
	}
	if(s_ptr == s_size){
		if(w_ptr == w_size)
			return 1;
		else return 0;
	}

	if(s[s_ptr] == '*'){
		if((w_ptr < w_size && Iswildcard(w,s,w_ptr+1, s_ptr)) || Iswildcard(w,s,w_ptr, s_ptr+1)){
			return 1;
		}
	}
	return 0;
}

vector<string> wildcard(vector<string> s, string str, int n){
	vector<string> answer;
	for(int i =0; i<n; i++){
		if(Iswildcard(s[i], str, 0, 0))
			answer.push_back(s[i]);
	}
	return answer;
}

int main(){
	string str;
	cin >> str;
	int n; cin >> n;
	vector<string> s(n);
	for(int i =0; i<n; i++){
		string s1; cin >> s1;
		s[i] = s1;
	}
	for(int i =0; i<MAX; i++){
		for(int j = 0; j<MAX; j++)
			cache[i][j] = -1;
	}
	vector<string> answer = wildcard(s, str, n);
	for(unsigned int i = 0; i< answer.size(); i++){
		cout << answer[i] << " ";
	}
}



