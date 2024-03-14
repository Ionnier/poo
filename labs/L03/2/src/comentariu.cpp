//
// Created by Dragos BAHRIM on 14.03.2024.
//
#include <comentariu.h>
#include <iostream>
void Comentariu::adauga_comentariu(const string &mesaj) {
    comentarii.push_back(Comentariu(mesaj));
}

Comentariu::Comentariu(const string &mesaj) {
    this->mesaj = mesaj;
}

ostream &operator<<(ostream &out, const Comentariu c) {
    out << "Comentariu(mesaj = " << c.mesaj << ", ";
    for (auto &comentariu: c.comentarii) {
        out << comentariu << ", ";
    }
    out << ")";
    return out;
}