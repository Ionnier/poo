#ifndef CNP_H
#define CNP_H
#include <string>

#include "displayable.h"
#include "judet.h"
#include "readable.h"

class CNP: public Displayable, public Readable {
public:
    CNP(const std::string &cnp) {
        try {
            if (!isValid(cnp)) {
                throw "Invalid CNP";
            }
            // daca nu este valid, executia se opreste in linia de throw
            // cautand primul camp care trateaza eroare (sau un upcast al ei)
            // ajungand pana la opriprea executiei programului
            _cnp = cnp;
        } catch (std::string &message) {
            std::cout << message;
            // o eroare poate fi rearuncata;
            throw;
        }

    }

    static bool isValid(const std::string &cnp);
    struct CNPInfo {
        int an;
        int luna;
        int zi;
        bool isMale;
        Judet judet;
    };
private:


    static CNPInfo getInfoFrom(const std::string &cnp);
    std::string _cnp;

    void afisare(std::ostream &) const override;
    void citire(std::istream &) override;
};
#endif //CNP_H
