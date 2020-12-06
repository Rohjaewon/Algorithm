#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int ret = 0, left = 0, right = height.size()-1;
    while (left < right) {
        ret = max(ret, min(height[left], height[right])*(right-left));
        height[left] < height[right] ? ++left : --right;
    }
    return ret;
}

int main()
{
    int n;
    vector<int> height;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        height.push_back(temp);
    }
    cout << maxArea(height) << endl;
}

/* 
비슷한 문제 : 최대 울타리 면적
- 풀이과정
울타리 면적 문제는 분할과 정복 문제여서 이 문제도 비슷한 방식으로
해결할 수 있을 거라고 생각함. 그러다 보니 더 단순한 문제임에도 분할과 정복 방식으로
풀려다 보니 해결하지 못함.
- 정답 증명
양 옆의 높이만 고려하기 때문에 시작을 맨 양옆에서 부터 시작.
현재 물의 양을 계산한 후 다음 단계로 넘어갈 때 더 낮은 쪽을 
안쪽으로 이동시킨다. 이유는 더 높은 쪽을 이동시켜봤자 현재 물의 양보다
더 낮아지기만 하기 때문. 따라서 최대 값을 찾기 위해선 높은 쪽은 고정하고 
낮은 쪽을 안쪽으로 이동시켜야 한다.

*/