#include <iostream>
#include <string>
#include <vector>
#include <persoana.h>
using namespace std;

class Carte {
private:
    string nume;
    string autor;
    Persoana *persoana_imprumuta;
public:
    Carte(const string &nume, const string &autor) : nume(nume), autor(autor) {
        persoana_imprumuta = nullptr;
    }

    bool operator==(const Carte &c) const {
        return c.autor == this->autor && c.nume == this->nume;
    }

    void imprumuta_la(Persoana *persoanaImprumuta) {
        persoana_imprumuta = persoanaImprumuta;
    }

    bool este_imprumutata() {
        return persoana_imprumuta != nullptr;
    }

    bool este_imprumutata_la(const Persoana *p) {
        return *persoana_imprumuta == *p;
    }

    friend ostream& operator<<(ostream& out, const Carte &c) {
        out << "Carte(nume=" << c.nume << ", autor=" << c.autor;
        if (c.persoana_imprumuta == nullptr) {
            out << ")";
            return out;
        }
        out << ", persoana=" << *(c.persoana_imprumuta) << ")";
        return out;
    }

};

class Biblioteca {
private:
    vector<Carte> carti_administrate;
public:
    void adauga_carte(const Carte &c) {
        carti_administrate.push_back(c);
    }

    void elimina_carte(const Carte &c) {
        for (auto i = carti_administrate.begin(); i != carti_administrate.end(); i++) {
            if (*i == c) {
                carti_administrate.erase(i);
                break;
            }
        }
    }

    bool imprumuta_carte(Persoana *p, const Carte &c) {
        for (auto &element: this->carti_administrate) {
            if (element == c && !element.este_imprumutata()) {
                element.imprumuta_la(p);
                return true;
            }
        }
        return false;
    }

    bool retur_carte(Persoana *p, const Carte &c) {
        for (auto &element: this->carti_administrate) {
            if (element == c && element.este_imprumutata_la(p)) {
                element.imprumuta_la(nullptr);
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& out, const Biblioteca &b) {
        out << "Biblioteca(";
        for (auto &element: b.carti_administrate) {
            out << element << ", ";
        }
        out << ")";
        return out;
    }
};

void afisare_status_imprumut(bool value) {
    if (value) {
        cout << "A fost imprumutata\n";
        return;
    }
    cout << "Nu a fost imprumutata\n";
}

int main() {
    Carte c1("carte1", "autor1");
    Carte c2("carte2", "autor2");
    Carte c3("carte3", "autor3");
    Biblioteca b = Biblioteca();
    b.adauga_carte(c1);
    b.adauga_carte(c2);
    b.adauga_carte(c3);
    cout << b << endl;

    b.elimina_carte(c1);

    cout << b << endl;

    Persoana p("persoana1");

    afisare_status_imprumut(b.imprumuta_carte(&p, c1));

    afisare_status_imprumut(b.imprumuta_carte(&p, c2));

    afisare_status_imprumut(b.imprumuta_carte(&p, c2));

    cout << b << endl;

    b.retur_carte(&p, c2);

    cout << b << endl;

    afisare_status_imprumut(b.imprumuta_carte(&p, c2));

    return 0;
}
