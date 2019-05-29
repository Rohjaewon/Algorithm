/*
 * FenwickTree.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
using namespace std;

typedef struct fenwick{
	vector<int> tree;
	fenwick(int n):tree(n+1){}

	int sum(int pos){
		int ret = 0; pos++;
		while(pos > 0){
			ret += tree[pos];
			pos &= (pos-1);
		}
		return ret;
	}
	void add(int pos, int val){
		pos++;
		tree[pos] += val;
		pos += (pos&-pos);
	}
}fenwick;
*/


