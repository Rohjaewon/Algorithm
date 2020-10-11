#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = -1, d = -1, s = -1;
int n;
vector<double> village(52, 0.0);
vector<double> connected(52, 0);
vector<vector<int>> path(52, vector<int>(52, 0));

void dunibal(int start, int d, double prob){
	if(d == 0){
		village[start] += prob;
		return;
	}
	for(int i = 0; i < N; i++){
		if(path[start][i] == 1){
			dunibal(i, d-1, prob * (1 / connected[start]));
		}
	}
}

int main(){
	
	cin >> N >> d >> s;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> path[i][j];
		}
	}
	cin >> n;
	vector<int> dist(n, -1);
	for(int i = 0; i < n; i++)
		cin >> dist[i]; 
	for(int i = 0; i < N; i++){
		int cnt = 0;
		for(int j = 0; j < N; j++){	
			if(path[i][j] == 1) cnt++;
		}
		connected[i] = cnt;
	}
	dunibal(s, d, 1);
	for(int i = 0; i < n; i++){
		cout << village[dist[i]] << " ";
	} cout << endl;
}