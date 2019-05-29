/*
 * UnsortedList.cpp
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */
#include <iostream>
#include "UnsortedList.h"
using namespace std;

UnsortedList::UnsortedList() {
   head = NULL;
   last = NULL;
   amount = 0;
}
UnsortedList::~UnsortedList() {
   Node* temp;
   while (head != NULL) {
      temp = head;
      head = head->link;
      delete temp;
   }
}
void UnsortedList::insertItem(Node ptr) {


   if (search(ptr.bookID) != NULL) {//도서목록에 이미 있는 경우 "error: 1" 출력
      cout << "error: 1" << endl;
      //exit(0);
   }
	else{
	 	Node* temp = new Node;
   	temp->bookID = ptr.bookID;
   	temp->bookName = ptr.bookName;
   	temp->price = ptr.price;
   	temp->num = ptr.num;
   	if (head == NULL) {
       temp->link = head;
     	 head = temp;
   	}
   	else {
   	  temp->link = NULL;
			last->link = temp;
   	}
		last = temp;
   	amount++;
	}
}
bool UnsortedList::deleteItem(string str) {
   return remove(head, str);
}

bool UnsortedList::remove(Node* &ptr, string str) { //재귀적으로 삭제함수 구현
   if (ptr == NULL){//삭제하는데 도서목록이 비어있거나 목록에 없는 도서일 경우 "error: 5"
      cout << "error: 5" << endl;
		  return false;
      //exit(0);
	 }
   if (ptr->bookID == str) {
      Node* tempPtr = ptr;
      ptr = ptr->link;
      delete tempPtr;
      amount--;
      return true;
   }
   else
      return remove(ptr->link, str);
}
Node* UnsortedList::search(string str) {
   Node* temp = head;
   while (temp != NULL) {
      if (temp->bookID == str)
         break;
      temp = temp->link;
   }
   return temp;
}
void UnsortedList::find(string str) {
   Node* ptr = search(str);
   if (ptr == NULL) {//도서목록에 원하는 도서가 없으면 "error: 2"
      cout << "error: 2" << endl;
      //exit(0);
   }
   if (ptr != NULL)
      cout << ptr->bookID << " " << ptr->bookName << " " << ptr->price << " " << ptr->num << endl;
}
void UnsortedList::sell(string str, int num) {
   Node* temp = search(str);
   if (temp == NULL) {//도서목록에 팔고자하는 도서가 없으면 "error: 3"
      cout << "error: 3" << endl;
      //exit(0);
   }

   else {
      if (temp->num - num < 0) {//판매량이 재고량보다 많으면 "error: 4"
         cout << "error: 4" << endl;
         //exit(0);
      }
      else {
         temp->num -= num;
      }
   }
}
void UnsortedList::get(string str, int num) {
   Node* temp = search(str);
   if (temp == NULL) { //입고하려는데 도서목록에 없는 도서일 경우 "error: 2"
      cout << "error: 2" << endl;
      //exit(0);
   }
   else
      temp->num += num;
}



