#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
        int ret = 0, lo = 0, hi = height.size()-1;
        while (lo < hi) {
            ret = max(ret, min(height[lo], height[hi])*(hi-lo));
            if (height[lo] < height[hi]) {
                lo++;
            }
            else {
                hi--;
            }
        }
        return ret;
}

int main() {
    int n;
    vector<int> height;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        height.push_back(temp);
    }
    cout << maxArea(height) << endl;
}