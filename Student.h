/*
 * Student.h
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
using namespace std;

class Student {
public:
	void set(string id, string name, string dept, int grade) {
		this->id = id;
		this->name = name;
		this->dept = dept;
		this->grade = grade;
	}
	string getID() {
		return id;
	}
	string getName() {
		return name;
	}
	string getDept() {
		return dept;
	}
	int getGrade() {
		return grade;
	}
private:
	string id;  //학번
	string name;  //이름
	string dept;  //학과
	int grade;  //학년
};




#endif /* STUDENT_H_ */
