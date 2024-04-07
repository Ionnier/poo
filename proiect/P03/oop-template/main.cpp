#include <iostream>
using namespace std;

void doSomething(const int &n) {
    for (int i = 0; i < n; ++i) {
        cout << ++i;
    }
}

int main() {
    doSomething(5);
}