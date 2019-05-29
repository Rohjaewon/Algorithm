/*
 * algo_4-1.cpp
 *
 *  Created on: 2018. 11. 25.
 *      Author: harry
 */
/*
#include <iostream>
#include <stack>
#include <algorithm>
#include <time.h>
const int MAX = 2000;
int Board[MAX][MAX] = {0};
using namespace std;
int num, day; //사람 수, 일할 날의 수

typedef struct worker {
	int day; //직원이 일할 수 있는 일 수
	int restart = -1; //직원이 다시 일을 시작할 수 있는 날짜
	int ing = 0; //연속으로 몇일 일했는지 확인
} worker;

bool down(worker left, worker right) {
	return left.day > right.day;
}

int answer(worker *p_num, int* w_day, int w, int h) {
	int index;
	int person = 0;
	int temp =-1;
	int cnt = 0;
	stack<int> store;
	for(index = 0; index<day; index++){
		while (w_day[index] > 0) {
			if (p_num[person].day > 0 && p_num[person].restart <= index) {
				if (index < day-1 && Board[person][index - 1] == 0 && p_num[person].ing >= 1) {
					cout << "index : " << index << " person : " << person << endl;
					for (int i = 0; i < num; i++) {
						for (int j = 0; j < day; j++)
							cout << Board[i][j] << " ";
						cout << endl;
					}
					return -1;
				}
				Board[person][index] += 1;
				if(p_num[person].ing == 0){
					store.push(person);
				}
				if(p_num[person].ing != 0 && !store.empty()){
					int tstore = store.top();
					cout << "tstore : " << tstore << endl;
					Board[tstore][index] -= 1;
					p_num[tstore].day += 1;
					p_num[tstore].ing -= 1;
					w_day[index] += 1;
					store.pop();
				}
				w_day[index] -= 1;
				p_num[person].day -=1;
				p_num[person].ing +=1;
				if(p_num[person].ing == w){
					p_num[person].ing = 0;
					p_num[person].restart = index+h+1;
					temp = -1;
				}
				if (p_num[person].ing >= 1 && p_num[person].ing < w)
					if (temp == -1 || temp >= person)
						temp = person;
			} //if
			person++; cnt++;
			if(person >= num && cnt > num)
				break;
			if(person >= num && cnt <= num)
				person = 0;
		} //while
		if (temp == -1)
			person = 0;
		else
			person = temp;
		cnt = 0;
		while(!store.empty()) store.pop();
	} //for

	for(int i =0; i<num; i++){
		for(int j =0; j<day; j++)
			cout << Board[i][j] << " ";
		cout << endl;
	}
	int index2 = day-1;
	for (int p = 0; p < num; p++) {
		if (Board[p][index2 - 1] == 1 && Board[p][index2] == 0 && p_num[p].ing > 0)
			return -1;
	}
	for (int work = 0; work < day; work++)
		if (w_day[work] != 0)
			return -1;
	return 1;
}

int main() {
	srand((int) time(0));

	int w, h; //각 사람의 일 수, 휴식 일수
	cin >> num >> day >> w >> h;
	worker *p_num = new worker[num];
	int *w_day = new int[day];
	for (int i = 0; i < num; i++) {
		//p_num[i].day = (rand()%3+1)*w;
		cin >> p_num[i].day;
	}
	for (int i = 0; i < day; i++) {
		//w_day[i] = rand()%3+1;
		cin >> w_day[i];
	}
	for (int i = 0; i < num; i++)
		cout << p_num[i].day << " ";
	cout << endl;
	for (int i = 0; i < day; i++)
		cout << w_day[i] << " ";
	cout << endl;

	clock_t start, end;
	start = clock();
	sort(p_num, p_num + num, down);
	cout << answer(p_num, w_day, w, h) << endl;
	end = clock();
	cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
	delete[] p_num;
	delete[] w_day;
	return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;
const int MAX = 2000;
int Board[MAX][MAX] = {0};
int num, day; //사람 수, 일할 날의 수

struct work {
	work(int d, int  s){
		day = d;
		start = s;
	}
	bool operator <(const work& work) const{
		if(start > work.start)
			return true;
		else if(start < work.start)
			return false;
		else{
			if(day < work.day)
				return true;
			else return false;
		}
	}
	int day;
	int start;
};

int answer(priority_queue <work, vector<work>, less<work> > p_num, int w_day[], int w, int h){
	int index =0;
	for(index =0; index <day; index++){
		while(w_day[index] >0){
			if(p_num.top().day >0 && p_num.top().start <= index){
				p_num.top().day -=1;
			}
		}
	}
}

int main(){
	priority_queue <work, vector<work>, less<work> > p_num;
	int w, h;
	cin >> num >> day >> w >> h;
	int *w_day = new int[day];
	for(int i =0; i<num; i++){
		int temp; cin >> temp;
		p_num.push(work(temp, 0));
	}
	for(int i =0; i<day; i++)
		cin >> w_day[i];
	while(!p_num.empty()){
		cout << p_num.top().day << " " << p_num.top().start<< endl;
		p_num.pop();
	}
}
*/

