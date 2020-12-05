#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<string> formedCases;

void getParenthesis(int open, int closed, string currentCase)
{
    if (closed == n)
    {
        formedCases.push_back(currentCase);
        return;
    }

    for (int i = 1; i <= open; i++)
    {
        for (int j = 1; j <= n - open + i - closed; j++)
        {
            string temp = genOpenString(i) + genCloseString(j);
            getParenthesis(open - i, closed + j, currentCase + temp);
        }
    }
}
string genOpenString(int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
        temp += "(";
    return temp;
}
string genCloseString(int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
        temp += ")";
    return temp;
}

int main() {
    cin >> n;
    getParenthesis(n, 0, "");
    for(int i = 0; i < formedCases.size(); i++) {
        cout << formedCases[i] << " ";
    }
}