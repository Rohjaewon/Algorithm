/*
 * CircularQ.cpp
 *
 *  Created on: 2018. 5. 3.
 *      Author: harry
 */

#include <iostream>
#include "CircularQ.h"
#include "truck.h"
using namespace std;

CircularQ ::CircularQ(){
	front = 0; rear = 0;
	data = new ItemType[1001];
	MAXSIZE = 1001;
}
CircularQ::CircularQ(int size){
	front = 0; rear = 0;
	data = new ItemType[size+1];
	MAXSIZE = size+1;
}
CircularQ::~CircularQ(){
	delete[] data;
}
bool CircularQ::isEmpty() const{
	return front == rear;
}
bool CircularQ::isFull() const{
	return front == ((rear+1)%MAXSIZE);
}
bool CircularQ::willEmpty() const{
	if((front+1)%MAXSIZE == rear)
		return true;
	else return false;
}
void CircularQ::enqueue(ItemType item){
	if(isFull()){
		cout << "큐가 포화상태입니다." << endl;
		exit(0);
	}
	else {
		rear = (rear+1)%MAXSIZE;
		data[rear] = item;
	}
}
ItemType CircularQ::dequeue(){
	if(isEmpty()){
		cout << "큐가 비어있습니다." << endl;
		exit(0);
	}
	else {
		front = (front+1)%MAXSIZE;
		return data[front];
	}
}

bool CircularQ::move(int pos, int len){
	data[front+pos+1].pos += 1;
	cout << "[" << data[front+pos+1].weight << "," <<data[front+pos+1].pos<<"]" << endl;
	if(data[front+pos+1].pos > len){
		this->dequeue();
		return true;
	}
	return false;
}
int CircularQ::getweight(int pos){
	return data[front+pos+1].weight;
}
int CircularQ::Qsize(){
	return rear-front;
}

