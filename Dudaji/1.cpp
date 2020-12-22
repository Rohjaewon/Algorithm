#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//nums배열을 정렬 후에 한 바퀴 돌면서 숫자가 
//threshold(n/2)를 넘는지 체크.
//vector를 매개변수로 받을 때 call-by-value로 알고있음.
int solution(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int current = nums[0], count = 0;
    int threshold = nums.size() / 2;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == current) {
            count += 1;
        } else {
            if (count > threshold) {
                break;
            }
            current = nums[i];
        }
    }
    return current;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    cout << solution(nums) << endl;
}