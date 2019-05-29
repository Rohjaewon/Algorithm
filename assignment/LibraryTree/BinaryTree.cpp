/*
 * UnsortedList.cpp
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */
#include "BinaryTree.h"

#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
	amount = 0;
}
BinaryTree::~BinaryTree() {
	Destroy(root);
}

void BinaryTree::Destroy(TreeNode* ptr) { //소멸자 재귀함수
	if (ptr != NULL) {
		Destroy(ptr->leftchild);
		Destroy(ptr->rightchild);
		delete ptr;
	}
}

void BinaryTree::insertItem(Book book) {
	insert(root, book);
}

void BinaryTree::insert(TreeNode* &ptr, Book book) { //신규도서 추가 재귀함수
	if (ptr == NULL) {
		ptr = new TreeNode;
		ptr->leftchild = NULL;
		ptr->rightchild = NULL;
		ptr->book = book;
		amount++;
	} else {
		if (ptr->book.getID() > book.getID()) {
			insert(ptr->leftchild, book);
		} else if (ptr->book.getID() < book.getID()) {
			insert(ptr->rightchild, book);
		} else { //기존의 같은 도서번호가 있으면 error1
			cout << "error: 1" << endl;
		}
	}

}

void BinaryTree::removeItem(string id) {
	remove(root, id);
}

void BinaryTree::remove(TreeNode* &ptr, string id) { //도서 삭제 재귀함수
	if (ptr == NULL) { //삭제할 도서가 목록에 없으면 error: 5
		cout << "error: 5" << endl;
	} else {
		if (ptr->book.getID() > id)
			remove(ptr->leftchild, id);
		else if (ptr->book.getID() < id)
			remove(ptr->rightchild, id);
		else {
			TreeNode* tempPtr;
			if (ptr->leftchild == NULL) {
				tempPtr = ptr;
				ptr = ptr->rightchild;
				delete tempPtr;
			} else if (ptr->rightchild == NULL) {
				tempPtr = ptr;
				ptr = ptr->leftchild;
				delete tempPtr;
			} else {
				tempPtr = ptr->rightchild;
				while (tempPtr->leftchild != NULL)
					tempPtr = tempPtr->leftchild;
				ptr->book = tempPtr->book;
				remove(ptr->rightchild, ptr->book.getID());
			}
		}
		amount--;
	}
}

void BinaryTree::GetItem(string id, int num) { //도서 입고 함수
	TreeNode* ptr = root;

	while (ptr != NULL) {
		if (ptr->book.getID() > id)
			ptr = ptr->leftchild;
		else if (ptr->book.getID() < id)
			ptr = ptr->rightchild;
		else
			break;
	}
	if (ptr == NULL) { //입고할 도서가 목록에 없으면 error 2
		cout << "error: 2" << endl;
	} else {
		ptr->book.getnum(num);
	}
}

void BinaryTree::SellItem(string id, int num) {
	sell(root, id, num);
}

void BinaryTree::sell(TreeNode* ptr, string id, int num) { //도서 판매
	if (ptr == NULL) { // 판매할 도서가 목록에 없으면 error: 3
		cout << "error: 3" << endl;
	} else {
		if (ptr->book.getID() > id)
			sell(ptr->leftchild, id, num);
		else if (ptr->book.getID() < id)
			sell(ptr->rightchild, id, num);
		else {
			if (ptr->book.getNum() < num)
				cout << "error: 4" << endl;
			else
				ptr->book.sellnum(num);
		}
	}
}

void BinaryTree::searchItem(string id) {
	return search(root, id);
}

void BinaryTree::search(TreeNode* ptr, string id) { //도서조회
	if (ptr == NULL) { //조회할 도서가 목록에 없으면 error: 2
		cout << "error: 2" << endl;
	} else {
		if (ptr->book.getID() > id)
			search(ptr->leftchild, id);
		else if (ptr->book.getID() < id)
			search(ptr->rightchild, id);
		else {
			cout << ptr->book.getID() << " " << ptr->book.getName() << " "
					<< ptr->book.getPrice() << " " << ptr->book.getNum()
					<< endl;
		}
	}
}

void BinaryTree::printItem() {
	print(root);
}

void BinaryTree::print(TreeNode *ptr) { //도서번호의 오름차순으로 출력하는 함수
	if (ptr != NULL) {
		print(ptr->leftchild);
		cout << ptr->book.getID() << " " << ptr->book.getName() << " "
				<< ptr->book.getPrice() << " " << ptr->book.getNum() << " "
				<< ptr->book.getSell() << " " << ptr->book.getGet() << endl;
		print(ptr->rightchild);
	}
}

