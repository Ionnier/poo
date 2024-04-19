## Laborator 7

### Programare generica in C
```c
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int comparator(const void *a, const void *b) {
    return ( *(const int*)a - *(const int*)b );
}

int main() {
    // malloc intoarce un pointer void* (generic) pe care il convertim la int*
    int *n = (int *) malloc(sizeof(int) * 5);
    n[0] = 5;
    n[1] = 3;
    n[2] = 4;
    n[3] = 6;
    n[4] = 10;
    
    // qsort primeste ca argument
    //    adresea de memorie de inceput
    //    numarul de elemente 
    //    dimensiunea unui element
    //    o functie cu semnatura int cmp(const void * e1, const void * e2)
    //       returneaza 0 daca cele doua elemente sunt identice
    //       returneaza <0 daca e1 trebuie sa fie inaintea lui e2
    //      returneaza >0 daca e1 trebuie sa fie dupa e2
    qsort(n, 5, sizeof(int), comparator);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", n[i]);
    }
    
    printf("\n");

    return 0;
}
```


### Funcții generice

#### Motivație

Considerăm următoarea funcție

```c++
int sum(const int &x, const int &y) {
    return x + y;
}
```

În interiorul funcției nu folosim nimic specific unui `int` (presupunând că ar avea constructori sau alte metode).

Dacă am vrea să creăm o funcție asemănătoare dar pentru alt tip de dată, funcția ar arăta a asemănător.

```c++
double sum(const double &x, const double &y) {
    return x + y;
}
```

Astfel, creăm comportament identic însă care trebuie să îl copiem în altă parte.

#### Soluție? Funcții generice

```c++
template <typename T>
T sum(const T &x, const T &y) {
    return x + y;
}
```

Cu `typename` specificăm tipul de tată folosit în interiorul funcției.

În general, în interiorul unei funcții template lucrăm doar cu operatorii claselor pe care le folosim.

#### Cum funcționează?

În timpul compilării, în momentul în care folosim funcția oriunde, se vor genera funcțiile pe care le folosim prin intermediul template-ului.

```c++
template <typename T>
T sum(const T &x, const T &y) {
    return x + y;
}

class A {
private: 
int x;

public:
    A(const int &x): x(x) {
        
    }
    friend std::ostream& operator<<(std::ostream &out, const A &aux) {
        out << "A(x=" << aux.x << ")";
        return out;
    }
    
    int operator+(const A &x) const {
        return this->x + x.x;
    }


};


int main() {
    std::cout << sum(5, 6) << std::endl; // 11
    std::cout << sum(5.0, 6.0) << std::endl; // 11.0
    
    A a(5),b(6);
    std::cout << sum(a, b) << std::endl; // A(x=11)

    return 0;
}
```

în locul template-ului se vor genera în spate următoarele funcții

```c++
int sum(const int &x, const int &y) {
    return x + y;
}

double sum(const double &x, const double &y) {
    return x + y;
}

A sum(const A &x, const A &y) {
    return x + y;
}
```

E important să gândiții orice generați prin template-uri ca fiind instanțe separate a ceea ce vreți să generați.

```c++
template <typename T>
int doSomething(const T& a) {
    static int i;
    i += int(a);
    return i;
}

int main() {
    doSomething(5);
    std::cout << doSomething(6.0);
}
```

#### Specializare

Putem să rescriem o funcție template, pentru a avea un comportament specific.

Compilatorul nu va mai genera funcția template pentru acel tip de dată.

```c++
template <typename T>
T sum(const T &x, const T &y) {
    return x + y;
}

class A{
public:
    friend std::ostream& operator<<(std::ostream& out, const A &x) {
        return out;
    }
};
template <>
A sum(const A &x, const A &b) {
    return x;
}

int main() {
    A a, b;
    std::cout << sum(a, b);
    return 0;
}
```

#### Template-uri cu mai multe argumente

```c++
template <typename T, typename Y>
T sum(const T &x, const Y &y) {
    return x + y;
}
```


#### Prioritizarea funcțiilor în contextul template-urilor

```c++
template <typename T, typename Y>
T doSomething(const T &x) {
    return x + 2;
}

template <typename T>
T doSomething(const T &x) {
    return x + 1;
}

template<>
int doSomething(const int &x) {
    return x;
}

int doSomething(const int &x) {
    return x - 1;
}

double doSomething(const double &x) {
    return x - 2;
}

int main() {
    std::cout << doSomething(5);
}

```

### Clase generice

Asemănător ca la funcții.

```c++
template <typename T = int>
class SirInt {
    int n;
    T *V;
public:
    SirInt();
    SirInt(int &n) {
        this->n = n;
        V = new T[n];
    }

    ~SirInt() {
        n = 0;
        delete[]V;
    }

    void addElement(const T &x) {
        T *aux = new T[n + 1];
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
        T *aux = new T[n];
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
    
    SirInt& operator=(const SirInt<T> &aux) {
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

};
template <typename T>
void SirInt<T>::citire(std::istream &in) {
    std::cout << "nr elemente= ";
    in >> n;
    if (V != nullptr) {
        delete[] V;
    }
    if (n <= 0) {
        return;
    }
    int *aux = new T[n];
    for (int i = 0; i < n; i++) {
        std::cout << "V[" << i << "]=";
        in >> aux[i];
    }
    this->V = aux;
}

template <typename T>
SirInt<T> :: SirInt() {
    n = 0;
    V = nullptr;
}

int main() {
    SirInt<> i;
    i.addElement(1);
    std::cout << i;
    
    SirInt<double> d;
    d.addElement(5.5);
    std::cout << d;

    return 0;
}
```

#### Argumente default la template-uri

```c++
template <typename T, typename U=int>
class A {

};

int main() {
    A<float> s;
    // echivalent cu
    A<float, int> d;
}
```

#### Clasele generice sunt tot clase

Astfel putem face tot ce am putea face cu niste clase normale

```c++
template<class T> class A;
template<class T>
std::ostream& operator<<(std::ostream&, const A<T>&);
    
template <typename T>
class A{
    T x;
public:
    A(const T&);
    virtual ~A() = default;
    virtual void afisare(ostream &) const;
    
    friend ostream& operator<< <>(ostream& out, const A<T> & x);
};

template<typename T>
A<T>::A(const T& x):x(x) {
    
};


template<typename T>
void A<T>::afisare(ostream & out) const {
    out << "A(x= " << x <<")";
}

template<typename T>
ostream& operator<< (ostream& out, const A<T> &x) {
    x.afisare(out);
    return out;
}

template <typename T, typename U>
class B: public A<T>{
    U y;
public:
    B(const T &x, const U &y): A<T>(x), y(y) {
        
    }
    void afisare(ostream & out) const {
        out << "B(";
        A<T>::afisare(out);
        out << ", y=" << y <<")";
    }
};

int main() {
    A<int> a(1);
    B<int, float> b(1, 2.5);
    B<int, int> c(1, 4);
    
    A<int>* p= &b;
    B<int, float> *pp = dynamic_cast< B<int, float>* >(p);
    if (pp != nullptr){
        cout << *p << endl;
    }
    
    A<int>* ppp = dynamic_cast< A<int>* >(&c);
    if (ppp != nullptr) {
        cout << *ppp << endl;
    }
}
```



### Warnings & others

[via @mcmarius](https://github.com/mcmarius/poo/tree/master/tema-3#templates)

### STL

[random article](https://abhiarrathore.medium.com/the-magic-of-c-stl-standard-template-library-e910f43379ea)

[iterators](https://www.programiz.com/cpp-programming/iterators)