/*
 * SectionTree.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

typedef struct RNG{
	vector<int> RangeMin;
	int n;
	RNG(vector<int> arr){//생성자에서 RangeMin 배열 초기화
		n = arr.size();
		RangeMin.resize(n*4);
		Init(arr,0, n-1, 1);//RangeMin배열 초기화 함수
	}
	int Init(vector<int> arr, int l, int r, int node){
		if(l == r)
			return RangeMin[node] = arr[left];
		int mid = (l+r)/2;
		return RangeMin[node] = min(Init(arr, l, mid, node*2), Init(arr, mid+1, r, node*2+1));
	}
	int query(int l, int r, int node, int nl, int nr){
		if(nl < l && nr > r)
			return INF;
		if(nl >= l && nr <= r)
			return RangeMin[node];
		int mid = (nl+nr)/2;
		return min(query(l, r, node*2, nl, mid), query(l, r, node*2+1, mid+1, nr));
	}
	int query(int l, int r){
		return query(l, r, 1, 0, n-1);
	}
	int update(int index, int newVal, int node, int l, int r){
		if(index < l && index > r)
			return RangeMin[node];
		if(l==r)
			RangeMin[node] = newVal;
		int mid = (l+r)/2;
		return RangeMin[node] = min(update(index, newVal, node*2, l, mid),
				update(index, newVal, node*2+1, mid+1, r));
	}
	int update(int index, int newVal){
		return update(index, newVal, 1, 0, n-1);
	}
}RNG;
*/



