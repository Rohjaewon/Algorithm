/*
 * Var.h
 *
 *  Created on: 2018. 4. 7.
 *      Author: harry
 */

#ifndef VAR_H_
#define VAR_H_
#include <string>
using namespace std;

class Var{
private:
	string var;
	int value;
public:
	Var();
	Var(string str, int insert);
	void setname(string str);
	void setvalue(int insert);
	bool print(string str);
	string getname();
	int getvalue();
};

#endif

/* VAR_H_ */
