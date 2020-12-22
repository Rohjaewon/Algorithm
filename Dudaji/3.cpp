#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    vector<int> maxPrices(prices.begin()+1, prices.end());
    sort(maxPrices.begin(), maxPrices.end());
    int current = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        current = prices[i];
        int maxPrice = maxPrices[maxPrices.size()-1];
        cout << current << " " << maxPrice << endl;
        answer = max(answer, maxPrice - current);
        if (prices[i+1] == maxPrice) {
            maxPrices.pop_back();
        }
    }
    cout << answer << endl;
    //[7 8 1 5 3 6]
    //7 - 1 3 5 6 8 => 1
    //8 - 1 3 5 6 => -2
    //1 - 1 3 5 6 => 5
    //5 - 1 3 5 6 => 1
    //3 - 1 3 5 6 => 3
    //6 - 1 3 5 => -1
}


/*
첫번째 원소를 제외하고 나머지 원소들을 정렬 시킨 다음에 
현재 값과 최대값의 차이를 구한다. 다음 원소를 확인하기 전에
정렬된 값의 최대값이 빠지게 되면 그 다음 원소를 최대값으로 하여 
같은 방식으로 계산.

*/