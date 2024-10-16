#include "../include/adresa.h"

std::ifstream& operator>>(std::ifstream& in, Adresa &adresa) {
    in >> adresa.strada;
    in >> adresa.numar;
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const Adresa &adresa) {
    static_cast<std::ostream&>(out) << adresa.strada << " " << adresa.numar;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Adresa &adresa) {
    out << "Adresa(strada = " << adresa.strada << ", numar= " << adresa.numar << ")";
    return out;
}