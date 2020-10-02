/*
 * pi.cpp
 *
 *  Created on: 2019. 1. 2.
 *      Author: harry
 */
#include <iostream>
#include <string>
using namespace std;
const int MAX = 10002;
const int INF = 987654321;
int cache[MAX][MAX];

int min(int left, int mid, int right){
	if(left <= mid && left <= right)
		return left;
	if(mid <= left && mid <= right)
		return mid;
	else// (right < left && right < mid)
		return right;
}

int check(string str){
	int size = str.size();
	if(size < 3)
		return 10;
	//난이도 1
	bool diff1 = true;
	for(int i =01; i< size; i++)
		if(str[i] != str[i-1])
			diff1 = false;
	if(diff1) return 1;
	//등차수열 판별
	bool equaldiff = true;
	int d = str[1]-str[0];
	for(int i = 2; i<size; i++){
		if(str[i]-str[i-1] != d)
			equaldiff = false;
	}
	if(equaldiff){//등차수열 일 때
		if(d == 1 || d == -1) // 단조 증가 또는 감소일 때
			return 2;
		else return 5; // 그냥 등차수열일 때
	}
	//난이도 4
	bool diff4 = true;
	for(int i =2; i<size; i++){
		if(str[i] != str[i%2])
			diff4 = false;
	}if(diff4) return 4;

	return 10;

}

int answer (int start, int end, string str){
	int& ret = cache[start][end];
	if(start > end)
		return 0;
	if(ret != INF) return ret;
	else{
			ret = min(ret, check(str.substr(start, 3))+answer(start+3, end, str));
			ret = min(ret, check(str.substr(start, 4))+answer(start+4, end, str));
			ret = min(ret, check(str.substr(start, 5))+answer(start+5, end, str));
		return ret;
	}
}

int main(){
	string pi; cin >> pi;
	int size = pi.size();
	for(int i =0; i< MAX; i++)
		for(int j = 0; j<MAX; j++)
			cache[i][j] = INF;
	cout << answer(0, size-1, pi) << endl;
}
/*
 * pi.cpp
 *
 *  Created on: 2019. 1. 2.
 *      Author: harry
 */
/*
#include <iostream>
#include <string>
using namespace std;
const int MAX = 10002;
const int INF = 987654321;
int cache[MAX];

int min(int left, int right){
	if(left < right)
		return left;
	else return right;
}

int check(string str){
	int size = str.size();
	if(size < 3)
		return 10;
	//난이도 1
	bool diff1 = true;
	for(int i =01; i< size; i++)
		if(str[i] != str[i-1])
			diff1 = false;
	if(diff1) return 1;
	//등차수열 판별
	bool equaldiff = true;
	int d = str[1]-str[0];
	for(int i = 2; i<size; i++){
		if(str[i]-str[i-1] != d)
			equaldiff = false;
	}
	if(equaldiff){//등차수열 일 때
		if(d == 1 || d == -1) // 단조 증가 또는 감소일 때
			return 2;
		else return 5; // 그냥 등차수열일 때
	}
	//난이도 4
	bool diff4 = true;
	for(int i =2; i<size; i++){
		if(str[i] != str[i%2])
			diff4 = false;
	}if(diff4) return 4;

	return 10;

}

int answer (int start, string str){
	int& ret = cache[start];
	int size = str.size();
	if(start >= size || size < 3)
		return 0;
	if(ret != INF) return ret;
	else{
		for(int cut = 3; cut <= 5; cut++){
			//cout << str.substr(start, cut) << endl;
			//cout << check(str.substr(start, cut)) << endl;
			ret = min(ret, check(str.substr(start, cut))+answer(start+cut, str));
		}
		return ret;
	}
}

int main(){
	for (int i = 0; i < 50; i++) {
		string pi;
		cin >> pi;
		for (int i = 0; i < MAX; i++)
			cache[i] = INF;
		cout << answer(0, pi) << endl;
	}
}
*/




