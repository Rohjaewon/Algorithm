/*
 * RunningMedian.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: harry
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void GetMid(vector<int> A){
	int ret = 0;
	priority_queue<int, vector<int>, less<int>> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int n = A.size();
	for(int i =0 ; i<n; i++){
		int mas = maxheap.size(), mis = minheap.size();
		if(mas == mis){
			//cout << "max" << A[i] << endl;
			maxheap.push(A[i]);
		}
		else{
			//cout << "max" << A[i] << endl;
			minheap.push(A[i]);
		}
		if(!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()){
			int a = maxheap.top(), b = minheap.top();
			maxheap.pop(); minheap.pop();
			maxheap.push(b); minheap.push(a);
		}
		cout << maxheap.top() << " ";
		ret = (ret+maxheap.top())%20090711;
		//cout << ret << endl;
	}
	cout << endl;
	cout << ret << endl;
}

int getnum(int A, int a, int b){
	//cout << ((long long)A*(long long)a+b)%20090711 << endl;
	return ((long long)A*(long long)a+b)%20090711;
}

int main(){
	int n; //a, b;
	cin >> n;// >> a>> b;
	vector<int> A(n);
	//A[0] = 1983;
	for(int i =0; i<n; i++){
		cin >> A[i];
		//A[i] = getnum(A[i-1], a, b);
	}
	GetMid(A);
}

