#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<vector<int> > cases;
int userCnt = 0, bannedCnt = 0;

bool canBeMatched(string candidate, string id) {
    if (candidate.size() != id.size()) {
        return false;
    }
    for (int i = 0; i < candidate.size(); i++) {
        if (id[i] != '*' && id[i] != candidate[i]) {
            return false;
        }
    }
    return true;
}

void count(vector<string> user_id, vector<string> banned_id, 
           vector<int> &banned, vector<bool> &visited, int bannedUser) {
    if (bannedUser == bannedCnt) {
        vector<int> temp(banned);
        sort(temp.begin(), temp.end());
        cases.insert(temp);
        return;
    }
    for (int user = 0; user < userCnt; user++) {
        if (!visited[user] && canBeMatched(user_id[user], banned_id[bannedUser])) {
            banned.push_back(user);
            visited[user] = true;
            count(user_id, banned_id, banned, visited, bannedUser+1);
            visited[user] = false;
            banned.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    userCnt = user_id.size();
    bannedCnt = banned_id.size();
    vector<int> banned;
    vector<bool> visited(userCnt, false);
    count(user_id, banned_id, banned, visited, 0);
    answer = cases.size();
    return answer;
}

/*
- 풀이과정
완전탐색을 위해서 for문과 재귀호출을 섞어서 사용.
매칭 여부 판단에 있어서 중복을 허용하지 않도록 visited를 사용했고
매칭이 되는 하나의 케이스를 완성하면 선택된 index를 정렬하여 set에
저장한다. 따라서 set에는 중복되지 않는 선택된 index들의 배열들만 남을 것이고
set의 원소 개수가 이 문제의 답이 된다.
*/