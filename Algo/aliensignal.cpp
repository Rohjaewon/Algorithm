/*
 * aliensignal.cpp
 *
 *  Created on: 2019. 2. 7.
 *      Author: harry
 */
/*
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;

int k, n, sum =0, cnt = 0;
int num = 1984; unsigned int A = 1983;
void f(){
	num = A%10000+1;
	A = (A*214013+2531011);
}

int main(){
	cin >> k >> n;
	queue<int> list;
	for(int i =0; i<n; i++){
		list.push(num);
		sum += num;
		f();
		while(sum > k){
			sum -= list.front();
			list.pop();
		}
		if(sum == k)
			cnt++;
	}
	cout << cnt;
}*/
