/*
 * topologicalsort.cpp
 *
 *  Created on: 2018. 12. 15.
 *      Author: harry
 */

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef struct node{
	int v;
	node* link = NULL;
}node;

void topologicalsort(node** adList, int n, vector<int> visited, vector<int> indegree){
	queue<int> Q;
	queue<int> order;
	for(int i =0; i<n; i++)
		if(indegree[i] == 0){
			Q.push(i);
			order.push(i);
			visited[i] =1;
		}
	while(!Q.empty()){
		int w = Q.front(); Q.pop();
		node* ptr = adList[w];
		while(ptr != NULL){
			int v = ptr->v;
			indegree[v] -= 1;
			if(indegree[v] == 0){
				Q.push(v);
				order.push(v);
			}
			ptr = ptr->link;
		}
	}
	while(!order.empty()){
		cout << order.front() << " ";
		order.pop();
	}
}

int main(){
	int n, m; cin >> n >> m;
	node** adList = new node*[n];
	for(int i =0; i<n; i++)
		adList[i] = NULL;
	vector<int>indegree(n, 0);
	vector<int>visited(n,0);
	for(int i =0; i<m; i++){
		int v1, v2; cin >> v1 >> v2;
		node* ptr = new node;
		ptr->v = v2; ptr->link = adList[v1];
		adList[v1] = ptr;
	}
	for(int i =0; i<n; i++){
		node* ptr = adList[i];
		while(ptr != NULL){
			int v = ptr->v;
			indegree[v] += 1;
			ptr = ptr->link;
		}
	}
	for(int i =0; i<n; i++)
		cout << indegree[i] << " ";
	cout << endl;
	topologicalsort(adList,n,visited,indegree);
	return 0;
}
stack<int> S;
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

int main(){
	int n, m; cin >> n >> m;
		node** adList = new node*[n];
		for(int i =0; i<n; i++)
			adList[i] = NULL;
		vector<int>visited(n,0);
		for(int i =0; i<m; i++){
			int v1, v2; cin >> v1 >> v2;
			node* ptr = new node;
			ptr->v = v2; ptr->link = adList[v1];
			adList[v1] = ptr;
		}
		DFS(adList, 0, n, visited);

		while(!S.empty()){
			cout << S.top() << " ";
			S.pop();
		}
}



