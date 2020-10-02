/*
 * Var.cpp
 *
 *  Created on: 2018. 4. 7.
 *      Author: harry
 */

#include "Var.h"
#include <string>
#include <iostream>
using namespace std;

Var::Var(string str, int insert) : var(str), value(insert){}
Var::Var() : var(""), value(0)
{}
bool Var::print(string str){
	if(var == str)
		return true;
	else return false;
}
void Var::setname(string str){
	var = str;
}
void Var::setvalue(int insert){
	value = insert;
}
string Var::getname(){
	return var;
}
int Var::getvalue(){
	return value;
}

