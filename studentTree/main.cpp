/*
 * main.cpp
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */
#include <iostream>

#include "StudentTree.h"

using namespace std;

int main() {
	StudentTree stTree;
	Student st;
	string id;
	string name;
	string dept;
	int grade;
	string command;

	while (cin >> command) {
		if (command == "Q") // 프로그램 종료
			break;
		if (command == "N") { //수강자 정보입력
			cin >> id >> name >> dept >> grade;
			st.set(id, name, dept, grade);
			stTree.insertItem(st);
		} else if (command == "W") { // 수강자 정보 삭제
			cin >> id;
			stTree.removeItem(id);
		} else if (command == "R") { // 수강자 정보 조회
			cin >> id;
			stTree.searchItem(id);
		} else if (command == "C") { // 수강자 정보 수정
			cin >> id >> name >> dept >> grade;
			st.set(id, name, dept, grade);
			stTree.correctItem(st);
		} else if (command == "P") { //수강자 학번 오름차순으로 출력
			stTree.printItem();
		} else if(command == "H"){
			cout << stTree.Height() << endl;
		}
	}
	return 0;
}

