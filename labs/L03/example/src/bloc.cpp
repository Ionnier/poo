#include "../include/bloc.h"

std::ostream &operator<<(std::ostream &out, const Bloc &bloc) {
    bloc.afisare(out);
    return out;
}

std::istream &operator>>(std::istream &in, Bloc &bloc) {
    bloc.citire(in);
    return in;
}

void Bloc::afisare(std::ostream &out) const {
    out << "Bloc(adresa=" << _adresa << ", identificator = " << this->identificator << ", scari= ";
    for (auto &bloc: this->_scari) {
        out << bloc << ", ";
    }
    out << ")";
}

void Bloc::citire(std::istream &) {
}

bool Bloc::operator==(const Bloc &other) const {
    return other.identificator == this->identificator;
}

std::ofstream & operator<<(std::ofstream & out, const Bloc & bloc) {
    out << bloc._adresa << " " << bloc.identificator << std::endl;
    out << bloc._scari.size() << std::endl;
    for (auto &scara: bloc._scari) {
        out << scara << std::endl;
    }
    return out;
}

std::ifstream & operator>>(std::ifstream &in, Bloc & bloc) {
    in >> bloc._adresa >> bloc.identificator;
    int n;
    in >> n;
    for (int i = 0; i<n; i++) {
        Scara scara;
        in >> scara;
        bloc._scari.push_back(scara);
    }
    return in;
}

void Bloc::modificareScara(const Scara &scara) {
    std::erase_if(_scari, [scara](const Scara &mScara) {
       return mScara.numar() == scara.numar();
    });
    _scari.emplace_back(scara);
}
