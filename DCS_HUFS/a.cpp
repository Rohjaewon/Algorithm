#include <string>
#include <iostream>
#include <vector>
using namespace std;

int ROW, COL;
vector<vector<int> > check(1001, vector<int>(1001, 0));
vector<vector<int> > memorizing(1001, vector<int>(1001, -1));
int min_value = 999999999;
int min(int a, int b, int c, int d) {
   if (a < b) {
      if (c < d) {
         if (a < c) {
            return a;
         }
         else {
            return c;
         }
      }
      else {  //dc
         if (a < d) {
            return a;
         }
         else {
            return d;
         }
      }
   }
   else {
      if (c < d) {
         if (b < c) {
            return b;
         }
         else {
            return c;
         }
      }
      else {//  ba  dc
         if (b < d) {
            return b;
         }
         else {
            return d;
         }
      }
   }
}
bool range(int x, int y) {
   if (x < 0 || x >= ROW || y < 0 || y >= COL) {
      return false;
   }
   return true;
}
int DFS(vector<vector<char> > board, int x, int y, int hammer, int cnt) {
//    cout << x << "  " << y << endl;
   if (memorizing[x][y] != -1) { return memorizing[x][y]; }
   if (cnt > min_value) { return 999999999; }
   if (x == ROW - 1 && y == COL - 1) {
      if (min_value > cnt) { min_value = cnt; }
      return cnt;
   }
   int right = 999999999, left = 999999999, up = 999999999, down = 999999999;
   if (range(x, y + 1)) {  //오른쪽
      if (check[x][y + 1] == 0) {
         if (board[x][y + 1] == '0') {
            check[x][y + 1] = 1;
            right = DFS(board, x, y + 1, hammer, cnt + 1);
            check[x][y + 1] = 0;
         }
         else {
            if (hammer != 0) {
               check[x][y + 1] = 1;
               right = DFS(board, x, y + 1, hammer - 1, cnt + 1);
               check[x][y + 1] = 0;
            }
         }
      }
   }
   if (range(x + 1, y)) {  //아래쪽
      if (check[x + 1][y] == 0) {
         if (board[x + 1][y] == '0') {
            check[x + 1][y] = 1;
            down = DFS(board, x + 1, y, hammer, cnt + 1);
            check[x + 1][y] = 0;
         }
         else {
            if (hammer != 0) {
               check[x + 1][y] = 1;
               down = DFS(board, x + 1, y, hammer - 1, cnt + 1);
               check[x + 1][y] = 0;
            }
         }
      }
   }
   if (range(x, y - 1)) {  //왼쪽
      if (check[x][y - 1] == 0) {
         if (board[x][y - 1] == '0') {
            check[x][y - 1] = 1;
            left = DFS(board, x, y - 1, hammer, cnt + 1);
            check[x][y - 1] = 0;
         }
         else {
            if (hammer != 0) {
               check[x][y - 1] = 1;
               left = DFS(board, x, y - 1, hammer - 1, cnt + 1);
               check[x][y - 1] = 0;
            }
         }
      }
   }
   if (range(x - 1, y)) {  //위로
      if (check[x - 1][y] == 0) {
         if (board[x - 1][y] == '0') {
            check[x - 1][y] = 1;
            up = DFS(board, x - 1, y, hammer, cnt + 1);
            check[x - 1][y] = 0;
         }
         else {
            if (hammer != 0) {
               check[x - 1][y] = 1;
               up = DFS(board, x - 1, y, hammer - 1, cnt + 1);
               check[x - 1][y] = 0;
            }
         }
      }
   }
   memorizing[x][y] = min(up, down, left, right);
   if (memorizing[x][y] == 999999999) { memorizing[x][y] = -1; }
   return memorizing[x][y];
}
int main() {

   int row, col;
   cin >> row >> col;
   ROW = row; COL = col;

   vector<vector<char> > board(row, vector<char>(col, '0'));
   char temp = 0;
   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        //  cin >> temp;
        temp = '0';
        board[i][j] = temp;
      }
   }
   check[0][0] = 1;
   DFS(board, 0, 0, 1, 1);
   if (min_value == 9999999) {
      cout << "-1" << endl;
   }
   else {
      cout << min_value << endl;
   }

}