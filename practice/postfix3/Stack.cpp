/*
 * Stack.cpp
 *
 *  Created on: 2018. 4. 6.
 *      Author: harry
 */
#include <iostream>
#include <cstdio>
#include "Stack.h"
using namespace std;
typedef int ItemType;
Stack::Stack() // 스택 생성자
{
	topPtr = NULL;
}
Stack::~Stack()
{
	Node *tempPtr;
	while(topPtr!=NULL){
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
} // 스택 소멸자
bool Stack::isEmpty()
{
	return topPtr == NULL;
}

void Stack::push(ItemType item) // 맨 위에 항목 삽입
{
	Node *newNode;
	newNode = new Node;
	newNode->info = item;
	newNode->next = topPtr;
	topPtr = newNode;
}
ItemType Stack::pop() // 맨 위의 요소를 삭제하고 반환
{
	if (isEmpty()) {
		cout << "Error: the stack is empty" << endl;
		exit(1);
	}
	else{
		ItemType item;
		Node *tempPtr;
		tempPtr = topPtr;
		item = tempPtr->info;
		topPtr = topPtr->next;
		delete tempPtr;
		return item;
	}

}
ItemType Stack::peek() // 삭제하지 않고 요소 반환
{
	if (isEmpty()) { // error ("스택 비어있음 오류");
		cout << "스택 비어있음 오류" << endl;
		exit(1);
	}
	else
		return topPtr->info;
}
void Stack::display() // 스택 내용을 화면에 출력
{
	Node *location = topPtr;
	cout << "[스택 항목들] : ";
	while(location != NULL){
		cout << "<" << location->info << "> ";
		location = location->next;
	}
}



