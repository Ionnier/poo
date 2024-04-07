#include <gtest/gtest.h>
#include "mocks/mocka.h"

TEST(SuiteBTests, Test) {
    MockA a;

    EXPECT_CALL(a, doSomething(testing::_, testing::_))
            .Times(1)
            .WillRepeatedly(testing::Return(0));

    B b(a);

    EXPECT_EQ(5, b.doSomething(2, 2));
}