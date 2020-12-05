#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000;
const int USED = 100;
int n;
vector<int> nums(1000, 0);
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
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
}