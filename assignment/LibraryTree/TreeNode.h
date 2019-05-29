/*
 * Node.h
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */

#ifndef TREENODE_H_
#define TREENODE_H_
#include "Book.h"
using namespace std;
struct TreeNode {
	Book book;
	TreeNode* leftchild;
	TreeNode* rightchild;
};
#endif /* TREENODE_H_ */
