/*
 * Node.h
 *
 *  Created on: 2018. 4. 7.
 *      Author: harry
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
typedef int ItemType;
class Node{
public:
	ItemType info;
	Node *next;
	Node(int val=0) :info(0), next(NULL) {}
};


#endif /* NODE_H_ */
