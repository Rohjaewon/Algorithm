/*
 * CircularQ.h
 *
 *  Created on: 2018. 5. 3.
 *      Author: harry
 */

#ifndef CIRCULARQ_H_
#define CIRCULARQ_H_
#include "truck.h"
typedef Truck ItemType;
class CircularQ
{
private:
	int front;
	int rear;
	int MAXSIZE;
	ItemType *data;
public:
	CircularQ();
	CircularQ(int size);
	~CircularQ();
	bool isEmpty() const;
	bool isFull() const;
	bool willEmpty() const;
	void enqueue(ItemType item);
	bool move(int pos, int len);
	int getweight(int pos);
	int Qsize();
	ItemType dequeue();
};




#endif /* CIRCULARQ_H_ */
