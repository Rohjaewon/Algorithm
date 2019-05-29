/*
 * postfix.cpp
 *
 *  Created on: 2018. 3. 23.
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
	cin >> token;

	while (token != ";")
	{
		const char* str = token.c_str();

		if(isdigit(token[0]))
		{
			stack.push(atoi(str));
		}

		else if(str[0] == '_' && isdigit(str[1])) //negative operand
		{
			str = token.c_str()+1;
			stack.push(atoi(str)*-1);
		}
		else if(token == "+")
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
			stack.push(first+second);
		}
		else if(token == "*")
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

			stack.push(first*second);
		}
		else if (token == "-")
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
		else if (token == "/")
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

			stack.push(first/second);
		}
		else if (token == "%")
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
			stack.push(first%second);
		}
		cin >> token;
	}
	int result = stack.pop();
	if(!stack.isEmpty()){
		cout << "error2 \n";
		return 1;
	}
	cout << result << endl;
	return 0;
}



