#include "../include/angajat.h"

void Angajat::afisare(std::ostream &out) const {
    out << "Angajat(functie=" << functie << ", salariu=" << salariu << ", persoana=";
    Persoana::afisare(out);
}

void Angajat::citire(std::istream &in) {
    Persoana::citire(in);
    std::cout << "functie= ";
    in >> functie;
    std::cout << "salariu= ";
    in >> salariu;
}

int Angajat::incomeLunar() {
    return calculareIncome() + Persoana::incomeLunar();
}

int Angajat::calculareIncome() {
    return salariu;
}
