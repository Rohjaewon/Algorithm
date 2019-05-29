/*
 * maze.cpp
 *
 *  Created on: 2018. 12. 18.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct point {
	int x;
	int y;
} point;

void BFS(vector<vector<int> > maze, vector<vector<bool> > visited, int n, int m,
		point start, point end) {
	queue<point> Q;
	vector<vector<int> > route(n, vector<int>(m, 1));
	Q.push(start);
	visited[start.x][start.y] = true;
	point v = start;
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		if (v.y + 1 < m) { //오른쪽 탐색
			if (visited[v.x][v.y + 1] == false) {
				if (maze[v.x][v.y + 1] == 1) {
					point temp;
					temp.x = v.x;
					temp.y = v.y + 1;
					visited[v.x][v.y + 1] = true;
					route[v.x][v.y + 1] = route[v.x][v.y] + 1;
					Q.push(temp);
				}
			}
		}
		if (v.x + 1 < n) { //아래
			if (visited[v.x + 1][v.y] == false) {
				if (maze[v.x + 1][v.y] == 1) {
					point temp;
					temp.x = v.x + 1;
					temp.y = v.y;
					visited[v.x + 1][v.y] = true;
					route[v.x + 1][v.y] = route[v.x][v.y] + 1;
					Q.push(temp);
				}
			}
		}
		if (v.y - 1 >= 0) { //왼쪽
			if (visited[v.x][v.y-1] == false) {
				if (maze[v.x][v.y-1] == 1) {
					point temp;
					temp.x = v.x;
					temp.y = v.y-1;
					visited[v.x][v.y-1] = true;
					route[v.x][v.y-1] = route[v.x][v.y] + 1;
					Q.push(temp);
				}
			}
		}
		if (v.x -1 >= 0) { //위
			if (visited[v.x - 1][v.y] == false) {
				if (maze[v.x - 1][v.y] == 1) {
					point temp;
					temp.x = v.x - 1;
					temp.y = v.y;
					visited[v.x - 1][v.y] = true;
					route[v.x - 1][v.y] = route[v.x][v.y] + 1;
					Q.push(temp);
				}
			}
		}
	}
	for(int i =0; i<n; i++){
		for(int j =0; j<m; j++){
			cout << route[i][j] << " ";
		}
		cout << endl;
	}
	cout << route[end.x][end.y] << endl;;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > maze(n, vector<int>(m)); //미로 형태
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}
	point start, end;
	start.x = 0; start.y = 0;
	end.x = n-1; end.y = m-1;
	BFS(maze, visited, n, m, start, end);
	return 0;
}
*/
