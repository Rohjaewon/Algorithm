/*
 * WebBrowser.h
 *
 *  Created on: 2018. 5. 4.
 *      Author: harry
 */
#ifndef WEBBROWSER_H_
#define WEBBROWSER_H_

#include <iostream>
#include "Node.h"
#include "DoubleNode.h"

using namespace std;

class WebBrowser{
private:
	string home_addr;//홈주소
	DoubleNode* head;//처음
	DoubleNode* current;//마지막
	Node* hisHead; //history 처음
	Node* hisLast; //history 마지막
public:
	WebBrowser();
	~WebBrowser();
	void go (string addr);
	void forward();
	void backward();
	void home();
	void set_home(string addr);
	void history();
	void deleteAll(DoubleNode* ptr);

};

#endif /* WEBBORWSER_H_ */


