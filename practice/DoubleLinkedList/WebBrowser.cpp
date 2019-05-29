/*
 * WebBrowser.cpp
 *
 *  Created on: 2018. 5. 4.
 *      Author: harry
 */

#ifndef WEBBROWSER_CPP_
#define WEBBROWSER_CPP_
#include "WebBrowser.h"
#include <iostream>

using namespace std;

WebBrowser::WebBrowser(){
	home_addr = "http://ces.hufs.ac.kr";
	cout << home_addr << endl;
	head = new DoubleNode;
	head ->data = home_addr;
	head -> back = head -> next = NULL;
	current = head;
	hisHead = new Node;
	hisHead -> data = home_addr;
	hisHead -> next = NULL;
	hisLast = hisHead;
}
WebBrowser::~WebBrowser(){
	deleteAll(head);
}
void WebBrowser::deleteAll(DoubleNode* ptr){
	DoubleNode* temp;
	temp = ptr;
	while(temp != NULL){
		delete temp;
		ptr = ptr ->next;
		temp = ptr;
	}
}
void WebBrowser::go(string addr){
	DoubleNode* location;
	location = new DoubleNode;
	location->data = addr;
	location->next = NULL;

	deleteAll(current->next);

	location -> back = current;
	current -> next = location;
	current = location;

	Node* hisTemp;
	hisTemp = new Node;
	hisTemp->data = addr;
	hisTemp->next = NULL;
	hisLast->next = hisTemp;
	hisLast = hisTemp;

	cout << current->data << endl;
}
void WebBrowser::forward(){
	if(current->next != NULL)
		current = current->next;
	cout << current->data << endl;
}
void WebBrowser::backward(){
	if(current->back != NULL)
		current = current->back;
	cout << current->data << endl;
}
void WebBrowser::home(){
	go(home_addr);
}
void WebBrowser::set_home(string addr){
	home_addr=addr;
}
void WebBrowser::history(){
	Node* hisTemp=hisHead;
	while(hisTemp){
		cout << hisTemp->data << endl;
		hisTemp = hisTemp->next;
	}
}



#endif /* WEBBROWSER_CPP_ */
