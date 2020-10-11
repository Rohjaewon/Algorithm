#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int POSINF = numeric_limits<int>::max();
int n;
string number;
vector<int> cache(10001, POSINF);
int howHard(string sub){
    bool dif1 = true, dif2 = true, dif4 = true, dif5 = true, dif10 = true;
    int num1 = -1;
    for(int i = 0; i < sub.size(); i++){
        int num = sub[i] - '0';
        if(i == 0) num1 = num;
        else if(num1 != num) {dif1 = false; break;}
    } if(dif1) return 1;

    int before = -1, updown = -1;
    for(int i = 0; i < sub.size(); i++){
        int num = sub[i] - '0';
        if(before != -1){
            if(updown == -1) {updown = num - before;}
            if((updown != 1 && updown != -1) || (num - before != updown)){
                dif2 = false;
                break;
            }
        }
        before = num;
    } if(dif2) return 2;
    int first = -1, second = -1;
    for(int i = 0; i < sub.size(); i++){
        int num = sub[i] - '0';
        if(first == -1){first = num; continue;}
        else if(second == -1){ second = num; continue;}
        if(i % 2 == 0){
            if(first != num){
                dif4 = false;
                break;
            }
        } else{
            if(second != num){
                dif4 = false;
                break;
            }
        }
    } if(dif4) return 4;

    int gap = -1, beforeN = -1;
    for(int i = 0; i < sub.size(); i++){
        int num = sub[i] - '0';
        if(beforeN != -1){
            if(gap == -1) {gap = num - beforeN; continue;}
            if(gap != (num - beforeN)){
                dif5 = false;
                break;
            }
        }
        beforeN = num;
    } if(dif5) return 5;
    return 10;
}

int dif(int cur){
    int left = number.size() - cur;
    if(left > 0 && left <= 2) return 10;
    else if (left == 0) return 0;
    int& ret = cache[cur];
    if(ret != POSINF) return ret;
    for(int sub = 3; sub <= 5; sub++){
        if(cur + sub <= number.size()){
            ret = min(ret, dif(cur+sub)+howHard(number.substr(cur, sub)));
        }
    }
    return ret;
}

int main(){
    cin >> number;
    cout << dif(0) << endl;
}