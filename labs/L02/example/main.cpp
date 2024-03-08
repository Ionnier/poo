#include <iostream>

class SirInt {
    int n;
    int *V;
public:
    SirInt();
    SirInt(int &n) {
        this->n = n;
        V = new int[n];
    }

    ~SirInt() {
        n = 0;
        delete[]V;
    }

    void addElement(int &x) {
        int *aux = new int[n + 1];
        for (int i = 0; i < n; i++) {
            aux[i] = V[i];
        }
        aux[n] = x;
        delete[] V;
        V = aux;
        n++;
    }

    void removeElement() {
        n--;
        int *aux = new int[n];
        for (int i = 0; i < n; i++) {
            aux[i] = V[i];
        }
        delete[] V;
        V = aux;
    }

    int &getN() {
        return n;
    }

    friend std::ostream &operator<<(std::ostream &o, const SirInt &p) {
        for (int i = 0; i < p.n; i++) {
            o << p.V[i] << " ";
        }
        return o;
    }

    void citire(std::istream &in);

    friend std::istream &operator>>(std::istream &i, SirInt &p) {
        p.citire(i);
        return i;
    }

};

void SirInt::citire(std::istream &in) {
    std::cout << "nr elemente= ";
    in >> n;
    if (V != nullptr) {
        delete[] V;
    }
    if (n <= 0) {
        return;
    }
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        std::cout << "V[" << i << "]=";
        in >> aux[i];
    }
    this->V = aux;
}

SirInt :: SirInt() {
    n = 0;
    V = nullptr;
}

SirInt& SirInt::operator=(const SirInt &aux) {
    this->n = aux.n;
    if (V != nullptr) {
        delete[] V;
    }
    V = new int[n];
    for (int i = 0; i < n; i++) {
        V[i] = aux.V[i];
    }
    return *this;
}

SirInt& SirInt::operator=(const SirInt &aux) {
    this->n = aux.n;
    if (V != nullptr) {
        delete[] V;
    }
    V = new int[n];
    for (int i = 0; i < n; i++) {
        V[i] = aux.V[i];
    }
    return *this;
}

class MatriceInt {
private:
    int n;
    SirInt *p;
public:
    MatriceInt() {
        n = 0;
        p = nullptr;
    }

    ~MatriceInt() {
        // optionala
        this->n = 0;
        delete[]p;
    }

    friend std::istream &operator>>(std::istream &in, MatriceInt &aux) {
        std::cout << "n=";
        in >> aux.n;
        aux.p = new SirInt[aux.n];
        for (int i = 0; i < aux.n; i++) {
            in >> aux.p[i];
        }
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, MatriceInt &aux) {
        for (int i = 0; i < aux.n; i++) {
            out << aux.p[i];
        }
        return out;
    }
};


// int main() {
//     MatriceInt x;
//     std::cin >> x;
//     std::cout << x;

// }


class Carte {
private:
    std::string name;
    std::string author;
    int year;
public:
    Carte(const std::string &name = "", const std::string &author = "", const int &year = 2024) {
        this->name = name;
        this->author = author;
        this->year = year;
    }

    Carte(const Carte &aux) {
        this->name = aux.name;
        this->author = aux.author;
        this->year = aux.year;
    }

    friend std::istream &operator>>(std::istream &in, Carte &d) {
        in >> d.name;
        in >> d.author;
        in >> d.year;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Carte &d) {
        out << d.name;
        out << d.author;
        out << d.year;
        return out;
    }

    friend bool operator==(const Carte &c, const Carte &d) {
        return c.author == d.author &&
               c.name == d.name &&
               c.year == d.year;
    }

    friend Carte& operator+(const Carte &c, const Carte &d) {
        Carte *aux = new Carte(c.author + d.author, c.name + d.name, c.year + d.year);
        return *aux;
    }

    int genereazaSimilaritate() const {
        return 0;
    }


};

int main() {
    // Carte C("BookName", "AuthorName", 2024);

    // Carte D;

    // std::cin >> D;

    // if (C == D) {
    //     std::cout << "Cartile sunt la fel";
    //     return 1;
    // }

    // std::cout << D.genereazaSimilaritate();

    // Carte e = C + D;

    // std::cout << e;
}
