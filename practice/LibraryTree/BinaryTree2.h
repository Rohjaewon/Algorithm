/*
 * UnsortedList.h
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */

#ifndef BINARYTREE2_H_
#define BINARYTREE2_H_
#include <iostream>

#include "TreeNode.h"
using namespace std;

class BinaryTree2 {
public:
	BinaryTree2();
	~BinaryTree2();
	void Destroy(TreeNode* ptr); //소멸자
	void insertItem(Book book); //책 정보 입력
	void insert(TreeNode* &ptr, Book book); //책 정보 입력 재귀
	void GetItem(string id, int num); //책 입고
	void SellItem(string id, int num); //책 판매
	void sell(TreeNode* ptr, string id, int num); // 책 판매 재귀
	void showItem(); //판매수량이 가장 많은 책 정보 출력
	int show(TreeNode* ptr); //가장 많은 판매수량을 찾고 반환
	void print_s(TreeNode* ptr, int num); //가장 많은 판매수량과 같은 판매수량을 가지고 있는 책 정보를
										  //책번호 오름차순으로 출력
private:
	TreeNode *root;
	int amount;
};

#endif /* BINARYTREE_H_ */
