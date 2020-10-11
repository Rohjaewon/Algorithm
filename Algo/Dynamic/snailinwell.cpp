#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 100;
int n, m;

vector<vector<int>> cache(MAX, vector<int>(2*MAX, -1));

double cntEscape(int curH, int curM){
   if(curM == m) return curH >= n ? 1 : 0;
   int& ret = cache[curM][curH];
   ret = 1/4 * cntEscape(curH+2, curM+1) + 3/4*cntEscape(curH+1, curM+1);
   return ret; 
}

int main(){
    cin >> n >> m;
    cout << cntEscape(0, 1) << endl;
}