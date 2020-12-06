#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.display();
    a.pop();
    a.display();

    stack<int> b;
    b = a;
    b.display();
    return 0;
}