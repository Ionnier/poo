//
// Created by Dragos BAHRIM on 14.03.2024.
//
#include <videoclip.h>
#include <iostream>

Videoclip::Videoclip(const string nume) {
    this->nume = nume;
}

ostream &operator<<(ostream &out, const Videoclip v) {
    out << "Videoclip(nume = " << v.nume << ", ";
    for (auto &comentariu: v.comentarii) {
        out << comentariu << ", ";
    }
    out << ")";
    return out;
}