#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 10000000;
int N;
vector<vector<int>> cache(102, vector<int>(102, -1));

int poly(int n, int prev){
	if(n == 0){
		return 1;
	}
	int& ret = cache[n][prev];
	if(ret != -1 ) return ret;
	ret = 0;
	for(int i = 1; i <=n; i++){
		if(prev == 0)
			ret += poly(n-i, i) % MOD;
		else
			ret += ((prev + i - 1) * poly(n-i, i))%MOD;
		ret %= MOD;
	}
	return ret;
}

int main(){
	cin >> N;	
	cout << poly(N, 0) << endl;
}
