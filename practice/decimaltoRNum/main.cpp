/*
 * main.cpp
 *
 *  Created on: 2018. 4. 5.
 *      Author: harry
 */
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

string f (int decimalNum, int r) {
   Stack s;
   string str;
   if (decimalNum == 0) {
      str = "0";
      return str;
   }
   while (decimalNum != 0) {
      int rem = decimalNum % r;
      char ch = '0'+rem;
      if(ch > '9')
    	  ch += 7;
      s.push(ch);
      decimalNum = decimalNum / r;
   }
   while(!s.isEmpty()) {
      str += s.pop();
   }
   return str;
}
int main( ) {
   int n, r;
   string rNum;
   cin >> n >> r;
   rNum = f(n, r);
   cout << rNum << endl;

   return 0;
}




