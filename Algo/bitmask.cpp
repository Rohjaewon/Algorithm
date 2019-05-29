/*
 * bitmask.cpp
 *
 *  Created on: 2018. 12. 30.
 *      Author: harry
 */

//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
/*
void print(int bomb){
	stack<int> S;
	while(bomb != 0){
		S.push(bomb%2);
		bomb /= 2;
	}
	while(!S.empty()){
		cout << S.top() << " ";
		S.pop();
	}
}

int main(){
	int n;
	cout << "화학물질 개수 입력 : "; cin >> n;
	int bn;
	cout << "폭발물 조합 개수 입력 : "; cin >> bn;
	vector<int> bomb(n, 0);
	for(int i =0; i<bn; i++){
		int b1, b2;
		cout << "폭발물 조합 입력 : "; cin>>b1>>b2;
		int temp = (1<<b1);
		bomb[b2] = temp;
		int temp2 = (1<<b2);
		bomb[b1] = temp2;
	}
	for(int set = 1; set < (1<<n); set++){
		bool explode = true;
		bool stable = true;
		for (int explore = 0; explore < n; explore++) {
			if ((set & (1 << explore)) != 0 && (set & bomb[explore]) != 0) {
				stable = false;
				break;
			}
		}if(!stable)
			continue;
		for(int explore = 0; explore < n; explore++){
			if((set & (1 << explore)) == 0 && (set & bomb[explore]) == 0){
				explode = false;
				break;
			}
		}
		if(explode){
			print(set);
			cout << endl;
		}
	}
}*/

/*
int main() {
	int N, K, M, L;
	cin >> N >> K >> M >> L;
	vector<int> classes(N, 0);
	vector<int> smester(M, 0);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int classnum;
			cin >> classnum;
			classes[i] |= (1 << classnum);
		}
	}
	for (int i = 0; i < M; i++) {
		int num;cin >> num;
		for (int j = 0; j < num; j++) {
			int classnum;
			cin >> classnum;
			smester[i] |= (1 << classnum);
		}
	}
	int count = 0; stack<int> S;
	for (int i = 0; i < M; i++) {
		bool Go = false;
		for (int set = 0; set < (1 << N); set++) {
			if (((1 << set) & smester[i]) != 0) {
				if (classes[set] == 0){
					S.push(set); Go = true;
					classes[set] = -1;
				}
			}
		}
		if(Go)
			count++;
		while (!S.empty()) {
			int temp = S.top();
			S.pop();
			for (int j = 0; j < N; j++) {
				if ((classes[j]&(1<<temp)) != 0 && classes[j] > 0)
					classes[j] -= (1 << temp);
			}
		}
	}
	int Kcount = 0;
	for(int i =0; i< N; i++){
		if(classes[i] == -1)
			Kcount++;
	}
	if(Kcount >= K)
		cout << count << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}

*/
