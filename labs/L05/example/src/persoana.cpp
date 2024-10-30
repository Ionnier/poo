#include "../include/persoana.h"

void Persoana::afisare(std::ostream &out) const {
    out << "Persoana(nume="<<_nume<<", prenume="<<_prenume << ", CNP="<< _cnp<<")";
}

void Persoana::citire(std::istream &in) {
    std::cout << "nume=";
    in >> _nume;
    std::cout << "prenume=";
    in >> _prenume;
    // in mod normal ar trebui folosit operatorul de citire, ca sa nu repetam logica
    // std::cout << "CNP\n";
    // in >> _cnp;

    // pastram exemplul pentru demonstratia de exceptii
    std::string cnp;
    while(true) {
        std::cout<<"cnp= ";
        in >> _cnp;
        try {
            _cnp = {_cnp};
            break;
        } catch (int s) {
            // daca s-ar arunca un int, s-ar oprii in acest loc

            // continua la urmatorul catch
        } catch (...) { // trateaza orice eroare care vine

        }
        // dupa tratarea oricarui bloc

    }
}

int Persoana::incomeLunar() {
    // functie care agregeaza functiile private de calculare income
    return calculareIncome();
}

int Persoana::calculareIncome() {
    // functie proprie care calculeaza strict pentru instanta de student
    return 0;
}
