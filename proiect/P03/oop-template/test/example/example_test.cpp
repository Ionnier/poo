#include <gtest/gtest.h>
#include "example.h"

TEST(SuiteName, TestName) {
    EXPECT_EQ(doSomething(10), 10);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}