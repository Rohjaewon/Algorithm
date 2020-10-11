#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int N;
vector<long long> cache(102, -1);

long long tiling(int n) {
    long long& ret = cache[n];
    if(n == 1 || n == 0) return ret = 1;
    if(ret != -1) return ret;
    ret = (tiling(n-2) + tiling(n-1)) % MOD;
    return ret;
}

long long asymTiling(int n){
    if(n ==1 || n == 2) return 0;
    long long ret = tiling(n);
    if(n % 2 == 0)
        ret = (ret - cache[n/2] - cache[(n-2)/2] + 2*MOD) %MOD;
    else ret = (ret - cache[(n-1)/2] + MOD) % MOD;
    return ret;
}

int main(){
    cin >> N;
    cout << asymTiling(N) << endl;
}