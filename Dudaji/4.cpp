#include <iostream>
#include <vector>
using namespace std;

const int MAX = 3 * 104;
const int ARRMAX = 2 * 3 * 104 + 2;


int solution(vector<int> & nums, vector<int>& count) {
    int answer = MAX+1;
    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        if (current < 0) {
            current = current * (-1) + MAX;
        }
        count[current] += 1;
    }
    for (int i = 0; i < ARRMAX; i++) {
        if (count[i] == 1) {
            answer = i;
        }
    }
    return answer;
}

int test() {
    vector<int> input = {2, 2, 1};
    vector<int> input2 = {4, 1, 2, 1, 2};
    vector<int> input3 = {1};
    vector<int> input4 = {-100, -312, 312, -100, -312};
    vector<int> input5;
    for (int i = 0; i < MAX-2; i++) {
        input5.push_back(-312);
    }
    input5.push_back(300);
    vector<int> input6 = {0, 0, -1, -1, 2, 2, 3};

    vector<int> count(ARRMAX, 0);
    return solution(input6, count);
}

int main() {
    // int n;
    // cin >> n;
    // vector<int> nums(MAX);
    // for (int i = 0; i < n; i++) {
    //     cin >> nums[i];
    // }
    cout << test() << endl;
    return 0;
}

/*
1 : 배열을 한 바퀴 돌아서 각 원소마다 중복 여부를 판단
0 ~ 2 * MAX count 배열 선언한 뒤 배열에서 원소가 등장할 때마다
count[i] += 1; 
원래 배열의 값이 음수일 땐 (-1)*a[i] + 3*104가 count배열의 index
*/