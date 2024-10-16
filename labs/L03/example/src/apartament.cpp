#include "../include/apartament.h"

std::ofstream & operator<<(std::ofstream &out, const Apartament &apartament) {
    static_cast<std::ostream&>(out) << apartament._numar << " " << apartament._suprafata;
    return out;
}

std::ifstream & operator>>(std::ifstream &in, Apartament &apartament) {
    in >> apartament._numar >> apartament._suprafata;
    return in;
}

std::ostream & operator<<(std::ostream &out, const Apartament &apartament) {
    out << "Apartament(numar= " << apartament._numar << ", suprafata= " << apartament._suprafata<<")";
    return out;
}
