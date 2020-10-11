#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int C, N, M;
int A[102], B[102];
int dp[102][102];

int jlis(int aIdx, int bIdx){
    int& ret = dp[aIdx+1][bIdx+1];
    if(ret != -1) return ret;
    
    ret = 0;
    long long aa = aIdx == -1 ? NEGINF : A[aIdx];
    long long bb = bIdx == -1 ? NEGINF : B[bIdx];
    long long maxElement = max(aa, bb);

    for(int next = aIdx+1; next < N; next++){
        if(A[next] > maxElement)
            ret = max(ret, jlis(next, bIdx));
    }
    for(int next = bIdx+1; next < M; next++){
        if(B[next] > maxElement)
            ret = max(ret, jlis(aIdx, next));
    }
    return ret;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int j = 0; j < M; j++)
        cin >> B[j];
    //cout << jlis(-1, -1) << endl;
}