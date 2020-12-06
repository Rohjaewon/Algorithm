#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
const int MAX = 1000;
int n; 
struct cmp {
    bool operator() (vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }  
};

bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int> > jobs) {
    int answer = 0, jidx = 0, currentTime = 0;
    sort(jobs.begin(), jobs.end(), comp);
    priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
    while (jidx < n || !pq.empty()) {
        if (jidx < n && jobs[jidx][0] <= currentTime) {
            pq.push(jobs[jidx++]);
            continue;
        } 
        if (!pq.empty()) {
            vector<int> temp = pq.top();
            currentTime += temp[1];
            answer += currentTime - temp[0];
            pq.pop();
        } else { //현재까지 처리한 작업들보다 현재 작업 시작시간이 멀리 있을 때
            currentTime = jobs[jidx][0];
        }
    }
    
    answer /= n;
    return answer;
}
int main() {
    vector<vector<int> >jobs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        vector<int> temp(2);
        temp[0] = t1; temp[1] = t2;
        jobs.push_back(temp);
    }
    cout << solution(jobs) << endl;
}

/*
- 오답 원인
겹치는 작업들은 처리시간이 짧은 순으로 처리해야 된다는 기본적인
아이디어는 잘 생각했지만 처리 시작 시간이 같은 여러 작업이 있거나,
처리 시작 시간이 항상 0이 아닌 점을 고려하지 않았음.
- 풀이과정
1. 작업들을 처리 요청 시간이 짧은 순으로 정렬 
2. 마지막으로 처리한 작업과 겹치는 모든 작업들을 우선순위 큐에 추가
   (우선순위 큐는 처리 시간이 짧은 순으로 정렬)
3. 겹치지 않는 작업까지 왔다면 우선순위 큐 순서대로 작업 처리
4. 겹치지 않는 작업부터 다시 2번으로.
*/