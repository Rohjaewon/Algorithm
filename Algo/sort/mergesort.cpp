#include <iostream>
#include <vector>
#include <random>
using namespace std;

int n;
vector<int> arr;

void mergesort(int lo, int hi) {
    if (lo == hi) return;
    int mid = (lo+hi)/2;
    mergesort(lo, mid);
    mergesort(mid+1, hi);
    int lefint = lo;
    int righint = mid+1;
    vector<int> temp;
    while (lefint <= mid && righint <= hi) {
        if (lefint <= mid && (righint > hi || arr[lefint] < arr[righint])) {
            temp.push_back(arr[lefint++]);
        } else {
            temp.push_back(arr[righint++]);
        } 
    }
    while (lefint <= mid) temp.push_back(arr[lefint++]);
    while (righint <= hi) temp.push_back(arr[righint++]);
    
    for(int i = lo; i <= hi; i++) {
        arr[i] = temp[i-lo];
    }
}

int main() {
    cin >> n;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100);
    for (int i = 0; i < n; i++) {
        int intemp = dis(gen);
        arr.push_back(intemp);
        cout << intemp << " ";
    } cout << endl;
    mergesort(0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}