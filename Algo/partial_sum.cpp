/*
 * partial_sum.cpp
 *
 *  Created on: 2018. 12. 31.
 *      Author: harry
 */
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <stack>
//using namespace std;
/*
int main(){
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> pnum(n, 0);
	for(int i =0; i<n; i++){
		int num; cin >> num;
		arr[i] = num;
	}
	for(int i =0; i<n; i++){
		if(i == 0)
			pnum[i] = arr[i];
		else{
			pnum[i] = pnum[i-1]+arr[i];
		}
	}
	vector<int>tempnum(pnum);
	sort(tempnum.begin(), tempnum.end());
	int min = 1000, ex1 = -1, ex2 = -1;
	for(int i =1; i<n; i++){
		int temp = tempnum[i]-tempnum[i-1];

		if(min > temp){
			min = temp;
			ex1 = tempnum[i];
			ex2 = tempnum[i-1];
		}
	}
	int index = -1, index2 = -1;
	for(int i =0; i<n;i++){
		if(pnum[i] == ex1)
			index = i;
		else if(pnum[i] == ex2)
			index2 = i;
	}
	cout << "최소 구간  : " << index2+1 << "~" << index << endl;
}
*/
/*
typedef struct point{
	int left = -1;
	int right = -1;
}point;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> present(n);
	vector<int> presum(n, 0);
	stack<point> S;
	for(int i =0; i<n; i++){
		int num; cin >> num;
		present[i] = num;
	}
	for(int i =0; i<n; i++){
		if(i==0)
			presum[i] = present[i];
		else{
			presum[i] = presum[i-1]+present[i];
		}
	}
	int cnt=0;
	for(int i =n-1; i>=0; i--){
		if(presum[i]%k == 0){
			cnt++;
			point temp; temp.left = 0; temp.right = i;
			S.push(temp);
		}
		for(int j = 0; j<i; j++){
			if((presum[i] - presum[j])%k == 0){
				cnt++;
				point temp2; temp2.left = j+1; temp2.right=i;
				S.push(temp2);
			}
		}
	}
	cout << cnt << " ";
	point range; range.left = -1; range.right = -1;
	int cnt2 = 0;
	while(!S.empty()){
		point temp = S.top(); S.pop();
		if(temp.left > range.right || temp.right < range.left){
			range = temp;
			cnt2++;
		}
	}
	cout << cnt2 << endl;
}
*/

