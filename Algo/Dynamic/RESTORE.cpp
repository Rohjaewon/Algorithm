/*
 * RESTORE.cpp
 *
 *  Created on: 2019. 1. 15.
 *      Author: harry
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<string> arr;
vector<int> size;

int get_most(string str, vector<int> picked){
	int left = 0, right = 0, most = 0, index = -1;
	int size = str.size();
	for(int i =0; i<n; i++){
		if(!picked[i]){
			int j = 0, k = size[i]-1;
			while(j < size && k >= 0){
				if(str[j] == arr[i][k]){
					left++;
					j++; k--;
				}//if
				else break;
			}//while
			j = size-1, k = 0;
			while(j >= 0 && k < size[i]){
				if(str[j] == arr[i][k]){
					right++;
					j--; k++;
				}//if
				else break;
			}//while
			if(most < left+right){
				most = left+right;
				index = i;
			}
		}//if
	}
	return index;
}

void shortest(string& str, vector<int>& picked){

}

int main(){
	cin >> n;

	for(int i =0; i<n; i++){
		string str; cin >> str;
		arr.push_back(str);
	}
	for(int i =0; i<n; i++)
		size.push_back(arr[i].size());
	vector<bool> picked(n, false);
	int max = 0, index = -1;
	for(int i =0; i<n; i++){
		if(max < size[i]){
			max = size[i];
			index = i;
		}
	}
	picked[index]=true;

}



