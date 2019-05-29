/*
 * main.cpp
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */
#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree2.h"
using namespace std;
int main(){
	BinaryTree btTree;//현재 도서 목록
	BinaryTree2 origin;//폐기된 도서까지 포함된 도서목록
	Book book;
	string id;
	string name;
	int price;
	int num;
	string command;

	while (cin >> command) {
		if (command == "Q")
			break;
		if (command == "N") {
			cin >> id >> name >> price >> num;
			book.set(id, name, price, num);
			btTree.insertItem(book);
			origin.insertItem(book);
		} else if (command == "E") {
			cin >> id >> num;
			btTree.GetItem(id, num);
		} else if (command == "S") {
			cin >> id >> num;
			btTree.SellItem(id, num);
			origin.SellItem(id, num);
		} else if (command == "D") {
			cin >> id;
			btTree.removeItem(id);
		} else if (command == "R") {
			cin >> id;
			btTree.searchItem(id);
		} else if (command == "B") {
			origin.showItem();
		} else if( command == "L") {
			btTree.printItem();
		}
	}
	return 0;
}



