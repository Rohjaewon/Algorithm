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
    int left = lo;
    int right = mid+1;
    vector<int> temp;
    while (left <= mid && right <= hi) {
        if (left <= mid && (right > hi || arr[left] < arr[right])) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        } 
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= hi) temp.push_back(arr[right++]);
    
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
        int temp = dis(gen);
        arr.push_back(temp);
        cout << temp << " ";
    } cout << endl;
    mergesort(0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}