#ifndef OOP_BIBLIOTECA_H
#define OOP_BIBLIOTECA_H
#include <iostream>
#include <carte.h>
#include <vector>
using namespace std;

class Biblioteca {
private:
    vector<Carte> carti_administrate;
public:
    void adauga_carte(const Carte &c);

    void elimina_carte(const Carte &c);

    bool imprumuta_carte(Persoana *p, const Carte &c);

    bool retur_carte(Persoana *p, const Carte &c);

    friend ostream& operator<<(ostream& out, const Biblioteca &b);
};
#endif //OOP_BIBLIOTECA_H
