/*
 * main.cpp
 *
 *  Created on: 2018. 5. 4.
 *      Author: harry
 */
#include <iostream>
#include "WebBrowser.h"
using namespace std;

int main(){
	WebBrowser Web;
	string addr;
	string command;

	while(1){
		cin >> command;
		if(command == "exit")
			break;
		if(command == "go"){
			cin >> addr;
			Web.go(addr);
		}
		else if (command == "forward")
			Web.forward();
		else if (command == "backward")
			Web.backward();
		else if(command == "home")
			Web.home();
		else if(command == "set_home"){
			cin >> addr;
			Web.set_home(addr);
		}
		else if(command == "history")
			Web.history();
	}
	return 0;
}



