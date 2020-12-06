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

    for (int willOpen = 1; willOpen <= open; willOpen++)
    {
        for (int willClose = 1; willClose <= n - willOpen + willClose - closed; willClose++)
        {
            string temp = genOpenString(willOpen) + genCloseString(willClose);
            getParenthesis(open - willOpen, closed + willClose, currentCase + temp);
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

/*
- 풀이과정
getParenthesis(int open, int closed, string currentCase)
open : 남은 열린 괄호의 개수
closed : 닫힌 열린 괄호의 개수
currentCase : 현재 괄호 상태
열린 괄호는 open수만큼 추가할 수 있고 닫힌 괄호는 현재까지 괄호 중
닫히지 않은 열린괄호의 개수 만큼 추가할 수 있다. 따라서 닫히지 않은
열린 괄호의 개수는 현재를 포함하여 열린 괄호 개수(n-open+willOpen)에서 
닫힌 괄호의 개수(closed)만큼 뺀 것이 닫히지 않을 괄호의 개수가 된다.
각 단계마다 이런 방식으로 경우의 수를 계산하여 열린괄호와 닫힌괄호를 추가하는 작업을
반복한다.
*/