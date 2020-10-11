#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int solution(vector<pair<int,int>> lunch){
    sort(lunch.begin(), lunch.end());
    int time = 0;
    for(int i = 0; i < lunch.size(); i++){
        if(i == 0){
            time += lunch[i].first;
        } else{
            time += lunch[i].first > lunch[i-1].second ? lunch[i].first : lunch[i-1].second;
        }
    } time += lunch[lunch.size()-1].second;
    return time;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> lunch(n, make_pair(0, 0));
    vector<int> m(n, 0);
    vector<int> e(n, 0);
    for(int i = 0; i < n; i++){
        cin >> m[i];
    }
    for(int i = 0; i < n; i++){
        cin >> e[i];
    }
    for(int i = 0; i < n; i++){
        lunch[i] = make_pair(m[i], e[i]);
    }
    cout << solution(lunch) << endl;
}