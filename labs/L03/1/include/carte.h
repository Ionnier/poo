#ifndef OOP_CARTE_H
#define OOP_CARTE_H
#include <iostream>
#include <string>
#include <persoana.h>
using namespace  std;

class Carte {
private:
    string nume;
    string autor;
    Persoana *persoana_imprumuta;
public:
    Carte(const string &nume = "", const string &autor = "");

    bool operator==(const Carte &c) const;

    void imprumuta_la(Persoana *persoanaImprumuta);

    bool este_imprumutata();

    bool este_imprumutata_la(const Persoana *p);

    friend ostream& operator<<(ostream& out, const Carte &c);
    friend istream& operator>>(istream& in, Carte &c);

};
#endif //OOP_CARTE_H
