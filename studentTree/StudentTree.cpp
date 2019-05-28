/*
 * StudentList.cpp
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */
#include <iostream>
#include <string>

#include "StudentTree.h"
using namespace std;

StudentTree::StudentTree() {
	head = NULL;
	length = 0;
}
StudentTree::~StudentTree() {
	Destroy(head);
}

void StudentTree::Destroy(TreeNode* ptr) {
	if (ptr != NULL) {
		Destroy(ptr->leftchild);
		Destroy(ptr->rightchild);
		delete ptr;
	}
}

void StudentTree::insertItem(Student st) {
	insert(head, st);
}

void StudentTree::insert(TreeNode* &ptr, Student st) {
	if (ptr == NULL) {
		ptr = new TreeNode;
		ptr->leftchild = NULL;
		ptr->rightchild = NULL;
		ptr->data = st;
		length++;
	} else {
		if (ptr->data.getID() > st.getID()) {
			cout << "root " << ptr->data.getID() << "의 왼쪽" << endl;
			insert(ptr->leftchild, st);
		} else if (ptr->data.getID() < st.getID()) {
			cout << "root " << ptr->data.getID() << "의 오른쪽" << endl;
			insert(ptr->rightchild, st);
		}
	}

}

void StudentTree::removeItem(string id) {
	remove(head, id);
}

void StudentTree::remove(TreeNode* &ptr, string id) {
	if (ptr->data.getID() > id)
		remove(ptr->leftchild, id);
	else if (ptr->data.getID() < id)
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
			ptr->data = tempPtr->data;
			remove(ptr->rightchild, ptr->data.getID());
		}
	}
	length--;
}

void StudentTree::correctItem(Student st) {
	correction(head, st);
}

void StudentTree::correction(TreeNode* ptr, Student st) {
	if (ptr->data.getID() > st.getID())
		correction(ptr->leftchild, st);
	else if (ptr->data.getID() < st.getID())
		correction(ptr->rightchild, st);
	else {
		ptr->data.set(st.getID(), st.getName(), st.getDept(), st.getGrade());
	}
}

void StudentTree::searchItem(string id) {
	return search(head, id);
}

void StudentTree::search(TreeNode* ptr, string id) {
	if (ptr->data.getID() > id)
		search(ptr->leftchild, id);
	else if (ptr->data.getID() < id)
		search(ptr->rightchild, id);
	else {
		cout << ptr->data.getID() << " " << ptr->data.getName() << " "
				<< ptr->data.getDept() << " " << ptr->data.getGrade() << endl;
	}
}

void StudentTree::printItem() {
	print(head);
}

void StudentTree::print(TreeNode *ptr) {
	if (ptr != NULL) {
		print(ptr->leftchild);
		cout << ptr->data.getID() << " " << ptr->data.getName() << " "
				<< ptr->data.getDept() << " " << ptr->data.getGrade() << endl;
		print(ptr->rightchild);
	}
}

int StudentTree::Height(){
	return getHeight(head);
}

int StudentTree::getHeight(TreeNode* ptr){
	if(ptr == NULL) return 0;
	else{
		int hleft = getHeight(ptr->leftchild);
		int hright = getHeight(ptr->rightchild);
		return (hleft>hright) ? hleft+1 : hright+1;
	}
}

