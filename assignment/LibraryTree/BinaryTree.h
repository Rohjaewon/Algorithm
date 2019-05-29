/*
 * UnsortedList.h
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>

#include "TreeNode.h"
using namespace std;

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	void Destroy(TreeNode* ptr); //소멸자
	void insertItem(Book book); //책 정보 입력
	void insert(TreeNode* &ptr, Book book); //책 정보입력 재귀
	void removeItem(string id); //책 정보 삭제
	void remove(TreeNode* &ptr, string id); //책 정보 삭제재귀
	void GetItem(string id, int num); //책 입고
	void SellItem(string id, int num); //책 판매
	void sell(TreeNode* ptr, string id, int num); //책 판매 재귀
	void searchItem(string id); //책 정보 조회
	void search(TreeNode* ptr, string id); //책 정보 조회 재귀
	void printItem(); //책 번호 오름차순으로 출력
	void print(TreeNode* ptr); //책 번호 오름차순으로 출력 재귀
private:
	TreeNode *root;
	int amount;
};

#endif /* BINARYTREE_H_ */
