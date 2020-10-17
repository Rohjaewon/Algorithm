/*
 * LIS.cpp
 *
 *  Created on: 2018. 11. 2.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int n = 0;
vector<int> cache(101, -1);
vector<int> arr(101, 0);
vector<int> choices(101, -1);
int LIS(int curr){
	int& ret = cache[curr+1];
	if(ret != -1) return ret;
	ret = 1;
	int bestNext = -1;
	for (int next = curr + 1; next < n; next++)	{
		int cand = -1;
		if (curr == -1)
			cand = LIS(next);
		else if (arr[curr] < arr[next])
			cand = LIS(next) + 1;
		if (cand != -1 && cand > ret){
			ret = cand;
			bestNext = next;
		}
	}
	choices[curr+1] = bestNext;
	return ret;
}

void findLISPath(int curr){
	if(curr != -1) cout << arr[curr] << " ";
	int next = choices[curr+1];
	if(next != -1) findLISPath(next);
}

int main(){
	srand((int)time(0));
	while (1){
		cin >> n;
		if(n == -1) return 0;
		for (int i = 0; i < n; i++)
			arr[i] = rand() % 10 + 1;
			//cin >> arr[i];
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		cout << LIS(-1) << endl;
		findLISPath(-1);
		cout << endl;
	}
}

