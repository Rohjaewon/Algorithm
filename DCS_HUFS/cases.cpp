#include <iostream>
#include <vector>
using namespace std;
const int MAX = 60;

int m, c, t;
vector<vector<long long> >cases(MAX, vector<long long>(MAX, -1));

long long solution(int c, int m) {
    long long & ret = cases[c][m];
    if(ret != -1) return ret;
    if(c == m) {
        ret = 1;
        return ret;
    }
    if(m == 0) {
        ret = 1;
        return ret;
    }
    ret = solution(c-1, m) + solution(c, m-1);
    return ret;
}

int main() {
    cin >> m >> t;
    c = t - m;
    cout << solution(c, m) << endl;
}