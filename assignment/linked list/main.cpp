/*
 * main.cpp
 *
 *  Created on: 2018. 3. 30.
 *      Author: harry
 */
#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

int main()
{
	SimpleLinkedList L;
	L.insertAfter(40);
	L.insertAfter(20);
	L.insertBefore(30);
	L.insertAfter(10);

	L.printAll();

	cout << "마지막 노드의 값 : " << L.getLast() << endl;

	L.removeAfter();
	L.removeAfter();

	L.printAll();
	return 0;
}



