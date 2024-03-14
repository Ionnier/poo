//
// Created by Dragos BAHRIM on 14.03.2024.
//

#ifndef OOP_CONT_H
#define OOP_CONT_H
#include <videoclip.h>
#include <iostream>

class Cont {
private:
    string nume;
    vector<Cont *> abonatii;
    vector<Videoclip> videoclip;
public:
    Cont(const string &nume);
    friend ostream& operator<<(ostream& out, const Cont c);
    void adaugaVideoclip(const string &nume);
    void aboneza(Cont *cont);

    const string &getNume() const;

    const vector<Cont *> &getAbonatii() const;

    const vector<Videoclip> &getVideoclip() const;

};

#endif //OOP_CONT_H
