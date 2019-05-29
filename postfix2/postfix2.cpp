/*
 * postfix2.cpp
 *
 *  Created on: 2018. 4. 5.
 *      Author: harry
 */
#include "Stack.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main()
{
	Stack stack;
	string token;
	char ch;

	while ((ch=getchar()) != ';')
	{
		if((ch != '_')&&(ch != ' ')&&(ch != '-') && (ch!= '+')&&(ch!='*')&&(ch!='/')&&(ch!='%')&&(ch!=';')){
			token += ch;
			continue;
		}

		if(ch == '_'){
			if (token.length() == 0){
				ch = '-';
				token += ch;
				continue;
			}
			else{
				const char *ptr = token.c_str();
				stack.push(atoi(ptr));
				token.clear();
				ch = '-';
				token += ch;
				continue;
			}
		}
		const char* str = token.c_str();

		if(isdigit(token[0]))
		{
			stack.push(atoi(str));
			token.clear();
		}
		if(str[0] == '-' && isdigit(str[1])) //negative operand
		{
			stack.push(atoi(str));
			token.clear();
		}

		if(ch == '+')
		{
			int second;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			else
				second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			first = stack.pop();
			stack.push(first+second);
		}
		if(ch == '*')
		{
			int second;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			else
				second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			first = stack.pop();
			stack.push(first*second);
		}
		if (ch == '-')
		{
			int second;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			first = stack.pop();

			stack.push(first-second);

		}
		if (ch == '/')
		{
			int second;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			else
				second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			first = stack.pop();
			stack.push(first/second);
		}
		if (ch == '%')
		{
			int second;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			else
				second = stack.pop();
			int first;
			if(stack.isEmpty())
			{
				cout << "error1 \n";
				return 1;
			}
			first = stack.pop();
			stack.push(first%second);
		}
	}//while
	int result = stack.pop();
	if(!stack.isEmpty()){
				cout << "error2 \n";
				return 0;
			}
	cout << result << endl;
	return 0;
}



