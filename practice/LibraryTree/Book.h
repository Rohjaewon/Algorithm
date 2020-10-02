/*
 * Student.h
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
using namespace std;

class Book {
public:
	void set(string id, string name, int price, int num) {
		this->id = id;
		this->name = name;
		this->price = price;
		this->num = num;
	}

	void sellnum(int num) {//도서 판매
		this->num -= num;
		sell += num;
		get += num * price;
	}
	void resetnum(int num) {//폐기됬던 도서에 대해서 재고수량 초기화
		this->num = num;
	}
	void getnum(int num) {
		this->num += num;
	}
	string getID() {
		return id;
	}
	string getName() {
		return name;
	}
	int getPrice() {
		return price;
	}
	int getNum() {
		return num;
	}
	int getSell() {
		return sell;
	}
	int getGet() {
		return get;
	}
private:
	string id;  //도서번호
	string name;  //도서이름
	int price;  //도서가격
	int num;  //도서 재고
	int sell = 0; //판매수량
	int get = 0; // 판매금액
};

#endif /* BOOK_H_ */
