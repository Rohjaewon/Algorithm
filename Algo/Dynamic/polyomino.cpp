/*
 * polyomino.cpp
 *
 *  Created on: 2019. 1. 8.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;
const long int mod = 10000000;
int cache[MAX][MAX] = {0};

int poly(int first, int num) {
	int& temp = cache[first][num];
	if(temp != 0) return temp;
	if (num==0)
		return temp=1;
	else{
	//cout << "first : " << first << " " << "num : " << num << endl;
	for (int second = 1; second <= num; second++) {
			temp += poly(second, num - second) * (first + second - 1);
			temp %= mod;
	}
	//cout << temp << endl;
	return temp;
	}
}

int main() {
	int num;
	cin >> num;
	vector<int> answer(MAX, 0);
	for (int first = 1; first <= num; first++) {
		//cout << "맨 위 : " << first << endl;
		answer[first] = poly(first, num-first);
	}
	int sum = 0;
	for (int i = 1; i <= num; i++){
		sum += answer[i];
		sum %= mod;
	}
	cout << sum << endl;
}*/
/*
#include <iostream>
using namespace std;

const int MOD = 10000000;
int cache[101][101];

int poly(int n, int first){
	if(n==first)
		return 1;
	int &ret = cache[n][first];
	if(ret != -1) return ret;
	ret = 0;
	for(int second = 1; second <= n-first; ++second){
		int add = second + first -1;
		add *= poly(n-first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main(){
	int num; cin >> num; int answer = 0;
	for(int i =0; i<101; i++){
		for(int j = 0; j <101; j++)
			cache[i][j] = -1;
	}
	for(int first = 1; first < num; first++){
		answer += poly(num, first);
		answer %= MOD;
	}
	cout << answer+1;
}*/
