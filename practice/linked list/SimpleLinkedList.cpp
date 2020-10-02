/*
 * SimpleLinkedList.cpp
 *
 *  Created on: 2018. 3. 30.
 *      Author: harry
 */
#include "SimpleLinkedList.h"
#include <iostream>
using namespace std;
SimpleLinkedList::SimpleLinkedList()
{
	head = NULL;
	last = NULL;
}
SimpleLinkedList::~SimpleLinkedList()
{
	Node* temp = NULL;
	while(head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}

}
void SimpleLinkedList::insertBefore(int insertvalue)
{
	Node *temp = new Node;
	temp->value = insertvalue;
	temp->next = head;
	if(head == NULL){
		head = temp;
		last = temp;
	}
	else
		head = temp;
}
void SimpleLinkedList::insertAfter(int insertvalue){
	Node *temp = new Node;
	temp->value = insertvalue;
	temp->next = NULL;
	if(last != NULL){
		last->next = temp;
		last = temp;
	}
	else {
		head = temp;
		last = temp;
	}
}
void SimpleLinkedList::removeBefore() {
	Node* temp;
	temp = head;
	head = head->next;
	if(head == NULL){
		last = NULL;
	}
	delete temp;
	cout << "Remove success!" << endl;
}

void SimpleLinkedList::removeAfter(){
	Node* temp;
	Node* temp2;
	temp = head;
	temp2 = last;
	while(temp->next != last){
		temp = temp->next;
		cout << temp->value << endl;
	}
	last = temp;
	delete temp2;
	cout << "Remove success!" << endl;
}
int SimpleLinkedList::getLast(){
	return last->value;
}
void SimpleLinkedList::printAll() const
{
	Node* temp = head;
	while(temp != NULL){
		cout << temp->value << endl;
		temp = temp->next;
	}
}
