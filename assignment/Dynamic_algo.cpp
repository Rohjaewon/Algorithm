/*
 * algo_3-2.cpp
 *
 *  Created on: 2018. 10. 28.
 *      Author: harry
 */
/*
#include <iostream>
using namespace std;
int n, k;//n은 만들어야할 숫자, k는  1~k까지의 단위를 의미
int C(int i, int j){
	int C1[n+1][k+1] = {0};//C1[a][b]일 때 a를 1~b로 만드는 가지수를 저장
	for(int z = 0; z <= i; z++){
		for(int u = 0; u<=j; u++){
			if(u==0) //단위가 없으면 가지수는 0개
				C1[z][u]=0;
			else if(z==0 || u==1)//단위가 1이거나 만들어야할 숫자가 0이면 가지수는 1개
				C1[z][u] = 1;
			else if(z < u)//만들어야할 숫자가 단위보다 작을경우 단위를 숫자와 같게 한다.
				C1[z][u] = C1[z][z];
			else//z를 1~u까지의 숫자로 만들 때 u를 포함할 때와 그렇지 않을때 2가지 경우로 나눠서 해결한다.
				C1[z][u] = C1[z-u][u]+C1[z][u-1];
		}
	}
	for(int z = 0; z<=i; z++){
		for(int u =0; u<=j; u++)
			cout << C1[z][u] << " ";
	cout << endl;
	}
	return C1[i][j];
}


int main(){
	cin >> n >> k;
	cout << C(n, k) << endl;
}
*/
