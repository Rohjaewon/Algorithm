/*
 * algo3.cpp
 *
 *  Created on: 2018. 11. 2.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int randomRange(int n1, int n2) {
	return (int) (rand() % (n2 - n1 + 1)) + n1;
}

int serial(vector<int>a){
	int sum[5] = {0}, maxsum=0;
	for(int i =0; i<5;i++){
		if(i==0)
			sum[i] = a[i];
		else if(sum[i-1] > 0)
			sum[i] = sum[i-1]+a[i];
		else
			sum[i] = a[i];
	}
	for(int i =0; i<5; i++){
		if(maxsum < sum[i])
			maxsum = sum[i];
	}
	return maxsum;
}

int main(){
	srand((int)time(0));
	vector<int> arr(5);
	for(int i =0; i<5; i++)
		arr[i] = randomRange(-7, 8);
	for(int i =0; i<5; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << serial(arr);
}
*/



