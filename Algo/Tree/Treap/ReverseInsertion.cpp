/*
 * ReverseInsertion.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct TreapNode{
	int key = 0, size = 0;
	int priority = 0;
	TreapNode* left;
	TreapNode* right;
	TreapNode(int _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL)
	{ }
	void setleft(TreapNode* newleft){left = newleft; calSize();}
	void setright(TreapNode* newright){right = newright; calSize();}
	void calSize(){
		size = 1;
		if(left) size += left->size;
		if(right) size += right->size;
	}
};

typedef pair<TreapNode*, TreapNode*> NodePair;//왼쪽은 root보다 작은 서브트리, 오른쪽은 root보다 큰 서브트리

NodePair split(TreapNode* root, int key){
	if(root == NULL) return NodePair(NULL, NULL);
	//root의 key가 새로운 key보다 작다면 오른쪽을 쪼갠다
	if(root->key < key){
		NodePair rs = split(root->right, key);
		root->setright(rs.first);
		return NodePair(root, rs.second);
	}
	//root의 key가 새로운 key보다 크다면 왼쪽을 쪼갠다
	NodePair ls = split(root->left, key);
	root->setleft(ls.second);
	return NodePair(ls.first, root);
}

TreapNode* insert(TreapNode* root, TreapNode* node){
	if(root == NULL)
		return node;
	if(root->priority < node->priority){ //새로운 node의 우선순위가 더 크다면
		NodePair splitted = split(root, node->key);
		node->setleft(splitted.first);
		node->setright(splitted.second);
		return node;
	}
	//root가 우선순위가 더 큰 경우
	else if(node -> key < root->key)
		root->setleft(insert(root->left, node));
	else
		root->setright(insert(root->right, node));
	return root;
}

TreapNode* merge(TreapNode* a, TreapNode* b){
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->priority < b->priority){
		b->setleft(merge(a, b->left));
		return b;
	}
	a->setright(merge(a->right, b));
	return a;
}

TreapNode* erase(TreapNode* root, int key){
	if(root == NULL) return root;
	if(root->key == key){
		TreapNode* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if(key < root->key)
		root->setleft(erase(root->left, key));
	else
		root->setright(erase(root->right, key));
	return root;
}

void preorder(TreapNode* ptr){
	if(ptr != NULL){
		cout << ptr->key << ", " << ptr -> priority << "  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void inorder(TreapNode* ptr){
	if(ptr != NULL){
		inorder(ptr->left);
		cout << ptr->key << ", " << ptr -> priority << "  ";
		inorder(ptr->right);
	}
}

TreapNode* kth(TreapNode* root, int k){//트립에서 k번째 원소 찾기
	if(root == NULL) return NULL;
	int leftsize = 0;
	if(root->left != NULL) leftsize = root->left->size;
	if(leftsize+1 == k) return root;
	if(leftsize < k) return kth(root->right, k-leftsize-1);
	else return kth(root->left, k);
}

int countLess(TreapNode* root, int x) { //x보다 작은 원소 개수 세기
	if(root == NULL) return 0;
	if(root->key >= x)
		return countLess(root->left, x);
	int ls = 1;
	if (root->left != NULL)
		ls = root->left->size+1;
	return countLess(root->right, x) + ls;
}

int main(){
	TreapNode* root = NULL;
	int n; cin >> n;
	vector<int> arr(n);
	stack<int> S;
	for(int i =0; i<n; i++){
		int k; cin >> k;
		arr[i] = k;
		root = insert(root, new TreapNode(i+1));
	}
	for(int i = n-1; i>=0; i--){
		int k = i+1-arr[i];
		TreapNode* temp = kth(root, k);
		S.push(temp->key);
		root = erase(root, temp->key);
	}
	while(!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
}*/







