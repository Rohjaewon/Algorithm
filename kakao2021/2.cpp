#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

bool isPrime(long long subN) {
    if (subN <= 1) return false;
    for (long long i = 2; i*i <= subN; i++) {
        if (subN % i == 0) {
            return false;
        }
    }
    return true;
}

string convertKdigit(int n, int k) {
    string converted = "";
    if (k == 10) return to_string(n);
    while (n != 0) {
        int l = n % k;
        n /= k;
        converted = to_string(l) + converted;
    }
    return converted;
}

// index, sub number
pair<int, long long> getPrimeToken(string n, int curIdx) {
    string token = "";
    long long retNum = 0;
    while (curIdx < n.size() && n[curIdx] != '0') {
        token += n[curIdx];
        curIdx++; 
    }
    if (token != "") {
        retNum = stoll(token);
    }
    return make_pair(curIdx, retNum);
}

int solution(int n, int k) {
    int answer = 0;
    string newN = convertKdigit(n, k);
    cout << newN << endl;
    int start = 0;
    int last = 0;
    while (start < newN.size()) {
        pair<int, long long> token = getPrimeToken(newN, start);
        last = token.first;
        long long tokenNum = token.second;
        if (isPrime(tokenNum)) {
            cout << "is prime!" << endl;
            if (start == 0 && newN[last] == '0') { // 오른쪽에만 0
                answer += 1;
            } else if (newN[start-1] == '0' && last == newN.size()) { //왼쪽에만 0
                answer += 1;
            } else if (newN[start-1] == '0' && newN[last] == '0') { // 양쪽이 0
                answer += 1;
            } else if (start == 0 && last >= newN.size()) { // 숫자 전체가 소수 일 때
                answer += 1;
            }
        } 
        start = last + 1;
    }
    return answer;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    cout << solution(n, k) << endl;

}