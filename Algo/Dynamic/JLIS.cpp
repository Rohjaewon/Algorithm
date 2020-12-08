#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
const int MAX = 102;
int C, N, M;
vector<int> a(MAX);
vector<int> b(MAX);
vector<vector<int> > dp(MAX, vector<int>(MAX, -1));

int jlis(int aIdx, int bIdx){
   int &ret = dp[aIdx+1][bIdx+1];
   if (ret != -1) return ret;
   ret = 0;
   int aa = aIdx == -1 ? NEGINF : a[aIdx+1];
   int bb = bIdx == -1 ? NEGINF : b[bIdx+1];

   int maxElement = max(aa, bb);
   for (int next = aIdx+1; next < N; next++) {
        if (a[next] > maxElement) {
            ret = max(ret, jlis(next, bIdx)+1);
        } 
   }

   for (int next = bIdx+1; next < M; next++) {
        if (b[next] > maxElement) {
            ret = max(ret, jlis(aIdx, next)+1);
        }
   }
   return ret;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int j = 0; j < M; j++)
        cin >> b[j];
    cout << jlis(-1, -1) << endl;
}

/*
- 해설
LIS와 같은 알고리즘으로 대신에 2개의 배열을 가지고 따진다.
jlis(int aIdx, int bIdx) : 현재 각 배열의 위치가 aIdx, bIdx일 때
다음 원소가 aIdx와 bIdx 중 큰 값보다 큰 원소들만 한번씩 시도해본다.
*/