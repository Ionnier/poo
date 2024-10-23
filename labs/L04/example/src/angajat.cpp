#include "../include/angajat.h"

int Angajat::id_seed = 0;

Angajat::Angajat(
    const std::string &nume,
    const std::string &prenume,
    const Data &data_angajare
):  nume(nume),
    prenume(prenume),
    data_angajare(data_angajare),
    id(id_seed++) {
}

Angajat::Angajat(const Angajat &other):
    nume(other.nume),
    prenume(other.prenume),
    data_angajare(other.data_angajare),
    id(other.id) {
}

Angajat & Angajat::operator=(const Angajat &other) {
    if (this != &other) {
        nume = other.nume;
        prenume = other.prenume;
        data_angajare = other.data_angajare;
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, const Angajat &other) {
    other.afisare(out);
    return out;
}

std::istream & operator>>(std::istream & in, Angajat &other) {
    other.citire(in);
    return in;
}

void Angajat::citire(std::istream &in) {
    std::cout << "nume= ";
    in >> nume;
    std::cout << "prenume= ";
    in >> prenume;
    in >> data_angajare;
}

void Angajat::afisare(std::ostream &out) const {
    out << "Angajat(id=" << id << ", nume="<< nume << ", prenume=" << prenume << ", data_angajare=" << data_angajare << ")";
}