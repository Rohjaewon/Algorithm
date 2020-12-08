/*
 * LIS.cpp
 *
 *  Created on: 2018. 11. 2.
 *      Author: harry
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int n = 0;
const int NEGINF = numeric_limits<int>::min();
vector<int> cache(101, -1);
vector<int> arr(101, 0);
vector<int> choices(101, -1);
int LIS(int curr){
	int &ret = cache[curr+1];
	int element = curr == -1 ? NEGINF : arr[curr+1];
	ret = 1;
	for (int next = curr+1; next < n; next++) {
		if (arr[next] > element) {
			ret = max(ret, LIS(next)+1);
		}
	}
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

/*
- 해설
LIS(int curr) : 현재 위치 curr일 때 가장 긴 증가 부분수열의 길이
curr일 때 그 뒤에 있는 원소들 중 현재 값보다 큰 원소들을 한번씩 시도해봄.
*/

