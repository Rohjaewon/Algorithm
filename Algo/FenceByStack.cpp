/*
 * FenceByStack.cpp
 *
 *  Created on: 2019. 2. 10.
 *      Author: harry
 */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> remain;
vector<int> hi;
int n, ret = -1;

int MaxFence(){
	for(int i =0; i< n; i++){
		while(!remain.empty() && hi[remain.top()] > hi[i]){
			int current = remain.top();
			remain.pop();
			int width = -1;
			if(remain.empty())
				width = i;
			else
				width = i-remain.top() - 1;
			ret = max(ret, hi[current]*width);
		}
		remain.push(i);
	}
	return ret;
}


int main(){
	cin >> n;
	for(int i =0; i< n; i++){
		int temp; cin >> temp;
		hi.push_back(temp);
	}
	cout << MaxFence();
}


