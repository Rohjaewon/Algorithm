/*
 * UnsortedList.h
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */

#ifndef UNSORTEDLIST_H_
#define UNSORTEDLIST_H_
#include <iostream>
#include "Node.h"
using namespace std;

class UnsortedList {
private:
   Node* head;
   Node* last;
   int amount;
public:
   UnsortedList();
   ~UnsortedList();
   void insertItem(Node ptr); // "N" 신규도서추가
   bool deleteItem(string str); // "D" 기존 도서목록에서 삭제
   bool remove(Node* &ptr, string str); //삭제를 재귀적으로 구현
   Node* search(string str); //find, sell, get에 search기능을 넣어줌
   void find(string ptr); // "R" 도서 조회
   void sell(string str, int num); // "S" 도서 판매
   void get(string str, int num); // "E" 도서 입고
};


#endif /* UNSORTEDLIST_H_ */
