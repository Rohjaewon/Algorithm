/*
 * Fossil.cpp
 *
 *  Created on: 2019. 2. 12.
 *      Author: harry
 */
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 987654321;
const int MIN = -987654321;

typedef struct point{
	double x;
	double y;
} point;

int n, m;
vector<pair<point, point> > upper;
vector<pair<point, point> > lower;
vector<point> hull1;
vector<point> hull2;

void seperate(vector<point> hull){
	 int size = hull.size();
	 for(int i =0; i<size; i++){
		 if(hull[i].x > hull[(i+1)%size].x)
			 upper.push_back(make_pair(hull[i], hull[(i+1)%size]));
		 else // if(hull[i].x <= hull[(i+1)%size].x)
			 lower.push_back(make_pair(hull[i], hull[(i+1)%size]));
	 }
}

bool between(point a, point b, double x){
	return ((a.x <= x) && (x < b.x)) || ((b.x <= x) && (x < a.x));
}

double get(point a, point b, double x){
	double dy = b.y-a.y, dx = b.x-a.x;
	return a.y+dy*(x-a.x)/dx;
}

double Dist(double x) {
	double minY = MAX, maxY = MIN;//minY:upper중에서 y값이 가장 작은 값, maxY:lower중에서 Y값이 가장 큰 값
	int usize = upper.size(), lsize = lower.size();
	for (int i = 0; i < usize; i++) {
		if(between(upper[i].first, upper[i].second, x)){
			minY = min(minY, get(upper[i].first, upper[i].second, x));
		}
	}
	for (int i = 0; i < lsize; i++) {
		if (between(lower[i].first, lower[i].second, x)) {
			maxY = max(maxY, get(lower[i].first, lower[i].second, x));
		}
	}
	return minY-maxY;
}

int main(){
	cin >> n >> m;
	for(int i =0; i<2*n; i++){
		point temp; cin >> temp.x >> temp.y;
		hull1.push_back(temp);
	}
	for (int i = 0; i < 2 * m; i++) {
		point temp;
		cin >> temp.x >> temp.y;
		hull2.push_back(temp);
	}
	seperate(hull1); seperate(hull2);
	double lo = 0, hi = 100;
	for(int it = 0; it < 100; it++){
		double abb, aab;
		aab = (lo+2*hi)/3;
		abb = (2*lo+hi)/3;
		if(Dist(abb) < Dist(aab))
			lo = abb;
		else
			hi = aab;
	}
	cout << max(0.0, Dist(hi));
}
*/
