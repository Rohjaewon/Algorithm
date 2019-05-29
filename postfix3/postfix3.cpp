/*
 * postfix.cpp
 *
 *  Created on: 2018. 3. 23.
 *      Author: harry
 */

#include "Stack.h"
#include "Var.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//변수가 저장된 table에 원하는 변수를 찾아서 위치를 반환해주는 함수
int find(Var var[], string token, int i){
	for(int j = 0; j <= i; j++){
		if(var[j].getname() == token){
			return j;
		}
	}
	return -1;
}
//연산자나 ';'과 일치하는지 비교해주는 함수
bool matching(string token){
	if(token != "_" && token != "+" && token != "-" && token != "*" && token != "/" && token != "%" && token != ";") return true;
	else return false;
}
///////main
int main()
{
	Stack stack;
	Var var[100]; //변수와 값을 저장하는 클래스 배열
	string token;//명령어와 식을 입력받는 변수
	string flag; // 명령어를 기억하는 string 변수
	int i = 0; // 클래스 var에 있는 변수를 찾기위한 index
	int k = -1; // find함수 반환 값을 받아주는 변수
	int first = -1;//변수저장이 처음인지 아닌지 구별해주는 변수
	int error=0;//error3 잡아주기 위한 변수
	while (1)
	{
		cin >> token;
		if(token == "print")
			flag = token;
		if(token == "q")
			flag = token;


		if(token == "set")
			flag = token;
		const char* str = token.c_str();

		if(isdigit(token[0]))
		{
			stack.push(atoi(str));
		}

		else if(str[0] == '-' && isdigit(str[1])) //negative operand
		{
			stack.push(atoi(str));
		}

		else if (token == "_"){
			int changesign;
			changesign = stack.pop()*(-1);
			stack.push(changesign);
		}
		else if(token == "+")
		{

			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}

			}
			int second;
			second = stack.pop();

			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			int first;
			first = stack.pop();
			stack.push(first+second);
		}
		else if(token == "*")
		{
			int second;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			first = stack.pop();

			stack.push(first*second);
		}
		else if (token == "-")
		{
			int second;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
				return 0;
				}
			}
			first = stack.pop();

			stack.push(first-second);
		}
		else if (token == "/")
		{
			int second;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			first = stack.pop();

			stack.push(first/second);
		}
		else if (token == "%")
		{
			int second;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				if(error == -1)
					continue;
				else{
					cout << "error1 \n";
					return 0;
				}
			}
			first = stack.pop();
			stack.push(first%second);
		}
		////////변수에 값을 저장
		if(flag == "set" && token == ";"){
			if(k == -1){//새로 만들어진 변수에 값을 저장
				var[i].setvalue(stack.pop());
				i++;
				flag.clear();
				first = -1;
			}
			else{//기존에 있던 변수에 값을 다시 저장
				var[k].setvalue(stack.pop());
				k = -1;
				flag.clear();
				first = -1;

			}
		}

		/////////stack에 변수의 값을 저장
		else if(flag == "set" && !isdigit(token[0]) && first == 0){
			int index = find(var, token, i);
			if(index != -1){
				stack.push(var[index].getvalue());
			}

		}
		///////////변수생성
		else if (flag == "set" && !isdigit(token[0]) && first == -1){
			if(token != "set" && matching(token)){
				int index = find(var, token, i);
					if(index == -1){ //같은 이름이 없으면 새로 저장
						var[i].setname(token);
						++first;
					}
					else{ // 같은 이름이면 저장하지않음
						 k = index;
						 ++first;
					}
			}
		}

		if(flag == "print" && token != ";" && !isdigit(token[0])){ //변수이름을 찾아서 그 변수에 저장된 값을 stack에 저장
			if(token != "print" && matching(token)){
				int index = find(var, token, i);
					if(index != -1){
						stack.push(var[index].getvalue());
					}
					else error = -1;
			}
		}
		if(token == ";" && flag == "print"){ //명령어 print를 입력 받으면 출력할 수 있게 함.
			if(error == -1){
				cout << "error3 \n" << endl;
				return 0;
			}
			else if(error == 0){
				int result = stack.pop();
				if(!stack.isEmpty()){
					cout << "error2 \n";
					return 0;
				}
				cout << result << " ";
				flag.clear();
			}
		}
		if(flag == "q"){
			return 0;
		}
	}//while
	return 0;
}//main







