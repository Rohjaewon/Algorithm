#include <string>
#include <vector>
#include <iostream>
using namespace std;

void takeAction(vector<vector<int>> &board, const vector<int> &action) {
    int value = action[5];
    if (action[0] == 1) {
        value *= -1;
    }
    for (int y = action[1]; y <= action[3]; y++) {
        for (int x = action[2]; x <= action[4]; x++) {
            board[y][x] += value;
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for (vector<int> action : skill) {
        takeAction(board, action);
    }
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board[y].size(); x++) {
            if (board[y][x] > 0) answer++;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board {{5,5,5,5,5},
    {5,5,5,5,5},
    {5,5,5,5,5},
    {5,5,5,5,5}};
    vector<vector<int>> skill {{1,0,0,3,4,4},
    {1,2,0,2,3,2},
    {2,1,0,3,1,2},
    {1,0,1,3,3,1}};
    cout << solution(board, skill) << endl;
}