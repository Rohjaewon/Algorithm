/*
 * Josephus.cpp
 *
 *  Created on: 2019. 2. 10.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
using namespace std;

int n, k, cnt = 0, i = 0;

void Josephus(vector<int>& jo){
	while(jo.size() > 2){
		if(cnt == 0){
			//cout << jo[i] << endl;
			cnt = k%jo.size();
			jo.erase(jo.begin()+i);
		}
		else{
			i++; i%=jo.size();
		}
			cnt--;
	}
}

int main(){
	cin >> n >> k;
	vector<int> jo(n);
	for(int i =0; i<n; i++)
		jo[i] = i+1;
	Josephus(jo);
	for(int i =0; i<2; i++)
		cout << jo[i] << " ";
	return 0;
}
*/


