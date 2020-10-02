/*
 * algo2.cpp
 *
 *  Created on: 2018. 10. 30.
 *      Author: harry
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> arr;
int tiling(int n)
{
    int answer = 0;
  if(n % 2 == 0)
  {

    arr.push_back(1);
    int idx = n / 2;
    for(int i = 1; i <= idx; ++i)
    {
      arr.push_back(3 * arr[i - 1]);
      for(int j = 0; j < i - 1; ++j)
      {
        arr[i] = (arr[i] + (2 * arr[j])) % 100000;
      }
    }
    answer = arr[idx];
  }

    return answer;
}
int main()
{
    int test = 10;

    cout<< tiling(test)<<endl;
    for(int i =0; i<test; i++)
    	cout << arr[i] << " ";
    cout << endl;
}
