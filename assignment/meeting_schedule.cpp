/*
 * algo_3-4.cpp
 *
 *  Created on: 2018. 10. 28.
 *      Author: harry
 */
/*
#include <iostream>
#include <algorithm>

using namespace std;
int n; //회의의 수

typedef struct point {
	int s; //회의 시작시간
	int f; //회의 끝나는 시간
	int w; //회의 가중치
} point;

bool Xcompare(point left, point right) { //회의 끝나는 시간 기준으로 오름차순 정렬
	return left.f < right.f;
}

int p2(point arr[], int left, int right, int j, int index) { //binary search로 안겹치는 회의 중 가장 늦게 끝나는 회의 찾기
															 //매개변수 index는 a[j].s와 같은 회의의 index혹은 a[j].s보다 작은 회의 가장 큰 회의의 index를 저장
	if (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid].f <= arr[j].s) {
			return p2(arr, mid + 1, right, j, mid);
		}
		else { //arr[mid].f > arr[j].s
			return p2(arr, left, mid - 1, j, index);
		}
	}
	else {//left > right
		return index;
	}
}


int p(point arr[], int j) {
	return p2(arr, 1, j - 1, j, 0);
}

int max(int left, int right) {
	if (left < right)
		return right;
	else
		return left;
}

int opt(point arr[], int i) {
	int *board = new int[i + 1];//board[i] = 1~i번째 회의까지 안겹치면서 가장 큰 가중치를 저장하는 배열
	for (int k = 0; k <= i; k++)
		board[k] = 0;
	for (int k = 1; k <= i; k++) {
		board[k] = max(board[k - 1], board[p(arr, k)] + arr[k].w); //k를 포함한 가중치와 제외한 가중치 중 더 큰 가중치로 지정
	}
	int answer = board[i];
	delete[] board;
	return answer;
}

int main() {
	cin >> n;
	int size = n + 1;
	point *arr = new point[size]; //회의 배열
	arr[0].f = arr[0].s = arr[0].w = 0; //0번째는 없는 경우로 설정
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].s >> arr[i].f >> arr[i].w; //index 1번부터 회의 값 저장
	}
	sort(arr, arr+size, Xcompare);
	cout << opt(arr, n) << endl;
	delete[] arr;
	return 0;
}
*/
