/*
 * union-find.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: harry
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct UF{
	vector<int> parent, rank;
	UF(int n) : parent(n), rank(n, 1){
		for(int i =0; i<n; i++)
			parent[i] = i;
	}
	int find(int w){
		if(w == parent[w]) return w;
		return parent[w] = find(parent[w]);
	}
	void merge(int u, int v){
		u = find(u); v = find(v);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v])
			rank[v]++;
	}
} UF;



