#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1002;

int r, c;
vector<string> miro(MAX, "");
vector<vector<int> > cache(MAX, vector<int>(MAX, -1));
vector<vector<int> > visited(MAX, vector<int>(MAX, 0));
int solution(int y, int x, int b)
{
    // cout << y << " " << x << " " << b << endl;
    if (y == r - 1 && x == c - 1)
    {
        return 1;
    }
    int &ret = cache[y][x];
    visited[y][x] = 1;
    if (ret != -1 && ret != 10000)
        return ret;
    ret = 10000;
    if (y > 0)
    {
        // cout <<visited[y-1][x] << endl;
        if (!visited[y - 1][x])
        {
            if (miro[y - 1][x] == '1')
            {
                if(b==1){
                    ret = min(ret, solution(y - 1, x, b-1) + 1);
                }
                    
            }
            else
                ret = min(ret, solution(y - 1, x, b) + 1);
            visited[y-1][x] = 0;

        }
    }
    if (x > 0)
    {
        // cout <<visited[y][x-1] << endl;
        if (!visited[y][x - 1])
        {
            if (miro[y][x - 1] == '1')
            {
                if(b == 1){
                    ret = min(ret, solution(y, x - 1, b-1) + 1);
                    
                }
                    
            }
            else
                ret = min(ret, solution(y, x - 1, b) + 1);
            visited[y][x-1] = 0;
        }
    }
    if (y < r - 1)
    {
        // cout <<visited[y+1][x] << endl;
        if (!visited[y + 1][x])
        {
            if (miro[y + 1][x] == '1'){
                if(b == 1)
                    ret = min(ret, solution(y + 1, x, b-1) + 1); 
            }
            else
                ret = min(ret, solution(y + 1, x, b) + 1);
            visited[y+1][x] = 0;
        }
    }
    if (x < c - 1)
    {
        // cout <<visited[y][x+1] << endl;
        if (!visited[y][x + 1])
        {
            if (miro[y][x + 1] == '1')
            {
                if(b==1)
                ret = min(ret, solution(y, x + 1, b-1) + 1);
            }
            else
                ret = min(ret, solution(y, x + 1, b) + 1);
            visited[y][x+1] = 0;
        }
    }
    visited[y][x] = 0;
    return ret;
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        // cin >> miro[i];
        miro[i] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    }
    int answer = solution(0, 0, 1);
    if (answer >= 10000)
        answer = -1;
    cout << answer << endl;
        
}