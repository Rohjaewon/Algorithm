#include <iostream>
#include <vector>
using namespace std;
const int USED = 100;
int n;
vector<vector<int> >cases;

void solution(vector<int>& nums, vector<int>& current) {
    if (current.size() == n) {
        cases.push_back(current);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] != USED) {
            current.push_back(nums[i]);
            int temp = nums[i];
            nums[i] = USED;
            solution(nums, current);
            nums[i] = temp;
            current.pop_back();
        }
    }
}

int main() {
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> current;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    solution(nums, current);
}

/*
- 풀이과정
현재 위치에서 nums의 각 원소를 한번씩 시도하며, 이 과정을
매 단계마다 반복한다. 이 때 원소가 중복되면 안되므로, 현재 위치에서 어떤
원소를 사용했다면 다음 단계에서 알 수 있도록 값을 USED로 바꿔놓고 재귀호출한다.
재귀 호출이 끝나면 다시 원래 상태로 돌려놓고 다음 원소를 시도한다.
*/