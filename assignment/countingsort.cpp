/*
 * algo_3-1.cpp
 *
 *  Created on: 2018. 10. 28.
 *      Author: harry
 */
/*
#include <iostream>
using namespace std;
int n = 0; //배열 크기

int max(int a[]) { //배열 중 가장 큰 원소 찾는 함수
	int temp = a[0];
	for (int i = 1; i < n; i++) {
		if (temp < a[i])
			temp = a[i];
	}
	return temp;
}

void Csort(int a[]) {
	int Max = max(a)+1;
	int C[Max] = { 0 }; //counting한 결과를 넣는 배열
	int B[n] = { 0 }; //counting 순서대로 넣는 배열 -> 최종 정렬 상태의 배열
	for (int i = 0; i < n; i++) {//원래 배열의 원소값 counting
		C[a[i]] += 1;
	}
	for (int i = 1; i < Max; i++) {//count를 누적
		C[i] += C[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {//누적 개수에 따라 B배열에 원소 삽입
		if (C[a[i]] > 0) {
			B[C[a[i]] - 1] = a[i];
			C[a[i]]--;
		}
	}
	for (int i = 0; i < n; i++)//원래 배열에 덮어쓰기
		a[i] = B[i];
}

int maxsum(int a[]){
		int sum = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] - sum >= 2) //i번째 원소와 1~i-1까지의 합이 2보다 크면 종료
				break;
			sum += a[i];
		}
		return sum;
}

int main() {
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		Csort(arr);
		cout << maxsum(arr);
}
*/
