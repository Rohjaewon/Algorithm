#include <iostream>
#include <stack>
#include <stack>
using namespace std;

bool solution(int n, string a) {
    stack<char> check;
    for(int i = 0; i < n; i++) {
        if (a[i] == '[') {
            check.push(a[i]);
        } else if (a[i] == ']') {
            if(check.empty()) return false;
            check.pop();
        }
    } 
    if (check.empty()) return true;
    else return false;
    
}

int main(){
    int n;
    string a = "";
    cin >> n;
    cin >> a;
    if(solution(n, a)) {
        cout << "True" << endl;
    } else cout << "False" << endl;
    return 0;
}