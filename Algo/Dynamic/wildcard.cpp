#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > cache(101, vector<int>(101, -1));

int solution(string a, string b, int aIdx, int bIdx){
    if (aIdx == a.size()) {
        return (bIdx == b.size() ? 1 : 0);
    }
    if (bIdx == b.size()) {
        if (aIdx == a.size() || a[aIdx] == '*') {
            return 1;
        } else {
            return 0;
        }
    }
    int& ret = cache[aIdx][bIdx];
    if (ret != -1) return ret;
    ret = 0;
    if (a[aIdx] != '*') {
        if (a[bIdx] == '?' || a[aIdx] == b[bIdx]) {
            ret = solution(a, b, aIdx+1, bIdx+1);
        }
    }
    else {
        for (int next = bIdx; next <= b.size(); next++) {
            ret |= solution(a, b, aIdx+1, next);
        }
    }
    return ret;
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
        if(solution(wildcard, targets[i], 0, 0) == 1)
            cout << targets[i] << endl;
        fill(cache.begin(), cache.end(), vector<int>(101, -1));
    }
}

/*
- 풀이과정
일반 문자와 '?'는 단순 1대1 매칭으로 해결하면 되지만 
'*'가 문제였다. 여기선 '*'를 0개 부터 끝까지 매칭여부를 따졌다.
베이스케이스는 만약 wildcard가 끝났을 때 일반 문자열이 끝나지 않았다면
그 경우는 실패한 것, 일반 문자열이 끝났을 때 wildcard가 끝나지 않았을 때
'*'였다면 성공, 그 외의 케이스는 실패로 처리했다. 각 문자열의 index로
메모아이징 적용.
*/