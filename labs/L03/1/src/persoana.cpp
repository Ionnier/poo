#include <persoana.h>

Persoana::Persoana(const string &nume) {
    this->nume = nume;
}

ostream& operator<<(ostream& out, const Persoana &persoana) {
    out << "Persoana(nume=" << persoana.nume << ")";
    return out;
}

bool Persoana::operator==(const Persoana p) const {
    return p.nume == this->nume;
}