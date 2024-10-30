#ifndef ANGAJAT_H
#define ANGAJAT_H
#include "persoana.h"
#include <string>

class Angajat: public virtual Persoana {
public:
    Angajat(const std::string &nume, const std::string &prenume, const CNP &cnp, const std::string &functie,
        int salariu)
        : Persoana(nume, prenume, cnp),
          functie(functie),
          salariu(salariu) {
    }
    int incomeLunar() override;

protected:
    void afisare(std::ostream &) const override;
    void citire(std::istream &) override;
    int calculareIncome() override;

    std::string functie;
    int salariu;
};
#endif //ANGAJAT_H
