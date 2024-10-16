#ifndef APARTAMENT_H
#define APARTAMENT_H
#include <string>
#include <fstream>

class Apartament {
public:
    Apartament(int numar = -1, double suprafata = -1)
        : _numar(numar), _suprafata(suprafata) {
    }

    Apartament(const Apartament&) = default;
    Apartament& operator=(const Apartament&) = default;
    ~Apartament() = default;

    friend std::ofstream& operator<<(std::ofstream&, const Apartament&);
    friend std::ifstream& operator>>(std::ifstream&, Apartament&);
    friend std::ostream& operator<<(std::ostream&, const Apartament&);

    bool operator==(const Apartament & apartament) const = default;

private:
    int _numar;
    double _suprafata;
};

#endif //APARTAMENT_H
