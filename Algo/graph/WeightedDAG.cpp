/*
 * WeightedDAG.cpp
 *
 *  Created on: 2018. 12. 15.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
stack<int> S;
typedef struct node{
	int v;
	int w;
	node* link;
}node;

void DFS(node** adList, int v, int n, vector<int>& visited){
	visited[v] = 1;
	node* ptr = adList[v];
	while(ptr != NULL){
		int w = ptr->v;
		if(visited[w] == 0)
			DFS(adList, w, n, visited);
		ptr = ptr->link;
	}
	S.push(v);
}

void LongestWay(node** adList, int n, int v1, int v2){
	int* L = new int[n];
	for(int i =0; i<n; i++)
		L[i] =0;
	while(!S.empty()){
		int v = S.top(); S.pop();
		for(int i =0; i<n; i++){
			node* ptr = adList[i];
			while(ptr!=NULL){
				if(ptr->v == v){
					if(L[v] < L[i]+ptr->w)
						L[v] = L[i]+ptr->w;
						break;
				}
				ptr = ptr->link;
			}
		}
	}//while
	for(int i =0; i<n; i++)
		cout << L[i] << " ";
	cout << endl;
	cout << L[v2] << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	node** adList = new node*[n];
	for (int i = 0; i < n; i++)
		adList[i] = NULL;
	vector<int> visited(n, 0);
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		node* ptr = new node;
		ptr->v = v2; ptr->w = w;
		ptr->link = adList[v1];
		adList[v1] = ptr;
	}
	DFS(adList,0,n,visited);
	LongestWay(adList,n, 0, 6);
}
*/
