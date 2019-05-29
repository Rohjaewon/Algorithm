/*
 * main.cpp
 *
 *  Created on: 2018. 5. 11.
 *      Author: harry
 */
/*
#include <iostream>
using namespace std;

int fact(int n){
	if(n == 0)
		return 1;
	else return n*fact(n-1);
}

long long fiboIteration(int n){

	if(n == 0 || n==1)
		return n;
	else {
		int first = 0;
		int second = 1;
		int current;

		for(int i =2; i <= n; i++){
			current = first+second;
			first = second;
			second = current;
		}
		return current;
	}
}
long long fibo(int n){
	if(n == 0|| n ==1)
		return n;
	else
		return fibo(n-2)+fibo(n-1);
}

int digitSum(int n){
	if(n<10)
		return n;
	else
		return n%10+digitSum(n/10);
}
int gcd(int A, int B){
	if(A%B == 0)
		return B;
	else
		return gcd(B, A%B);
}

int main(){
	cout << fact(3) << endl;
	cout << fiboIteration(3) << endl;
	cout << fibo(3) << endl;
	cout << digitSum(12345) << endl;
	cout << gcd(14, 6) << endl;

	return 0;
}
*/

#include <iostream>
#include <cstdio>
using namespace std;
int count = 0;
void Hanoi(int n, char from, char tmp, char to){
	count++;
	if (n == 1)
		printf("1을 %c에서 %c로 이동\n", from, to);
	else{
		Hanoi(n-1, from, to, tmp);
		printf("%d을 %c에서 %c로 이동\n", n, from, to);
		Hanoi(n-1, tmp, from, to);
	}
}

int main(){
	Hanoi(3, 'A', 'B', 'C');
	cout << count<<endl;
}

/*
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int maxArray(int a[], int n){
	if(n == 1)
		return a[0];
	else
		return max(a[n-1], maxArray(a, n-1));
}

int main(){
	int arr[10] = {1,2,3,34,3,7,1,6,9,2};
	int result = maxArray(arr, 10);
	cout << result << endl;
}
*/
