#ifndef ADRESA_H
#define ADRESA_H

#include <string>
#include <iostream>
#include <fstream>

struct Adresa {
    std::string strada;
    std::string numar;

    Adresa(const std::string &strada = "", const std::string &numar = ""): strada(strada), numar(numar) {

    }

    friend std::ifstream& operator>>(std::ifstream& in, Adresa &adresa);
    friend std::ofstream& operator<<(std::ofstream& out, const Adresa &adresa);
    friend std::ostream& operator<<(std::ostream& out, const Adresa &adresa);

};

#endif //ADRESA_H
