/*
 * StudentList.h
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */

#ifndef STUDENTTREE_H_
#define STUDENTTREE_H_
#include <iostream>
#include <string>

#include "TreeNode.h"
using namespace std;

class StudentTree {
public:
	StudentTree();
	~StudentTree();
	void Destroy(TreeNode* ptr); //소멸자
	void insertItem(Student st); //수강자 추가
	void insert(TreeNode* &ptr, Student st); //수강자 추가 재귀
	void removeItem(string id); //수강자 정보 삭제
	void remove(TreeNode* &ptr, string id); //수강자 정보 삭제 재귀
	void correctItem(Student st); //수강자 정보 변경
	void correction(TreeNode* ptr, Student st); //수강자 정보 변경 재귀
	void searchItem(string id); //수강자 정보 출력
	void search(TreeNode* ptr, string id); //수강자 정보 출력 재귀
	void printItem(); //학번 오름차순으로 출력
	void print(TreeNode* ptr); //학번 오름차순으로 출력 재귀
	int Height();
	int getHeight(TreeNode* ptr);//트리의 높이 구하기
private:
	TreeNode *head;
	int length;
};




#endif /* STUDENTTREE_H_ */
