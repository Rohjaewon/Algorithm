/*
 * Potion.cpp
 *
 *  Created on: 2019. 2. 11.
 *      Author: harry
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> potion;//원래 비율
vector<int> current;//현재 들어가 있는 양
vector<int> base;//원래 비율을 최대공약수로 나눈 것
int gcd(int n1, int n2){
	if(n2 == 0) return n1;
	return gcd(n2, n1%n2);
}

int f(){
	int a = 0;
	for(int i =0; i<n; i++){
		if(current[i]%base[i] != 0)
			a = max(a, current[i]/base[i]+1);
		else
			a = max(a, current[i]/base[i]);
	}
	return a;
}
bool check(int a){
	for(int i =0; i<n; i++){
		if(base[i]*a < current[i])
			return false;
	}
	return true;
}

int main(){
	cin >> n;
	for(int i =0; i<n; i++){
		int temp; cin >> temp;
		potion.push_back(temp);
	}
	for(int i =0; i<n; i++){
		int temp; cin >> temp;
		current.push_back(temp);
	}

	int b = potion[0];
	for(int i =1; i<n; i++)
		b = gcd(b, potion[i]);
	for(int i =0; i<n; i++)
		base.push_back(potion[i]/b);
	int a = f();
	cout << "처음 : " << a << endl;
	while(!check(a)){
		a++;
	}
	cout << "a : " << a << endl;
	for(int i =0; i<n; i++)
		cout << base[i]*a - current[i] << " ";
}



