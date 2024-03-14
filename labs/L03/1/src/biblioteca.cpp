#include <biblioteca.h>

void Biblioteca::adauga_carte(const Carte &c) {
    carti_administrate.push_back(c);
}

void Biblioteca::elimina_carte(const Carte &c) {
    for (auto i = carti_administrate.begin(); i != carti_administrate.end(); i++) {
        if (*i == c) {
            carti_administrate.erase(i);
            break;
        }
    }
}

bool Biblioteca::imprumuta_carte(Persoana *p, const Carte &c) {
    for (auto &element: this->carti_administrate) {
        if (element == c && !element.este_imprumutata()) {
            element.imprumuta_la(p);
            return true;
        }
    }
    return false;
}

bool Biblioteca::retur_carte(Persoana *p, const Carte &c) {
    for (auto &element: this->carti_administrate) {
        if (element == c && element.este_imprumutata_la(p)) {
            element.imprumuta_la(nullptr);
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& out, const Biblioteca &b) {
    out << "Biblioteca(";
    for (auto &element: b.carti_administrate) {
        out << element << ", ";
    }
    out << ")";
    return out;
}