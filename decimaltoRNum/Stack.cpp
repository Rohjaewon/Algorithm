#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() // 스택 생성자
{
	top = -1;
}
Stack::~Stack() {} // 스택 소멸자
bool Stack::isEmpty()
{
	return top == -1;
}
bool Stack::isFull()
{
	return top == MAX_STACK_SIZE - 1;
}

void Stack::push(ItemType item) // 맨 위에 항목 삽입
{
	if (isFull()) {
		cout << "Error: the stack is full" << endl;
		exit(1);
	}
	data[++top] = item;
}
ItemType Stack::pop() // 맨 위의 요소를 삭제하고 반환
{
	if (isEmpty()) {
		cout << "Error: the stack is empty" << endl;
		exit(1);
	}
	return data[top--];
}
ItemType Stack::peek() // 삭제하지 않고 요소 반환
{
	if (isEmpty()) { // error ("스택 비어있음 오류");
		cout << "스택 비어있음 오류" << endl;
		exit(1);
	}
	return data[top];
}
void Stack::display() // 스택 내용을 화면에 출력
{
	printf("[스택 항목의 수 = %2d] ==> ", top + 1);
	for (int i = 0; i <= top; i++)
		printf("<%2d>", data[i]);
	printf("\n");
}
