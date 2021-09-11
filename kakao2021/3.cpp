#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

const string IN = "IN";
const string OUT = "OUT";
const int LASTMINUTE = 1439;

int calculateTime(string time) {
    string hour = time.substr(0, time.find(":"));
    string minute = time.substr(time.find(":")+1);
    int hourT = stoi(hour);
    int minuteT = stoi(minute);
    return hourT * 60 + minuteT;
}

map<string, int> getTotalParkingTime(const vector<string> &records) {
    map<string, bool> isParked;
    map<string, int> currentParkedTime;
    map<string, int> totalParkedTime;
    for (string record : records) {
        string time = record.substr(0, record.find(" "));
        string temp = record.substr(record.find(" ")+1);
        string carNumber = temp.substr(0, temp.find(" "));
        string action = temp.substr(temp.find(" ")+1);

        if (action == IN) {
            isParked[carNumber] = true;
            currentParkedTime[carNumber] = calculateTime(time);
        } else {
            int parkedTime = calculateTime(time) - currentParkedTime[carNumber];
            auto found = totalParkedTime.find(carNumber);
            if (found == totalParkedTime.end()) {
                totalParkedTime[carNumber] = parkedTime;
            } else {
                totalParkedTime[carNumber] += parkedTime;
            }
            currentParkedTime[carNumber] = 0;
            isParked[carNumber] = false;
        }
    }
    for (auto checkParked : isParked) {
        if (checkParked.second) {
            totalParkedTime[checkParked.first] += (LASTMINUTE - currentParkedTime[checkParked.first]);
        }
    }
    return totalParkedTime;
}

vector<pair<string,int>> calculateFee(const vector<int> &fees, const map<string,int> &totalParkingTime) {
    vector<pair<string,int>> ret;
    for (auto parkTime : totalParkingTime) {
        cout << parkTime.first << " " << parkTime.second << endl;
        int time = parkTime.second;
        int extraTime = time - fees[0];
        if (extraTime <= 0) {
            ret.push_back(make_pair(parkTime.first, fees[1]));
        } else {
            int fee = fees[1] + ceil((float)extraTime / (float)fees[2]) * fees[3]; 
            ret.push_back(make_pair(parkTime.first, fee));
        }
    }
    return ret;
}

bool compareCar(pair<string, int> a, pair<string, int> b) {
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> totalParkingTime = getTotalParkingTime(records);
    vector<pair<string, int>> feePerCar = calculateFee(fees, totalParkingTime);
    sort(feePerCar.begin(), feePerCar.end(), compareCar);
    for (auto fee : feePerCar) {
        answer.push_back(fee.second);
    }
    return answer;
}

int main() {
    vector<int> fees {180, 5000, 10, 600};
    vector<string> records {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> answer = solution(fees, records);
    for (auto ret : answer) { 
        cout << ret << " ";
    } cout << endl;
}