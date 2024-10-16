#ifndef SCARA_H
#define SCARA_H
#include <string>
#include <vector>
#include "apartament.h"
class Scara {
public:
    Scara(const std::string &numar = "", const std::vector<Apartament> &apartments = {})
        : _numar(numar),
          _apartments(apartments) {
    }

    friend std::ofstream& operator<<(std::ofstream&, const Scara&);
    friend std::ifstream& operator>>(std::ifstream&, Scara&);
    friend std::ostream& operator<<(std::ostream&, const Scara&);

    [[nodiscard]] std::string numar() const {
        return _numar;
    }

    void modificaApartament(const Apartament&);

private:
    std::string _numar;
    std::vector <Apartament> _apartments;
};

#endif //SCARA_H
