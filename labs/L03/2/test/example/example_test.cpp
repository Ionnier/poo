#include <gtest/gtest.h>
#include "example.h"
#include <cont.h>

TEST(SuiteName, Constructor) {
    string asd = "asdsa";
    Cont c(asd);
    EXPECT_EQ(c.getNume(), asd);
}

TEST(SuiteName, Abonare) {
    Cont c("asdasdd");
    Cont c2("asdasdd");
    c.aboneza(&c2);
    EXPECT_EQ(c.getAbonatii().size(), 1);
}

TEST(SuiteName, AdaugareVideoclip) {
    Cont c("asdasdd");
    c.adaugaVideoclip("asdasdsa");
    EXPECT_EQ(c.getVideoclip().size(), 1);
}

