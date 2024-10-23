#include "../include/angajat_permanent.h"

AngajatPermanent::AngajatPermanent(int nrZileRamaseAnulTrecut, const std::string &basic_string, const std::string &string, const Data &data)
        : Angajat(basic_string, string, data), nrZileRamaseAnulTrecut(nrZileRamaseAnulTrecut) {
}

AngajatPermanent::AngajatPermanent(const AngajatPermanent &other): Angajat(other),
                    nrZileRamaseAnulTrecut(other.nrZileRamaseAnulTrecut) {
}

AngajatPermanent & AngajatPermanent::operator=(const AngajatPermanent &other) {
    if (this != &other) {
        Angajat::operator=(other);
        nrZileRamaseAnulTrecut = other.nrZileRamaseAnulTrecut;
    }
    return *this;
}

void AngajatPermanent::citire(std::istream &in) {
    Angajat::citire(in);
    std::cout << "nrZileRamaseAnulTrecut= ";
    in >> nrZileRamaseAnulTrecut;
}

void AngajatPermanent::afisare(std::ostream &out) const {
    out << "AngajatPermanent(nrZileRamaseAnulTrecut= " << nrZileRamaseAnulTrecut << ", ";
    Angajat::afisare(out);
    out << ")";
}

int AngajatPermanent::nrZileLibereAnulCurent() const {
    return nrZileRamaseAnulTrecut + 21;
}
