/*
 * algo_5-1.cpp
 *
 *  Created on: 2018. 12. 5.
 *      Author: harry
 */

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int n;

void DFS(vector<vector<int> > adList, int v, vector<int>& visited, int& cnt){
	visited[v] = 1;
	cout << v << " -> ";
	vector<int>::iterator iter = adList[v].begin();
	while (iter != adList[v].end()) {
		int w = *iter;
		cout << w << endl;
		if (w != -1 && visited[w] == 0) {
			cout << "cnt : " << cnt + 1 << endl;
			DFS(adList, w, visited, ++cnt);
		}//if
		iter++;
	}//while
	cout << "back : " << v << " cnt : " << cnt << endl;
}
int main(){
	cin >> n;
	vector<vector<int> > adList(n);//graph모양을 구현하는 이차원 vector
	vector<int> temp(n);//임시로 정수들을 받아 놓는 vector
	vector<int> count(n);//각 index별로 얼마나 방문할 수 있는지 count하여 저장
	vector<int> visited(n, 0);//각 index별로 방문여부를 알려주는 vector
	for(int i=0; i<n; i++){
		cin >> temp[i];
	}

	for(int i =0; i<n; i++){
		int vertex = i+temp[i];
		int vertex2 = i-temp[i];
		if(vertex == i||vertex2==i)//더이상 이동할 곳이 없는 경우
			adList[i].push_back(-1);
		else {
			if (vertex >= 0 && vertex < n) {
				adList[i].push_back(vertex);
			} //if
			if (vertex2 >= 0 && vertex2 < n) {
				adList[i].push_back(vertex2);
			}
		}
	}//graph만드는 for문
	for (unsigned int i = 0; i < adList.size(); ++i) {
	     vector<int>::iterator itr =  adList[i].begin();
	     cout << i;
	     while (itr != adList[i].end()) {
	        cout <<  " -> " << *itr;
	             ++itr;
	     }
	     cout << endl;
	}cout << endl;

	for(int v = 0; v<n; v++){
		int cnt = 1; DFS(adList,v,visited, cnt);
		count[v] = cnt;
		for(int i =0; i<n; i++)
			visited[i] = 0;
	}
	for(int i =0; i<n; i++)
		cout << count[i] << " ";
	cout << endl;
	int largest = 0; int largestlo = -1;
	for(int i =0; i<n; i++){
		if(largest < count[i]){
			largest = count[i];
			largestlo = i;
		}
	}
	cout << largestlo << " " << largest << endl;
}
/*
#include <iostream>
using namespace std;
void DFS(int cellnum[], int start, int n, bool visited[], int &cnt){
	visited[start] = true;
	int vertex = start - cellnum[start];
	int vertex2 = start + cellnum[start];
	if(vertex >= 0){//왼쪽으로 방문할 수 있으면 이동
		if(visited[vertex] == false){
			DFS(cellnum, vertex, n, visited, ++cnt);
		}
	}
	if(vertex2 < n){//오른쪽으로 방문할 수 있으면 이동
		if(visited[vertex2] == false){
			DFS(cellnum, vertex2, n, visited, ++cnt);
		}
	}
}

int main(){
	int n;
	cin >> n;
	int* cellnum = new int[n];//셀 값을 저장하는 배열
	bool* visited = new bool[n];//각 셀의 방문여부를 확인하는 배열
	int* count = new int[n];//각 셀의 방문 가능한 최대 개수를 저장하는 배열
	for(int i =0; i<n; i++){
		cin >> cellnum[i];
		visited[i] = false;
		count[i] = 0;
  }

	for(int i =0; i<n; i++){
		int cnt = 1;
		DFS(cellnum, i, n, visited, cnt);
		count[i] = cnt;
		for(int i =0; i<n; i++)
			visited[i] = false;
	}
	int largest = 0; int largestlo = -1;//largest는 도달한 셀의 개수 largestlo는 도달한 셀의 개수가 가장 많은 시작점의 위치
	for(int i =0; i<n; i++){
		if(largest < count[i]){
			largest = count[i];
			largestlo = i;
		}
	}
	cout << largestlo << " " << largest << endl;
}*/

