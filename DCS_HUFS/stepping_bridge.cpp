#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1002;
int n;
vector<int> bridge(MAX, 0);
vector<int> cache(MAX, -1);
int solution(int curr) {
    if(curr == n-1) {
        return 1;
    }
    if(curr >= n) {
        return 0;
    }
    int &ret = cache[curr];
    if(ret != -1) return ret;
    ret = 0;
    int can_go = bridge[curr];
    for (int go = 1; go <= can_go; go++) {
        int temp = solution(curr+go);
        if (temp == 1) {
            ret = 1;
            break;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> bridge[i];
    }
    if(solution(0) > 0) {
        cout << "True" << endl;
    } else cout << "False" << endl;
}