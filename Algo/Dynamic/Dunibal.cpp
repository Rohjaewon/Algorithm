#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = -1, d = -1, s = -1;
int n;
vector<double> village(52, 0.0);
vector<double> connected(52, 0);
vector<vector<int> >  path(52, vector<int>(52, 0));
vector<vector<double> > cache(52, vector<double>(102, -0.5));

double dunibal(int here, int d){ //d일 째에 here에 있을 확률 = 전날 there들에서 here로 올 확률을 다 더한 값
	if(d == 0)
		return here == s ? 1.0 : 0.0;
	double& ret = cache[here][d];
	if(ret != -0.5) return ret;
	ret = 0.0;
	for(int i = 0; i < N; i++){ // 전날의 there = i
		if(path[here][i] == 1){
			ret += dunibal(i, d-1) / connected[i];
		}
	}
	return ret;
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
	for(int i = 0; i < dist.size(); i++){
		cout << dunibal(dist[i], d) << " ";
	} cout << endl;
}