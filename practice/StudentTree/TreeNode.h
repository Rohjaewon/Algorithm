/*
 * Node.h
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */

#ifndef TREENODE_H_
#define TREENODE_H_
#include "Student.h"
struct TreeNode{
	Student data;
	TreeNode* leftchild;
	TreeNode* rightchild;
};



#endif /* TREENODE_H_ */
