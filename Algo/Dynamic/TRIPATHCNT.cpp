#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> tri(100);
vector<vector<int>> cache(100, vector<int>(100, -1));
vector<vector<int>> cntCache(100, vector<int>(100, -1));
int maxPath(int y, int x){
    if(y == n-1)
        return tri[y][x];
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = tri[y][x] + max(maxPath(y+1, x), maxPath(y+1, x+1));
    return ret;
}

int cntPath(int y, int x){
    if(y == n-1) return 1;
    int& ret = cntCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    int down = maxPath(y+1, x);
    int lowerright = maxPath(y+1, x+1);
    if(down >= lowerright) ret += cntPath(y+1, x);
    if(down <= lowerright) ret += cntPath(y+1, x+1);
    return ret;
}

int main(){
    cin >> n;
    int rowCnt = 1;
    while(rowCnt <= n){
        for(int i = 0; i < rowCnt; i++){
            int t;
            cin >> t;
            tri[rowCnt-1].push_back(t);
        }
        rowCnt++;
    }
    cout << cntPath(0, 0) << endl;
}