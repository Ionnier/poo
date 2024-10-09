#include <iostream>
#include <numeric>

using namespace std;

// Definirea unei clase
// Obiect = instanta a unei clase
class Fractie {
    // e good practice ca toate functiile si variabilele publice sa fie declarate la inceputul clasei
public:
    // CONSTRUCTORI = AU SCOPUL DE A INITIALIZA OBIECTUL, ASTFEL INCAT SA FIE INTR-O STARE UTILIZABILA
    Fractie(); // constructor fara parametrii, el exista by default daca nu este declarat
    Fractie(int, int); // constructor cu parametrii

    // CONSTRUCTORUL DE COPIERE ESTE ABSOLUT NECESAR IN CAZUL IN CARE FOLOSIM ADRESE DE MEMORIE PENTRU DATELE MEMBRE
    Fractie(const Fractie &); // constructor de copiere, el exista by default daca nu este declarat

    // DESTRUCTORI = AU SCOPUL DE A FACE CLEAN-UP IN MOMENTUL IESIRII DIN EXECUTIE A OBIECTULUI, exista by default
    ~Fractie();

    // SUPRAINCARCAREA OPERATORULUI =, exista by default daca nu este declarat
    Fractie &operator=(const Fractie &);

    // functii / metode
    Fractie inversa() const;

    // SUPRAINCARCAREA ALTOR OPERATORII (ca functii membre)
    Fractie operator+(const Fractie &) const;

    Fractie operator-(const Fractie &) const;

    Fractie operator*(int) const;

    // SUPRAINCARCAREA OPERATORILOR (ca functii externe)
    // friend poate fi folosit pe functii sau pe clase pentru a permite accesul la date membre private

    friend Fractie operator*(const Fractie &, const Fractie &);

    friend Fractie operator/(const Fractie &, const Fractie &);

    friend ostream &operator<<(ostream &, const Fractie &);

    friend istream &operator>>(istream &, Fractie &);

    // GETTERS & SETTERS
    // SINGURA METODA DE ACCESA DATE MEMBRE PRIVATE
    // e de preferat sa nu existe si ca sa lucram doar cu metode bine stabilite
    [[nodiscard]] int numarator1() const {
        return numarator;
    }

    void set_numarator(int numarator) {
        this->numarator = numarator;
    }

    [[nodiscard]] int numitor1() const {
        return numitor;
    }

    void set_numitor(int numitor) {
        this->numitor = numitor;
    }

    // TOATE DATELE MEMBRE TREBUIE SA FIE PRIVATE
    // -> se ascunde structura interna si evita modificarea incorecta
private:
    int numarator;
    int numitor;

    // functii / metode private
    void afisare(ostream &) const;

    void citire(istream &);
};

// folositi lantul de initializare al constructorului pentru a initializa datele membre
// aceasta initializare se va face in momentul alocarii memoriei
Fractie::Fractie(): numarator(1), numitor(1) {
}

Fractie::Fractie(int numarator, int numitor): numarator(numarator), numitor(numitor) {
}


Fractie::Fractie(const Fractie &other): numarator(other.numarator), numitor(other.numitor) {
}

// se va folosii destructorul implicit (dar este declarat explicit)
// daca nu folosim alocari de memorie dinamica sau shared pointers nu este nevoie sa fie scrisi explicit
// daca avem, facem dezalocarile necesare
Fractie::~Fractie() = default;

Fractie &Fractie::operator=(const Fractie &other) {
    // previne dublu initializarea
    if (this == &other) {
        return *this;
    }
    this->numarator = other.numarator;
    this->numitor = other.numitor;
    return *this;
}

// functia este const, ea nu va modifica obiectul pe care este apelata
Fractie Fractie::inversa() const {
    return Fractie(this->numitor, this->numarator);
}


Fractie Fractie::operator+(const Fractie &other) const {
    int lcm = std::lcm(numitor, other.numitor);
    int numSum = numarator * (lcm / numitor) + other.numarator * (lcm / other.numitor);
    return Fractie(numSum, lcm);
}

Fractie Fractie::operator*(int multiplu) const {
    return Fractie(this->numarator * multiplu, this->numitor);
}

Fractie operator*(const Fractie &first, const Fractie &second) {
    return Fractie(first.numarator * second.numarator, first.numitor * second.numitor);
}

ostream &operator<<(ostream &out, const Fractie &fractie) {
    fractie.afisare(out);
    return out;
}

istream &operator>>(istream &in, Fractie &fractie) {
    fractie.citire(in);
    return in;
}

Fractie Fractie::operator-(const Fractie &other) const {
    return *this + (other * -1);
}

Fractie operator/(const Fractie &fractie, const Fractie &other) {
    return fractie * other.inversa();
}


void Fractie::afisare(ostream &out) const {
    out << "Fractie(numarator=" << this->numarator << ", numitor=" << this->numitor << ")";
}

void Fractie::citire(istream &in) {
    cout << "numarator = ";
    in >> this->numarator;
    cout << "numitor = ";
    in >> this->numitor;
}

int main() {
    Fractie fractie; // se apeleaza constructorul fara parametrii
    Fractie fractie2(1, 0); // se apeleaza constructorul cu parametrii

    Fractie fractie3(fractie); // se apeleaza constructorul de copiere
    Fractie fractie4 = fractie; // se apeleaza constructorul de copiere

    cin >> fractie;
    cout << "Fractia citita = " << fractie << endl;

    cout << fractie + fractie2 << endl;
    cout << fractie - fractie2 << endl;
    cout << fractie * fractie2 << endl;
    cout << fractie / fractie2 << endl;
    cout << fractie.inversa();

    return 0;
}

/* Clasa vector
 * - membri privati: fie pointer la adresa de memorie + numarul de elemente daca folositi alocare dinamica sau un element de tipul std::vector
 * - constructori: fara parametrii, cu parametrii
 * - constructor de copiere
 * - destructor
 * - supraincarcarea operatorilor << si >> si functii de citire si afisare
 * - operator =
 * - metoda publica pentru calcularea sumei tuturor elementelor
 * - metoda publica pentru a gasii indexul unui element dat
 * - metoda publica pentru a gasii maximul si pozitia sa
 * - metoda publica pentru sortare
*/
