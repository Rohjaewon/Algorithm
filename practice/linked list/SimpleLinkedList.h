/*
 * SimpleLinkedList.h
 *
 *  Created on: 2018. 3. 30.
 *      Author: harry
 */

#ifndef SIMPLELINKEDLIST_H_
#define SIMPLELINKEDLIST_H_
#include "Node.h"

class SimpleLinkedList
{
private:
	Node* head;
	Node* last;
public:
	SimpleLinkedList();
	~SimpleLinkedList();
	void insertBefore(int insertvalue);
	void insertAfter(int insertvalue);
	void removeBefore();
	void removeAfter();
	int getLast();
	void printAll() const;
};

#endif /* SIMPLELINKEDLIST_H_ */
