#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

vector<string> filterStopped(const map<string, int> &reportStatus, int k) {
    vector<string> ret;
    for (auto status: reportStatus) {
        if (status.second >= k) {
            ret.push_back(status.first);
        }
    }
    return ret;
}

int countMatches(const set<string> &called, const vector<string> &stopped) {
    int cnt = 0;
    for (auto id : called) {
        for (auto stoppedId : stopped) {
            if (stoppedId == id) {
                cnt++;
            } 
        }
    }
    return cnt;
}

map<string, int> countEmail(const map<string, set<string>> &reportTable, 
    const map<string, int> &reportStatus, int k) {

    map<string, int> mail;
    vector<string> stoppedList = filterStopped(reportStatus, k);
    for (auto currentReport : reportTable) {
        int emailCnt = countMatches(currentReport.second, stoppedList);
        cout << emailCnt << endl;
        mail[currentReport.first] = emailCnt;
    }
    return mail;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> reportTable;
    map<string, int> reportStatus;
    for (auto rep: report) {
        int delIdx = rep.find(" ");
        string src = rep.substr(0, delIdx);
        string dst = rep.substr(delIdx+1);
        auto result = reportTable[src].insert(dst);
        if (result.second) {
            auto found = reportStatus.find(dst);
            if (found == reportStatus.end()) {
                reportStatus[dst] = 1;
            } else {
                reportStatus[dst] += 1;
            }
        }
    }
    map<string, int> emailResult = countEmail(reportTable, reportStatus, k);
    for (auto id : id_list) {
        answer.push_back(emailResult[id]);
    }
    return answer;
}

int main() {
    vector<string> id_list {"muzi", "frodo", "apeach", "neo"};
    vector<string> report {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;
    vector<int> answer = solution(id_list, report, k);
    for (auto result : answer) {
        cout << result << " ";
    } cout << endl;
}