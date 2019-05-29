/*
 * radixsort.cpp
 *
 *  Created on: 2018. 10. 18.
 *      Author: harry
 */
/*
#include <iostream>
#include <deque>
#include <math.h>
#include <time.h>
using namespace std;


int max(int a[], int n){
	int max = 0, count =0;
	for(int i =0; i<n; i++){
		if(max < a[i])
			max = a[i];
	}
	while(max >0){
		max /= 10;
		count++;
	}
	return count;
}

void radixsort(int a[], int n, int r){
	cout << "?" << endl;
	int d = max(a, n);//가장 큰 숫자의 자리수
	cout << "d : " << d << endl;
	deque<deque<int>> b(r);
	int tempA[n];
	for(int i=0; i<n; i++){ //tempA에 a복사
		tempA[i] = a[i];}

	for(int o =1; o<=d; o++){
		for(int j=0; j<n; j++){
			int temp = tempA[j] % 10;
			cout << "temp : " << temp << endl;
			b[temp].push_back(a[j]);
		}

		int num=0;
		for(int k = 0; k<r; k++){
			while(!(b[k].empty())){
				cout << "k : " << k << endl;
				cout << "b[k].front() : " << b[k].front() << endl;
				cout << "k2 : " << k << endl;
				a[num] = b[k].front();
				tempA[num] = b[k].front()/(int)pow(10, o);
				b[k].pop_front();
				num++;
			}
		}
		b.clear();
		cout << "시발" << endl;
	}
	cout << "디 안도" << endl;
}

int main(){
	srand((int)time(0));
	int n, r;
	//cin >> n >> r;
	n = 5;
	r=10;
	int a[n];
	//for(int i=0; i<n; i++)
	a[0]=798, a[1]= 336, a[2]= 325, a[3]= 306, a[4]= 770;
		//cin >> a[i];
		//a[i] = rand()%1000+1;
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
	radixsort(a, n, r);
	cout<<"리얼 디 안도" << endl;
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;

}

*/

