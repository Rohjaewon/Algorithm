/*
 * algo_3-3.cpp
 *
 *  Created on: 2018. 10. 28.
 *      Ajthor: harry
 */
/*
#include <iostream>
using namespace std;
int n;

int min(int left, int right) {//왼쪽과 오른쪽 중 작은거 반환
	if (left > 0 && right > 0)
		return left < right ? left : right;
	//둘 중 하나면 0보다 크다면 그 값을 반환한다
	else if (left <= 0 && right > 0)
		return right;
	else if (left > 0 && right <= 0)
		return left;
	else {//불가능한 경우와 0개인 경우가 동시에 발생했다는 것은 결국엔 불가능한 경우이다
		if (left == -1 || right == -1)
			return -1;
		else return 0;
	}
}

int Count(int C[], int M) {
	int **B = new int*[M + 1];//B[a][b]일 때 a를  1~b의 단위 동전으로 만들 때 최소 동전의 수를 저장
	for (int k = 0; k <= M; k++)
		B[k] = new int[n + 1];
	for (int k = 0; k <= M; k++)
		for (int u = 0; u <= n; u++)
			B[k][u] = 0;
	int i, j;
	for (i = 0; i <= M; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0)//단위 동전이 없거나 거스름돈이 없으면 동전 수는 0개
				B[i][j] = 0;
			else if (j == 0)//j가 없을 땐 아예 불가능하므로 -1
				B[i][j] = -1;
			else if (i < C[j])//어떤 동전의 단위가 거스름돈보다 크다면 그 단위는 제외
				B[i][j] = B[i][j - 1];
			else {//거스름돈 i를 1~j까지 단위 동전으로 만들 때 j를 포함한 동전 수와 그렇지 않은 동전 수 중 작은 값을 저장
				B[i][j] = min(B[i - C[j]][j] + 1, B[i][j - 1]);
			}
		}
	}
	int answer = B[M][n];
	for (int k = 0; k <= M; k++)
		delete[] B[k];
	if (answer == 0)
		answer = -1;
	return answer;
}

int main() {
	cin >> n;;
	int *C = new int[n + 1];//동전 단위 배열
	int M;//거스름돈
	C[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> C[i];
	cin >> M;

	cout << Count(C, M) << endl;
	delete[]C;
	return 0;
}*/



