/*
 * Dijkstra.cpp
 *
 *  Created on: 2018. 12. 14.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 1000;

typedef struct node {
	int v = -1;
	int w = 0;
}node;

void Dijkstra(vector<vector<node> > G, int size, int v1, int v2, vector<int> visited) {
	vector<int> Dist(size, MAX);
	vector<int> parent(size, -1);
	int S = v1;
	visited[S] = 1;
	Dist[S] = 0;
	parent[S] = -1;
	while (S != v2) {
		cout <<"S : " << S << endl;
		vector<node>::iterator iter = G[S].begin();
		while (iter != G[S].end()) {
			node vertex = *iter;
			if (visited[vertex.v] == 0) {
				if (Dist[vertex.v] > Dist[S] + vertex.w){
					Dist[vertex.v] = Dist[S] + vertex.w;
					parent[vertex.v] = S;
				}
			}
			iter++;
		}//while
		cout << "parent : ";
		for (int i = 0; i < size; i++)
			cout << parent[i] << "  ";
		cout << endl;
		int min = MAX; int index = -1;
		for (int i = 0; i<size; i++) {
			if (visited[i] == 0) {
				if (min > Dist[i]) {
					min = Dist[i];
					index = i;
				}
			}
		}//for
		cout << "Dist   : ";
		for (int i = 0; i < size; i++)
			cout << Dist[i] << "  ";
		cout << endl;
		visited[index] = 1;
		S = index;
	}//while
	int index = v2;
	cout << "Length : " << Dist[v2] << endl;
	cout << "route : ";
	while (index != -1) {
		cout << index << " ";
		index = parent[index];
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<vector<node> > G(n);
	vector<int> visited(n, 0);
	for (int i = 0; i<m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		node temp; temp.v = v2; temp.w = w;
		G[v1].push_back(temp);
		temp.v = v1; temp.w = w;
		G[v2].push_back(temp);
	}
	int v1, v2;
	cin >> v1 >> v2;
	Dijkstra(G, n, v1, v2, visited);
}
*/


