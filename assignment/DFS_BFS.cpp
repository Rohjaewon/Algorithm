/*
 * algo_5-2.cpp
 *
 *  Created on: 2018. 12. 6.
 *      Author: harry
 */
/*
#include <iostream>
using namespace std;

typedef struct Node{
	int vertex;
	Node* link;
}Node;

void DFS(Node** adList, bool* visited, int v, int& cnt){
	visited[v] = true;
	Node* ptr = adList[v];
	while(ptr != NULL){
		int w = ptr->vertex;
		if(visited[w] == false){
			DFS(adList, visited, w, ++cnt);
		}
		ptr=ptr->link;
	}
}


int main(){
	int n, m;
	cin >> n >> m;
	Node ** adList = new Node*[n];//연결리스트로 그래프 구현
	bool *visited = new bool[n];//방문여부를 알려주는 배열
	int *count = new int[n];//연결요소의 정점 개수를 저장하는 배열
	for(int i =0; i<n; i++){
		adList[i] = NULL;
		visited[i] = false;
		count[i] = 0;
	}
	for(int i =0; i<m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		Node *ptr = new Node;
		ptr->vertex = v2; ptr->link = adList[v1];
		adList[v1] = ptr;
		ptr = new Node;//무방향그래프이므로 양쪽을 연결해준다.
		ptr->vertex = v1;
		ptr->link = adList[v2];
		adList[v2] = ptr;
	}

	for(int v =0; v<n; v++){
		int cnt=1;
		DFS(adList, visited, v, cnt);
		count[v] = cnt;
	}
	int max = 0;
	for(int i =0; i<n; i++){
		if(max < count[i])//연결요소들의 정점 개수 중 가장 큰 연결요소의 정점 개수를 찾는다.
			max = count[i];
	}
	cout << max << endl;
}
*/
/*
#include <iostream>
#include <queue>
const int MAX = 100000;
using namespace std;
int n;
void BFS(int **adMatrix, int visited[], int v1, int v2, int cnt, int& smallest){
	queue<int> order;//레벨 순서대로 큐에 들어가고 빠진다
	int u; //현재 위치와 인접한 index를 탐색하는 변수
	int* count = new int[n];//각 노드의 경로의 길이를 저장
	for(int i =0; i<n; i++)
		count[i] = 0;
	order.push(v1);
	while(!order.empty()){
		int w = order.front(); order.pop();
		visited[w] = 1;
		for(u =0; u<n; u++){
			if(adMatrix[w][u] == 1){
				if (visited[u] == 0) {
					visited[u] = 1;
					count[u] = count[w] + 1;//부모노드 w와 자식노드 u가 인접하면 u의 경로길이는 부모노드 w의 경로길이에서 +1한 만큼이다.
					if (u == v2) {//도착지점에 이르면 cnt에 경로 길이를 저장해주고 break
						cnt = count[u];
						break;
					}
					order.push(u);
				} //if
			}//if
		}//for
		if(u == v2){//도착지점에 도착하면 현재 탐색한 경로와 현재까지의 최단경로를 비교한다.
			if(smallest > cnt)
				smallest = cnt;
		}
	}//while
}

int main(){
	 int m;
	cin >> n >> m;
	int **adMatrix = new int*[n];
	int *visited = new int[n];
	for(int i =0; i<n; i++){
		adMatrix[i] = new int[n];
		visited[i] = 0;
	}
	for(int i =0; i<n; i++)
		for(int j =0; j<n; j++)
			adMatrix[i][j] = 0;

	for(int i =0; i<m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		adMatrix[v1][v2] = 1;
		adMatrix[v2][v1] = 1;
	}

	int v1, v2, smallest = MAX;
	cin >> v1 >> v2;
	BFS(adMatrix, visited, v1,v2,0,smallest);
	if(smallest == MAX) smallest = -1;//원하는 도착지점에 가지 못할 경우
	cout << smallest << endl;
	return 0;
}
*/

