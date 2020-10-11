#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> cache(101, vector<int>(101, -1));

bool solution(string a, string b, int aIdx, int bIdx){
    //cout << aIdx << " " << bIdx << endl;
    int& ret = cache[aIdx][bIdx];
    if(ret != -1)
        return ret;
    if(bIdx == b.size()){
        if(aIdx == a.size() || (aIdx == a.size() -1 && a[aIdx] == '*')){
            return ret = true;
        } 
        else return ret = false;
    }
    if(a[aIdx] != '*'){
        if(a[aIdx] != '?' && a[aIdx] != b[bIdx])
            return ret = false;
        return ret = solution(a, b, aIdx+1, bIdx+1);
    } else{
        return ret = solution(a, b, aIdx+1, bIdx) || solution(a, b, aIdx, bIdx+1);
    }
}

int main(){
    int n;
    string wildcard;
    cin >> wildcard;
    cin >> n;
    vector<string> targets(n);
    for(int i = 0; i < n; i++){
        cin >> targets[i];
    }
    cout << "------------" << endl;
    for(int i = 0; i < n; i++){
        if(solution(wildcard, targets[i], 0, 0))
            cout << targets[i] << endl;
        fill(cache.begin(), cache.end(), vector<int>(101, -1));
    }
}