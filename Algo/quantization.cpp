/*
 * quantization.cpp
 *
 *  Created on: 2019. 1. 3.
 *      Author: harry
 */
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
const int MAX = 102;
int cache[MAX];

int average(vector<int> q, int start, int end){
	int sum = 0;
	for(int i = start; i <= end; i++)
		sum += q[i];
	int aver = sum/(end-start+1);
	return aver;
}

void Getaver(vector<int> q, vector<vector<int> >& a, int start, int n, int m){
	if (m > 1) {
		for (int cut = 0; cut < n-m+1; cut++) {
				//cout << "m : " << m << " " << endl;
				cout << start << "," << start + cut << endl;
				cout << average(q, start, start + cut) << endl;
				a[start][cut] = average(q, start, start + cut);
				Getaver(q, a, start + cut + 1, n - cut - 1, m-1);
		}
	}
	else{
		//cout << "m : " << m << endl;
		cout << start << "," << start+n-1 << endl;
		cout << average(q, start, start+n-1) << endl;
		a[start][start+n-1] = average(q, start, start+n-1);
	}
}

int main(){
	int n, m; cin >> n >>m;
	vector<int> q(n);
	vector<vector<int> > a(n, vector<int>(n, 0));
	for(int i =0; i<n; i++){
		int num; cin >> num;
		q[i] = num;
	}
	sort(q.begin(), q.end());
	Getaver(q, a, 0, n, m);
	for(int i =0; i < n; i++){
		for(int j = 0; j< n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for(int i =0; i<MAX; i++)
		cache[i] = INF;
}
*/


