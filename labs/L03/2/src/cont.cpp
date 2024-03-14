//
// Created by Dragos BAHRIM on 14.03.2024.
//
#include <cont.h>
Cont::Cont(const string &nume) {
    this->nume = nume;
}

ostream& operator<<(ostream& out, const Cont c) {
    out << "Cont(nume= " << c.nume <<", ";
    if (!c.abonatii.empty()) {
        out << "abonati = ";
        for (auto &abonat: c.abonatii) {
            out << (*abonat) << ", ";
        }
    }
    if (!c.videoclip.empty()) {
        out << "videoclipuri = ";
        for (auto &i: c.videoclip) {
            out << i << ", ";
        }
    }
    return out;
}

void Cont::adaugaVideoclip(const string &nume) {
    videoclip.push_back(Videoclip(nume));
}

void Cont::aboneza(Cont *cont) {
    abonatii.push_back(cont);
}

const string &Cont::getNume() const {
    return nume;
}

const vector<Cont *> &Cont::getAbonatii() const {
    return abonatii;
}

const vector<Videoclip> &Cont::getVideoclip() const {
    return videoclip;
}
