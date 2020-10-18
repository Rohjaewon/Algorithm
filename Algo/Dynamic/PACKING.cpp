#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int MIN = numeric_limits<int>::min();

typedef struct info{
    string name;
    int w;
    int u;
} info;
vector<info> stuff(101);
vector<vector<int> > cache(101, vector<int>(1001, -1));
vector<int> choices(101, -1);
vector<string> answers;
int n, w;

int pack(int start, int curW){
    if(start == n) return 0;
    int& ret = cache[start][curW];
    if(ret != -1) return ret;
    ret = pack(start+1, curW);
    if(curW >= stuff[start].w){
        ret = max(ret, pack(start+1, curW - stuff[start].w)+ stuff[start].u) ;
    }
    return ret;
}

void reconstruct(int capacity, int item, vector<int>& picked){
    if(item == n) return;
    if(pack(item, capacity) == pack(item+1, capacity)){//item을 넣지 않아도 넣은 것과 결과가 같다면 안넣는다.
        reconstruct(capacity, item+1, picked);
    } else {
        picked.push_back(item);
        reconstruct(capacity - stuff[item].w, item+1, picked);
    }
}

int main(){
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> stuff[i].name >> stuff[i].w >> stuff[i].u;
    }
    vector<int> picked;
    int answer = pack(0, w);
    reconstruct(w, 0, picked);
    cout << answer << " " << picked.size() << endl;
    for(auto iter = picked.begin(); iter != picked.end(); iter++){
        cout << stuff[*iter].name << " ";
    } cout << endl;
    return 0;
}