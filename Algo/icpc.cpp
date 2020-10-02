/*
 * icpc.cpp
 *
 *  Created on: 2018. 12. 27.
 *      Author: harry
 */

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

 typedef struct bunsu{
 long long int a = 1;//분자
 long long int b;//분모
 }bunsu;

 long long int gcd(long long int a, long long int b){
 if(b == 0){
 return a;
 }
 else{
 return gcd(b, a%b);
 }
 }

 int main(){
 srand((int)time(0));
 int bunmo = 2;
 long long int a, b;
 while(1){
 a = rand()%100;
 b = rand()%100;
 if((b > a) && (gcd(b,a) == 1))
 break;
 }

 bunsu B; B.b = bunmo;
 while(1){

 B.b = bunmo;
 if(a*B.b >= b){
 cout << a << "/" << b << endl;
 cout << "1/" << B.b << endl;
 a = a*B.b - b;
 b = b*bunmo;
 int mod = gcd(b, a);
 //cout << " " << mod << endl;
 a /= mod;
 b /= mod;
 }
 if(a == 1){
 cout << b << endl;
 break;
 }
 bunmo++;
 }
 }
 

typedef struct point {
	int x=0;
	int y=0;
} point;

int main() {
	int n;
	cin >> n;
	vector<point> Board(n);
	vector<int> Dist(n, 0);
	vector<int> answer(n, 0);
	point mean;
	for (int i = 0; i < n; i++) {
		cin >> Board[i].x;
		cin >> Board[i].y;
		mean.x += Board[i].x;
		mean.y += Board[i].y;
	}
	mean.x /= n;
	mean.y /= n;
	for (int i = 0; i < n; i++) {
		Dist[i] = ((mean.x - Board[i].x)*(mean.x - Board[i].x)) + ((mean.y - Board[i].y)*(mean.y - Board[i].y));
	}
	int index = -1, max = 0;
	for (int i = 0; i < n; i++) {
		if (max < Dist[i]) {
			max = Dist[i];
			index = i;
		}
	}
	for (int i = 0; i < n; i++) {
		answer[i] =
				((Board[index].x - Board[i].x) * (Board[index].x - Board[i].x))
						+ ((Board[index].y - Board[i].y)
								* (Board[index].y - Board[i].y));
	}
	int index2 = -1, maxDist = 0;
	for (int i = 0; i < n; i++) {
		if (maxDist < answer[i]) {
			maxDist = answer[i];
			index2 = i;
		}
	}
	cout << Board[index].x << " " << Board[index].y << " " << Board[index2].x
			<< " " << Board[index2].y << endl;
}

 typedef struct node {
 int v;
 int w;
 node* link;
 } node;

 int main() {
 int n, m, L, G;
 cin >> n >> m >> L >> G;
 int vertex = n * m;
 node** adlist = new node*[vertex];
 for (int i = 0; i < n; i++)
 adlist[i] = NULL;
 vector<vector<int> > garo(vertex, vector<int>(vertex), 0);
 vector<vector<int> > saero(vertex, vector<int>(vertex), 0);
 int h = 0, l = 1;
 while (1) {
 int temp;
 cin >> temp;
 garo[h][l] = temp;
 h++;
 l++;
 }
 for (int i = 0; i < vertex; i++) {
 node* ptr = new node;
 ptr->v = i + 1;
 ptr->w = garo[i][i];
 ptr->link = adlist[i];
 adlist[i] = ptr;
 node* ptr2 = new node;
 ptr2->v = i + m;
 ptr2->link = adlist[i];
 adlist[i] = ptr2;
 }
 }
 
