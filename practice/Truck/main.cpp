/*
 * main.cpp
 *
 *  Created on: 2018. 5. 3.
 *      Author: harry
 */
#include <iostream>
#include "CircularQ.h"
using namespace std;
/*
bool Howheavy(CircularQ qq, int L, int index) { //최대 적재하중 비교 작거나 같으면 true 크면 false반환
	int sum = 0;
	for (int j = 0; j <= index; j++) {
		cout << qq.getweight(j) << endl;
		sum += qq.getweight(j);
	}
	if (sum <= L)
		return true;
	else
		return false;
}*/

int main() {
	int n, w, L; //트럭의 수, 다리 길이, 다리의 최대 하중
	int time = 0; // 총 걸리는 시간
	int index = 0;//트럭 무게의 합산에 따라 혼자 이동할지 같이 이동할지 결정
	bool flag = false;//여러 개의 트럭이 같이 지나갈 때 time을 여러 번 증가하지 않고 1만 증가시키도록 해주는 변수
	cin >> n >> w >> L;
	CircularQ q(n);
	for (int i = 0; i < n; i++) {
		Truck tr; //트럭;
		cin >> tr.weight;
		q.enqueue(tr);

	}
	while (1) {
		if (q.isEmpty()) //트럭이 다 통과하면 빠져나옴
			break;
		flag = true;

		int sum = 0;
		for (int j = 0; j <= index; j++) {
			sum += q.getweight(j);
		}

		if (sum <= L) {
			for (int k = 0; k <= index; k++) {
				if (q.move(k, w)) { //다리를 빠져나갔을 때
					if (!q.isEmpty()) { //마지막 트럭이 나갈 때는 time증가
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				time++;
				cout << "---------------" << endl;
				if (!q.willEmpty()) {
					index++;
				}
			}
			if (index >= w || index >= q.Qsize())
				index--;
		} // sum <= L

		else {
			for (int z = 0; z < index; z++) {
				if (q.move(z, w)) {
					flag = false;
					index--;
					break;
				}
			}
			if (flag) {
				time++;
				cout << "---------------" << endl;
			}
		} //sum > L
	} //while
	cout << time << endl;
} //main

