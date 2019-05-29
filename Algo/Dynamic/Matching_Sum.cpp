/*
 * algo1.cpp
 *
 *  Created on: 2018. 10. 30.
 *      Author: harry
 */
/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarysearch(vector<int>a, int first, int last, int x, int size){
	if(first > last){
		if(first == size)
			return -1; // left를 올려야 함
		else return -2;//right를 줄여야 함
	}
	else{
		int mid = (first+last)/2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)
			return binarysearch(a,first,mid-1,x, size);
		else
			return binarysearch(a,mid+1,last,x, size);
	}
}

int main(){
	int n; int final;//만들어야할 수
	int flag = 0;//원소를 찾아서 종료했는지 못찾고 종료했는지 구분
	int index = -1;
	cin >> n; cin >> final;
	vector<int> arr(n);
	for(int i =0; i<n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int left = 0; int right = n-1;
	while(right - left >1){
		int temp = final - (arr[left]+arr[right]);
		index = binarysearch(arr, left+1, right-1, temp, right);
		cout << "index : " << index << endl;
		if(index > left){
			flag = 1;
			break;
		}
		if(index == -1)
			left++;
		if(index == -2)
			right--;
	}
	if(flag == 1){
		cout << arr[left] << " " << arr[index] << " " << arr[right] << endl;
	}
	else
		cout<<"없음" << endl;
}
*/

