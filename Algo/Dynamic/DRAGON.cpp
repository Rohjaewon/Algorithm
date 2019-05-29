/*
 * DRAGON.cpp
 *
 *  Created on: 2019. 1. 14.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int g, start, num;

string get_minus(string str){
	int size = str.size();
	for(int i =0; i<size; i++){
		if(str[i] == '+')
			str[i] = '-';
		else if(str[i] == '-')
			str[i] = '+';
	}
	return str;
}

void answer(vector<string>& dragon, int t, int size){
	string backhalf = dragon[t-1].substr(size);
	//cout << forehalf << "    " << backhalf << endl;
	dragon[t] = dragon[t-1]+"+"+dragon[t-2]+get_minus(backhalf);
	if(t == g){
		cout << dragon[g].substr(start-1, num) << endl;
	}
	else
		answer(dragon, t+1, 2*size+1);
}

int main(){
	cin >> g >> start >> num;
	vector<string> dragon(50);
	dragon[0] = "FX"; dragon[1] = "FX+YF";
	int size = dragon[1].size();
	if(g == 0 || g == 1){
		cout << dragon[g].substr(start-1,num) << endl;
	}
	else
		answer(dragon, 2, size/2);
	return 0;
}*/


