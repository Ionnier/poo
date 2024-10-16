#ifndef BLOC_H
#define BLOC_H
#include "adresa.h"
#include "scara.h"
#include <fstream>

class Bloc {
public:
    Bloc(const Adresa &adresa = {}, const std::string &identificator = "", const std::vector<Scara> &scari = {})
        : _adresa(adresa),
          identificator(identificator),
          _scari(scari) {
    }

    friend std::ostream& operator<<(std::ostream&, const Bloc&);
    friend std::istream& operator>>(std::istream&, Bloc&);
    friend std::ofstream& operator<<(std::ofstream&, const Bloc&);
    friend std::ifstream& operator>>(std::ifstream&, Bloc&);
    bool operator==(const Bloc&) const;
    void modificareScara(const Scara &);

private:
    Adresa _adresa;
    std::string identificator;
    std::vector<Scara> _scari;

    void afisare(std::ostream&) const;
    void citire(std::istream&);
};
#endif //BLOC_H
