#include "../include/scara.h"

std::ofstream & operator<<(std::ofstream &out, const Scara &scara) {
    static_cast<std::ostream&>(out) << scara._numar << std::endl << scara._apartments.size() << std::endl;
    for (auto &apartment: scara._apartments) {
        out << apartment << std::endl;
    }
    return out;
}

std::ifstream & operator>>(std::ifstream &in, Scara &scara) {
    in >> scara._numar;
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        Apartament c;
        in >> c;
        scara._apartments.push_back(c);
    }
    return in;
}

std::ostream & operator<<(std::ostream &out, const Scara &scara) {
    out << "Scara(numar= " << scara._numar << "apartments = ";
    for (auto &aparment: scara._apartments) {
        out << aparment;
        out << ", ";
    }
    out << ")";
    return out;
}

void Scara::modificaApartament(const Apartament &apartament) {
    std::erase_if(_apartments, [apartament](const Apartament &m_apartament) {
       return m_apartament == apartament;
    });
    _apartments.emplace_back(apartament);
}
