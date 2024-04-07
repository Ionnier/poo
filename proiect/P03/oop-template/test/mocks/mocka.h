#include <gmock/gmock.h>
#include <ex.cpp>
#include <gtest/gtest.h>

class MockA: public A {
public:
    MockA() : A(1) {}
//    int doSomething(const int &a, const int &b) override
    MOCK_METHOD(int, doSomething, (const int &a, const int &b), (const, override));
};