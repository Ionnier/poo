#include <iostream>
#include <utility>
using namespace std;

class A {
int x;
public:
    A(const int &x): x(x) {}

    [[nodiscard]] virtual int doSomething(const int &a, const int &b) const {
        return a + b;
    }
};

class B {
    A *a;
public:
    B(A &a): a(&a){}

    int doSomething(const int &x, const int &y) {
        return a->doSomething(x, y) + 5;
    }

};