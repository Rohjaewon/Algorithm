/*
 * UnsortedList.cpp
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */
#include "BinaryTree2.h"

#include <iostream>
using namespace std;

BinaryTree2::BinaryTree2() {
	root = NULL;
	amount = 0;
}
BinaryTree2::~BinaryTree2() {
	Destroy(root);
}

void BinaryTree2::Destroy(TreeNode* ptr) { //소멸자 재귀함수
	if (ptr != NULL) {
		Destroy(ptr->leftchild);
		Destroy(ptr->rightchild);
		delete ptr;
	}
}

void BinaryTree2::insertItem(Book book) {
	insert(root, book);
}

void BinaryTree2::insert(TreeNode* &ptr, Book book) { //신규도서 추가 재귀함수
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
		} else {
			ptr->book.resetnum(book.getNum());
		}
	}
}

void BinaryTree2::GetItem(string id, int num) { //도서 입고 함수
	TreeNode* ptr = root;

	while (ptr != NULL) {
		if (ptr->book.getID() > id)
			ptr = ptr->leftchild;
		else if (ptr->book.getID() < id)
			ptr = ptr->rightchild;
		else
			break;
	}
	if (ptr != NULL)
		ptr->book.getnum(num);
}

void BinaryTree2::SellItem(string id, int num) {
	sell(root, id, num);
}

void BinaryTree2::sell(TreeNode* ptr, string id, int num) { //도서 판매
	if (ptr != NULL) {
		if (ptr->book.getID() > id)
			sell(ptr->leftchild, id, num);
		else if (ptr->book.getID() < id)
			sell(ptr->rightchild, id, num);
		else {
			if (ptr->book.getNum() >= num)
				ptr->book.sellnum(num);
		}
	}
}
void BinaryTree2::showItem() {
	int num = show(root);
	print_s(root, num);
}

void BinaryTree2::print_s(TreeNode* ptr, int num) { //가장 큰 판매수량인 도서를 도서번호의 오름차순으로 출력하는 함수
	if (ptr != NULL) {
		print_s(ptr->leftchild, num);
		if (ptr->book.getSell() == num)
			cout << ptr->book.getID() << " " << ptr->book.getName() << " "
					<< ptr->book.getSell() << endl;
		print_s(ptr->rightchild, num);
	}
}

int BinaryTree2::show(TreeNode* ptr) { //가장 큰 판매수량 찾는 함수
	if (ptr == NULL)
		return 0;
	int leftnum = show(ptr->leftchild);
	int rightnum = show(ptr->rightchild);
	int rootnum = ptr->book.getSell();
	if (rootnum > leftnum && rootnum > rightnum)
		return rootnum;
	else if (leftnum > rootnum && leftnum > rightnum)
		return leftnum;
	else if (rightnum > rootnum && rightnum > leftnum)
		return rightnum;
	else
		return rootnum;
}

