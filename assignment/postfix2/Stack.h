/*
 * Stack.h
 *
 *  Created on: 2018. 4. 5.
 *      Author: harry
 */

#ifndef STACK_H_
#define STACK_H_
typedef int ItemType;
class Stack {
public:
	Stack(); // 스택 생성자
	~Stack(); // 스택 소멸자
	bool isEmpty();
	bool isFull();
	void push(ItemType item); // 맨 위에 원소 삽입
	ItemType pop(); // 맨 위의 원소를 삭제하고 반환
	ItemType peek(); // 삭제하지 않고 원소 반환
	void display(); // 스택 원소들을 위에서부터 차례대로 내용을 출력
private:
	int top; // 스택에서 가장 위에 있는 원소의 위치
	ItemType *data; // 원소들을 저장하는 배열
	int MAX_SIZE;
};




#endif /* STACK_H_ */
