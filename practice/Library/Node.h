/*
 * Node.h
 *
 *  Created on: 2018. 5. 22.
 *      Author: harry
 */

#ifndef NODE_H_
#define NODE_H_
#include <string>
using namespace std;
struct Node {
	   string bookID; //도서번호
	   string bookName;//도서이름
	   int price;//가격
	   int num;//재고수량
	   Node* link;
	};
#endif /* NODE_H_ */
