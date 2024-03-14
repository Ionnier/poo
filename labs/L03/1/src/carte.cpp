#include <carte.h>
#include <string>

using namespace std;

Carte::Carte(const string &nume, const string &autor) : nume(nume), autor(autor) {
    persoana_imprumuta = nullptr;
}

bool Carte::operator==(const Carte &c) const {
    return c.autor == this->autor && c.nume == this->nume;
}

void Carte::imprumuta_la(Persoana *persoanaImprumuta) {
    persoana_imprumuta = persoanaImprumuta;
}

bool Carte::este_imprumutata() {
    return persoana_imprumuta != nullptr;
}

bool Carte::este_imprumutata_la(const Persoana *p) {
    return *persoana_imprumuta == *p;
}

ostream &operator<<(ostream &out, const Carte &c) {
    out << "Carte(nume=" << c.nume << ", autor=" << c.autor;
    if (c.persoana_imprumuta == nullptr) {
        out << ")";
        return out;
    }
    out << ", persoana=" << *(c.persoana_imprumuta) << ")";
    return out;
}

istream &operator>>(istream &in, Carte &c) {
    cout << "nume= ";
    in >> (c.nume);
    cout << "autor= ";
    in >> (c.autor);
    return in;
}
