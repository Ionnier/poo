#include "../include/cnp.h"
#include <sstream>
#include "../include/judet.h"

bool CNP::isValid(const std::string &cnp) {
    if (cnp.length() != 13) {
        return false;
    }

    for (char c: cnp) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // validare prima cifra
    switch (cnp[0]) {
        case '7':
        case '8':
        case '9':
        case '0': {
            return false;
        }
        default: {

        };
    }

    // validare luna
    std::stringstream s;
    s << cnp[3];
    s << cnp[4];
    int luna;
    s >> luna;
    if (luna < 1  || luna > 12) {
        return false;
    }

    // partial validare zi
    s << cnp[5];
    s << cnp[6];
    if (luna < 1  || luna > 31) {
        return false;
    }

    // validare judet
    s << cnp[7];
    s << cnp[8];
    s >> luna;
    if (static_cast<Judet>(luna) != luna) {
        return false;
    }

    // int control[] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    // int suma = 0;
    // for (int i = 0; i < 12; ++i) {
    //     suma += (cnp[i] - '0') * control[i];
    // }
    // int cifra_control = suma % 11;
    // if (cifra_control == 10) {
    //     cifra_control = 1;
    // }
    // return cifra_control == (cnp[12] - '0');
    return true;
}

CNP::CNPInfo CNP::getInfoFrom(const std::string &cnp) {
    CNPInfo cnp_info;
    int ss = cnp[0] - '0';
    cnp_info.an = (cnp[1] - '0') * 10 + (cnp[2] - '0');
    cnp_info.luna = (cnp[3] - '0') * 10 + (cnp[4] - '0');
    cnp_info.zi = (cnp[5] - '0') * 10 + (cnp[6] - '0');
    int secol;

    switch (ss) {
        case 1:
        case 2: {
            secol = 1900;
            cnp_info.isMale = ss == 1;
            break;
        }
        case 3:
        case 4: {
            secol = 1800;
            cnp_info.isMale = ss == 3;
            break;
        }
        case 5:
        case 6: {
            secol = 2000;
            cnp_info.isMale = ss == 5;
            break;
        }
        default:
            throw "c";
    }
    cnp_info.an += secol;

    int cod_judet = (cnp[7] - '0') * 10 + (cnp[8] - '0');
    cnp_info.judet = static_cast<Judet>(cod_judet);
    return cnp_info;
}

void CNP::afisare(std::ostream &out) const {
    out << "CNP(cnp=" << _cnp << ")";
}

void CNP::citire(std::istream &in) {
    std::string cnp;
    while (true) {
        std::cout << "CNP =";
        in >> cnp;
        if (isValid(cnp)) {
            break;
        }
    }
    _cnp = cnp;
}
