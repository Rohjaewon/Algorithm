#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const long long POSINF = 987654321;
long long N, P;
vector<vector<long long>> cache(102, vector<long long>(11, -1));
vector<int> numbers(101, 1002);

long long minError(int from, int size)
{
    long long minErr = POSINF;
    for (int quanNum = numbers[from]; quanNum <= numbers[from + size - 1]; quanNum++)
    {
        long long tempErr = 0;
        for (long long start = from; start < from + size; start++)
        {
            tempErr += pow(numbers[start] - quanNum, 2);
        }
        minErr = min(minErr, tempErr);
    }
    return minErr;
}

long long quantize(int from, int parts){
    if (from == N) return 0;
    if (parts == 0) return POSINF;

    long long &ret = cache[from][parts];
    if (ret != -1) return ret;
    ret = POSINF;
    for (int s = 1; s <= N - from; s++)
        ret = min(ret, minError(from, s) + quantize(from + s, parts - 1));
    return ret;
}

int main()
{
    cin >> N >> P;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    int answer = quantize(0, P);
    cout << "answer : " << answer << endl;
    return 0;
}