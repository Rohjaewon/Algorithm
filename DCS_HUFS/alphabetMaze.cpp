#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 22;;

int n, m;

vector<int> alpha(26, 0);
vector<string>miro(MAX, "");
int solution(int y, int x) {
    int ret = 1;
    int idx = miro[y][x] - 'A';
    alpha[idx] += 1;
    if (y > 0) {
        if (alpha[miro[y-1][x] - 'A'] == 0)
            ret = max(ret, solution(y-1, x) + 1);
    }
    if (x > 0){
        if (alpha[miro[y][x-1] - 'A'] == 0)
            ret = max(ret, solution(y, x-1) + 1);
    } 
    if (y < n-1){
        if (alpha[miro[y+1][x] - 'A'] == 0) 
            ret = max(ret, solution(y+1, x) + 1);
    } 
    if (x < m-1){
        if (alpha[miro[y][x+1] - 'A'] == 0) 
            ret = max(ret, solution(y, x+1) + 1);  
    }
    alpha[idx] -= 1;
    return ret;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> miro[i];
    }
    cout << solution(0, 0);
}