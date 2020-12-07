#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 36;
const int COSTMAX = 100000;
const int CURVE = 6;
const int STRAIGHT = 1;
vector<vector<int>> cost(MAX, vector<int>(MAX, COSTMAX));
enum DIR {NONE = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4};
struct node {
    int y;
    int x;
    int cost;
    DIR prevDIR = NONE;
    node(int cy, int cx, int curCost, DIR CUR) {
        y = cy;
        x = cx;
        cost = curCost;
        prevDIR = CUR;
    }
};

int BFS(vector<vector<int>> board) {
    int curY = 0, curX = 0, n = board.size();
    int answer = COSTMAX;
    queue<node> q;
    q.push(node(curY, curX, 0, NONE));
    cost[curY][curX] = 0;
    while (!q.empty()) {
        node current = q.front(); q.pop();
        int curCost = current.cost;
        //DOWN
        if (current.y < n-1 && !board[current.y+1][current.x]) {
            int nextCost = curCost;
            
            if (current.prevDIR == LEFT || current.prevDIR == RIGHT) {
                nextCost += CURVE;
            } else {
                nextCost += STRAIGHT;
            }
            if (cost[current.y+1][current.x] >= nextCost) {
                cost[current.y+1][current.x] = nextCost;
                q.push(node(current.y+1, current.x, nextCost, DOWN));
            }
        }
        //UP
        if (current.y > 0 && !board[current.y-1][current.x]) {
            int nextCost = curCost;
            if (current.prevDIR == LEFT || current.prevDIR == RIGHT) {
                nextCost += CURVE;
            } else {
                nextCost += STRAIGHT;
            }
            if (cost[current.y-1][current.x] >= nextCost) {
                cost[current.y-1][current.x] = nextCost;
                q.push(node(current.y-1, current.x, nextCost, UP));
            }
        }
        //LEFT
        if (current.x > 0 && !board[current.y][current.x-1]) {
            int nextCost = curCost;
            if (current.prevDIR == UP || current.prevDIR == DOWN) {
                nextCost += CURVE;
            } else {
                nextCost += STRAIGHT;
            }
            if (cost[current.y][current.x-1] >= nextCost) {
                cost[current.y][current.x-1] = nextCost;
                q.push(node(current.y, current.x-1, nextCost, LEFT));
            }
        }
        //RIGHT
        if (current.x < n-1 && !board[current.y][current.x+1]) {
            int nextCost = curCost;
            if (current.prevDIR == UP || current.prevDIR == DOWN) {
                nextCost += CURVE;
            } else {
                nextCost += STRAIGHT;
            }
            if (cost[current.y][current.x+1] >= nextCost) {
                cost[current.y][current.x+1] = nextCost;
                q.push(node(current.y, current.x+1, nextCost, RIGHT));
            }
        }
    }
    return cost[n-1][n-1] * 100;
}

int solution(vector<vector<int>> board) {
    int answer = BFS(board);
    
    return answer;
}


/*
- 오답원인
현재 위치의 비용을 항상 board[y][x] 값으로 했었는데 
board[y][x]는 항상 최소값만 저장하므로 현재 위치에 대한 비용이
최소값으로 덮어씌워지게 된다. 따라서 다른 경로로 동시에 어떤 위치에 도달했을 때
두 경로의 비용이 최소값으로 바뀌게 되는 것이었다.
- 문제오류
현재 위치의 최소비용이 전체 경로에 대한 최소비용을 보장해주지 않음.
*/