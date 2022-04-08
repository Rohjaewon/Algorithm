#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;



int calcDiff(pair<int, int> src, pair<int, int> dist) {
    int xDiff = abs(dist.first - src.first);
    int yDiff = abs(dist.second - src.second);
    return yDiff + xDiff;
}

string solution(vector<int> numbers, string hand) {
    map<int, pair<int, int>> keypad {
        {1, make_pair(0, 0)},
        {2, make_pair(0, 1)},
        {3, make_pair(0, 2)},
        {4, make_pair(1, 0)},
        {5, make_pair(1, 1)},
        {6, make_pair(1, 2)},
        {7, make_pair(2, 0)},
        {8, make_pair(2, 1)},
        {9, make_pair(2, 2)},
        {0, make_pair(3, 1)}
    };
    string answer = "";
    pair<int, int> leftPos = make_pair(3, 0);
    pair<int, int> rightPos = make_pair(3, 2);

    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            leftPos = keypad[num];
        } else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            rightPos = keypad[num];
        } else {
            pair<int, int> dist = keypad[num];
            int leftDiff = calcDiff(leftPos, dist);
            int rightDiff = calcDiff(rightPos, dist);
            if (leftDiff < rightDiff) {
                answer += "L";
                leftPos = dist;
            } else if (leftDiff > rightDiff) {
                answer += "R";
                rightPos = dist;
            } else {
                if (hand == "left") {
                    answer += "L"; 
                    leftPos = dist;
                } else {
                    answer += "R";
                    rightPos = dist;
                }
            }
        }
    }
    return answer;
}