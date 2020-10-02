/*
 * main.cpp
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */
#include <iostream>
#include "UnsortedList.h"
using namespace std;
int main() {
   UnsortedList L;
   string command;
   Node book;
   while (1) {
      cin >> command;
      if (command == "Q") //루프빠져나가고 종료
         break;
      else if (command == "N") {
         cin >> book.bookID >> book.bookName >> book.price >> book.num;
         L.insertItem(book);
      }
      else if (command == "S") {
         cin >> book.bookID >> book.num;
         L.sell(book.bookID, book.num);
      }
      else if (command == "E") {
         cin >> book.bookID >> book.num;
         L.get(book.bookID, book.num);
      }
      else if (command == "R") {
         cin >> book.bookID;
         L.find(book.bookID);
      }
      else if (command == "D") {
         string bookID; cin >> bookID;
         L.deleteItem(bookID);
      }
   }//while
   return 0;
}



