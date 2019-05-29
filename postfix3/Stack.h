/*
 * Stack.h
 *
 *  Created on: 2018. 4. 6.
 *      Author: harry
 */

#ifndef STACK_H_
#define STACK_H_
#include "Node.h"
typedef int ItemType;
class Stack {
public:
	Stack(); // 스택 생성자
	Stack(int size);
	~Stack(); // 스택 소멸자
	bool isEmpty();
	void push(ItemType item); // 맨 위에 원소 삽입
	ItemType pop(); // 맨 위의 원소를 삭제하고 반환
	ItemType peek(); // 삭제하지 않고 원소 반환
	void display(); // 스택 원소들을 위에서부터 차례대로 내용을 출력
private:
	Node *topPtr;
};




#endif /* STACK_H_ */
