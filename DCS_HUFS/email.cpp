#include <iostream>
#include <string>
using namespace std;

int solution(string email) {
    int cvtLength = 0;
    for (int i = 0; i < email.size(); i++) {
        if (email[i] >= 'a' && email[i] <= 'z') {
            cvtLength++;
        }
    }
    return cvtLength;
}

int main(){
    string email;
    cin >> email;
    cout << solution(email);

    return 0;
}