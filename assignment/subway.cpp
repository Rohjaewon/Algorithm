/*
 * subway.cpp
 *
 *  Created on: 2018. 12. 13.
 *      Author: harry
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
const int MAX = 1000;
int error = 0;//원하는 역에 도달할 수 있는지 여부를 알려주는 변수

typedef struct time{//분, 초의 정보를 가지고 있는 time구조체
	int second = 0;
	int minute = 0;
}time;
typedef struct subinfo{//걸리는 시간과 호선이 몇번인지 저장하는 subinfo구조체
	int line = 0;
	time subtime;
}subinfo;



int FindStation(vector<string> subName, string sub){//subName vector로 지하철역의 번호를 찾아서 return해준다.
	unsigned int size = subName.size();
	for(unsigned int i = 0; i<size; i++){
		if(subName[i] == sub)
			return i;
	}
	return -1;
}

bool timeCompare(time left, time right){//time 구조체 비교 기준 설정 -> minute 먼저 비교 후 second 비교
	if(left.minute < right.minute)
		return true;
	else if(left.minute > right.minute){
		return false;
	}
	else{
		if(left.second < right.second)
			return true;
		else
			return false;
	}
}

int FindMin(subinfo** subway, vector<time> Dist, vector<bool>& visited){//현재 Dist 값중 가장 작은 Dist의 지하철 찾기
	unsigned int size = Dist.size();
	time min; int index = -1;
	min.minute = MAX; min.second = MAX;
	for(unsigned int i =0; i <size; i++){
		if(visited[i] == false){
			if(timeCompare(Dist[i], min)){
				min = Dist[i];
				index = i;
			}
		}
	}
	if (index == -1) {//더이상 이동할 선로가 없을 경우
		cout << "-1";
		error = 1;
	}
	else
		visited[index] = true;//
	return index;
}
void Dijkstra(subinfo** subway, int size, vector<bool>& visited, string v1, string v2, vector<string> subName){
	vector<time> Dist(size);//집합 S로부터 걸리는 최소 시간을 저장한 vector
	for(int i =0; i<size; i++){
		Dist[i].minute = MAX;
		Dist[i].second = MAX;
	}//처음에 모든 시간을 MAX로 초기화
	int S = 0;
	vector<int> parent(size, -1);//현재 지하철 경로에서 바로 전 역의 번호를 저장하는 vector
	stack<int> route;
	//시작역과 도착역의 번호를 미리 찾아놓음
	int start = FindStation(subName, v1);
	int end = FindStation(subName, v2);

	Dist[start].minute = 0; Dist[start].second = 0; //start는 걸리는 시간을 0으로 초기화
	visited[start] = true;//start를 S집합에 포함
	S = start;//S는 start부터 시작

	while (S != end) {//S가 종착역에 갈때까지 이동
		for (int i = 0; i < size; i++) {
			if (subway[S][i].line != 0) { //인접할 경우
				if (visited[i] == false) { //S집합이 아닌 정점인 경우
					time temp;
					temp.minute = Dist[S].minute + subway[S][i].subtime.minute;
					temp.second = Dist[S].second + subway[S][i].subtime.second;
					if(temp.second >= 60){//second가 60초가 넘으면 minute에 +1 하고 second에 -60
						temp.second -= 60;
						temp.minute += 1;
					}
					if (timeCompare(temp, Dist[i])) {//원래의 i까지의 경로와 다른 방법의 i까지의 경로와 비교해서 다른 방법의 경로가 더 작으면 경로의 길이와 parent 갱신
						Dist[i] = temp;
						parent[i] = S;
					} //if
				} //if
			} //if
		} //for 수행시간 : O(n)
		int min = FindMin(subway, Dist, visited); //수행시간 : O(n)
		if(error == 1)//경로가 없는 경우
			break;
		S = min;
	} //while 수행시간 : O(n-1) 최대 n-1번 돈다.
	if (error != 1) {//최단 경로와 시간을 출력
		int index = end;
		while (index != -1) {//parent의 저장된 값을 따라가면서 출발역까지 route 스택에 저장
			route.push(index);
			index = parent[index];
		}
		cout << "Time : " << Dist[end].minute << "분 " << Dist[end].second << "초"
				<< endl;
		int vertex1 = route.top();
		route.pop();
		int vertex2 = route.top();
		route.pop();
		int line = subway[vertex1][vertex2].line;
		cout << line << "호선 " << subName[vertex1] << " " << subName[vertex2]
				<< " ";
		while (!route.empty()) {
			vertex1 = route.top();
			int line2 = subway[vertex2][vertex1].line;
			if (line != line2) {//환승여부를 확인
				cout << "(환승" << line2 << "호선) ";
				line = line2;
			}
			route.pop();
			cout << subName[vertex1] << " ";
			vertex2 = vertex1;
		}
	}
}


int main(){
	int n; cin >> n; int size = 2*n;//선로개수가 n일 때 역 개수는 최대 2*n개이다.
	vector<string> subName(size);//지하철역 이름과 번호를 관리하는 vector
	vector<bool> visited(size, false);//S집합에 들어온 지하철 역을 관리해주는 vector, S집합에 포함되면 visited를 1로하여 더이상 방문하지 않도록 한다.
	subinfo** subway = new subinfo* [size];//지하철 인접행렬 그래프
	for(int i =0; i<size; i++){
		subway[i] = new subinfo[size];
		visited[i] = false;
	}
	int subnum = 0;
	for(int i =0; i<n; i++){
		int line; time taketime; string v1, v2;
		cin >> line; cin >> v1 >> v2; cin >> taketime.minute >> taketime.second;
		int subflag = -1, subflag2 = -1;
		int v1index = -1, v2index =-1 ;
		for(unsigned int j = 0; j<subName.size(); j++){
			if(subName[j] == v1){
				v1index = j;
				subflag = 1;
			}
			if(subName[j] == v2){
				v2index=j;
				subflag2 = 1;
			}
		}
		if(subflag == -1){
			subName[subnum] = v1;
			v1index=subnum;
			subnum++;
		}if(subflag2 == -1){
			subName[subnum] = v2;
			v2index = subnum;
			subnum++;
		}
		subway[v1index][v2index].line = line;
		subway[v1index][v2index].subtime = taketime;


		subway[v2index][v1index].line = line;
		subway[v2index][v1index].subtime = taketime;
	}//인접행렬로 그래프 만들기

	string start, end; int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> start >> end; error =0;
		cout << "출발역 :" << start << " " << " 종착역 :" << end << endl;
		Dijkstra(subway, size, visited, start, end, subName); cout << endl;
		for(int j =0; j<size; j++)
			visited[j] = false;
	}
}


