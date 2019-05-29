/*
 * PW486.cpp
 *
 *  Created on: 2019. 2. 11.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 1000*1000*10+1;
vector<int> p(MAX, 0);
int n, lo, hi;
void f(){//에라토스테네스 체
	p[0] = p[1] = -1;
	for(int i =2; i<=hi; i++)
		p[i] = i;
	int sqrtn = sqrt(hi);
	for(int i = 2; i<=sqrtn; i++){
		for(int j = i*i; j<=hi; j+= i){
			if(p[j] == j)
				p[j] = i;
		}
	}
}

int get_num(int n, int base){
	int cnt = 0;
	while(n > 1 && n%base == 0){
		n /= base;
		cnt++;
	}
	return cnt;
}

int main(){
	cin >> n >> lo >> hi;
	vector<int> num(MAX);
	num[0] = -1; num[1] = 1;
	f();
	for(int i =2; i<= hi; i++)
		if(p[i] == i)
			num[i] = 2;
	for(int i =2; i<=hi; i++){
		if(p[i] != i){
			int a = get_num(i, p[i]);
			//cout << "i : " << i << " p[i] : " << p[i] << " a : " << a;
			double temp = (double)(a+1)/(double)a;
			//cout << " temp : " << temp;
			num[i] = temp*num[i/p[i]];
			//cout << " num[i] : " << num[i] << endl;
		}
	}
	int cnt = 0;
	for(int i = lo; i<= hi; i++)
		if(num[i] == n)
			cnt++;
	cout << cnt << endl;
}
*/


