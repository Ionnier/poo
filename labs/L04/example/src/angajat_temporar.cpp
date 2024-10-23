#include "../include/angajat_temporar.h"
AngajatTemporar::AngajatTemporar(const Data &dataIncheiere, const std::string &nume, const std::string &prenume, const Data &data_angajare):
    Angajat(nume, prenume, data_angajare), dataIncheiere(dataIncheiere){
}

int AngajatTemporar::nrZileLibereAnulCurent() const {
    int diffDays = abs(dataIncheiere.dayDifference(data_angajare)) / 30;
    return std::max(diffDays * 21 / 12, 21);;
}

void AngajatTemporar::afisare(std::ostream &out) const {
    out << "AngajatTemporar(dataIncheiere= " << dataIncheiere << ", ";
    Angajat::afisare(out);
    out << ")";
}

void AngajatTemporar::citire(std::istream &in) {
    Angajat::citire(in);
    std::cout << "dataIncheiere= ";
    in >> dataIncheiere;
}
