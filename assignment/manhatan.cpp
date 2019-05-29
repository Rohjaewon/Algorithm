/*
 * algo_2-3.cpp
 *
 *  Created on: 2018. 9. 26.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct point{
	int x=0;//점들의 x좌표
	int flag=0;//1번 선의 점인지 2번 선의 점인지 구별
} point;
bool compare(point left, point right){
	return left.x < right.x;
}

int main() {
	srand((int)time(0));
	int num1, num2; // 1번, 2번 선위에 있는 점의 개수
	int y1, y2; //1번, 2번 선의 y값
	cin >> num1 >> num2;
	//num1 = rand()%10+1; num2 = rand()%10+1;
	cin >> y1 >> y2;
	//y1 = rand()%100000; y2 = rand()%100000;
	cout << "num1 : " << num1 << " num2 : "<< num2 << endl;
	cout << "y1 : " << y1 << " y2 : "<< y2 << endl;
	int ny = y1 - y2; if (ny < 0) ny *= -1; // y값의 차이의 절대값
	int minlength = numeric_limits<int>::max();//처음에 minlength를 int의 최대값으로 초기화
	int minNum = 0;//최소길이가 같은 접쌍의 개수
	int len = 0;//점 사이의 길이를 임시 저장하는 변수
	vector<point> arr1(num1);///1번 선 위에 점들을 저장하기 위한 vector
	vector<point> arr2(num2);///2번 선 위에 점들을 저장하기 위한 vector
	for (int i = 0; i < num1; i++){//1번 선 위에 점들의 x좌표 입력
		cin >> arr1[i].x;
		//arr1[i].x = rand()%100000;
		arr1[i].flag = 1;
	}

	for (int i = 0; i < num2; i++) {//2번 선 위에 점들의 x좌표 입력
		cin >> arr2[i].x;
		//arr2[i].x = rand()%100000;
		arr2[i].flag = 2;
	}


	if(arr1.size() == 0 || arr2.size() == 0){
		minlength = 0; minNum = 0;
	}
	else {
		for (int i = 0; i < num1; i++)
			arr2.push_back(arr1[i]);
		sort(arr2.begin(), arr2.end(), compare); //x값의 오름차순으로 정렬

		for (int i = 0; i < num1 + num2 - 1; i++) {
			if (arr2[i].flag != arr2[i + 1].flag) { // 서로 다른 선 위에 있는 점끼리만 값 비교
				len = arr2[i + 1].x - arr2[i].x;
				if(len<0) len *= -1;
				if (minlength > len) { //새로운 최소길이가 나타났을 경우
					minlength = len;
					minNum = 1;
				} else if (minlength == len) //기존의 최소길이와 같은 길이가 나타났을 경우
					minNum++;
			}
		}
	}
	minlength += ny;
	cout << minlength << " " << minNum<< endl;
	return 0;
}
*/



