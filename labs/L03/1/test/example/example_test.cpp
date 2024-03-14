#include <gtest/gtest.h>
#include <persoana.h>
#include <biblioteca.h>

TEST(SuiteName, TestName) {
    Biblioteca b;
    EXPECT_EQ(b.numar_carti(), 0);
}

TEST(SuiteName, AdaugaCarte) {
    Biblioteca b;
    b.adauga_carte(Carte("asd", "bsd"));
    EXPECT_EQ(b.numar_carti(), 1);
}

TEST(SuiteName, ImprumutaCarte) {
    Biblioteca b;
    Carte c("asd", "bsd");
    b.adauga_carte(c);
    Persoana p("asd");
    b.imprumuta_carte(&p, c);
    EXPECT_EQ(b.numar_carti(), 1);
    EXPECT_EQ(b.numar_carti_imprumutate(), 1);
}

TEST(SuiteName, ReturCarte) {
    Biblioteca b;
    Carte c("asd", "bsd");
    b.adauga_carte(c);
    Persoana p("asd");
    b.imprumuta_carte(&p, c);
    EXPECT_EQ(b.numar_carti(), 1);
    EXPECT_EQ(b.numar_carti_imprumutate(), 1);
    b.retur_carte(&p, c);
    EXPECT_EQ(b.numar_carti(), 1);
    EXPECT_EQ(b.numar_carti_imprumutate(), 0);
}