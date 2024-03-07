# Laborator 2

## Mic recap C/C++

```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Declararea unui struct
struct Student {
    int nr_matricol;
    string nume;
}
// Declararea unei variabile de tipul struct-ului se poate face si dupa definitia acestuia
  s;

int main() {

    // Afisarea unui mesaje in consola
    cout << "nr_matricol =";

    // Citirea unui numar de la tastatura
    cin >> s.nr_matricol;

    // Afisarea altui mesaj
    cout << "nume = ";

    // Citirea unui singur cuvant de la tastatura
    cin >> s.nume;

    // Daca introducem mai multe cuvinte, ele raman in buffer, la urmatoarea citire acestea vor fi luate in considerare
    // Daca nu sunt alte cuvinte, se va astepta input de la utilizator
    cin >> s.nume;

    // Atunci cand citim, caracterul pentru ENTER ramane in buffer, il eliminam folosind cin.get
    // Nu ne-a afectat la celelalte intrucat nu s-a acceptat input de marime 0
    cin.get();

    // Citirea mai multor cuvinte se poate face folosind getLine ce va citii pana la '\n'
    // Aceasta va indeparta automat caracterul ENTER din buffer
    getline(cin, s.nume);

    // Declarea unui vector de studenti alocat static (in stiva)
    // Alocarea este mai rapida, este facuta la compile time
    // Dezalocarea se face la iesirea din scope
    Student studenti[100];

    // Declararea unui vector de studenti alocat dinamic (in heap)
    // Alocarea este facuta in timpul rularii
    // Dezalocarea se face manual folosind delete
    // Se folosesc tool-uri pentru verificarea memory leak-uri -> Valgrind (Linux)
    Student *studenti2 = new Student[100];

    // Dezalocare unui sir alocat dinamic
    delete []studenti2;


    // [] este folosit doar atunci cand dezalocam un sir
    Student *aux = new Student;
    delete aux;


    // Declararea unui fisier de intrare
    ifstream input("input.txt");

    input >> s.nr_matricol;
    getline(input, s.nume);

    // Inchidem fisierul dupa ce terminam de citit
    input.close();

    // Declararea unui fisier de afisare
    ofstream output("output.txt");

    output << s.nume << " " << s.nr_matricol;

    // Inchidem fisierul dupa ce terminam de afisat
    // Folosim flush daca vrem sa scriem si sa nu il inchidem momentan
    output.close();

    // Daca nu avem un return definit, avem unul implicit
}
```
## C++ additions

### Supraîncărcarea funcțiilor

Putem definii funcții în același scope cu același nume dar ce primesc argumente diferite.

Supraîncărcarea nu este posibilă doar prin tipul de date de ieșire.

```c++
void doSomething(int x, int y) {
    // ...
}

void doSomething(int y) {
    // ...
}

//int doSomething(int y) {
// error: functions that differ only in their return type cannot be overloaded
// }
```

### Pasarea prin referință

Pentru a evita copierea inutilă a obiectelor (ca argumente) sau pentru modificarea mai ușoară a variabilelor folosite în interioriul funcțiilor (evitând folosirea de pointeri)

```c++
void doSomething(int &refX) {
    refX += 1;
}

int main() {
    int x = 5;
    doSomething(x);
    // x is now 6
}
```

### Argumente implicite
Atunci când scriem o funcție, putem să setăm pentru ultimele argumente valori implicite.

Atunci când apelăm funcția, putem omite argumentele implicite.

Atenție! Nu putem sării peste argumente. 

```c++
// x va trebui sa primeasca de la tastatura mereu valori
// y si z pot fi omise
// cand apelam functia, nu putem sarii peste y, sa isi pastreaza valoarea implicita si sa o schimbam pe cea pentru z
void doSomething(int x, int y = 3, int z = 5) {
    // ...
}

int main() {
    // x primeste valoarea 6
    // y primeste valoare 2
    // z foloseste valoarea implicita 5
    doSomething(6, 2);
}
```

### Alocarea dinamica prin new si delete

Au avantajul ca apeleaza constructorul fara parametrii

```c++
Student *p = new Student(2); // Apeleaza constructorul cu parametrii 
Student studenti = new Student[100]; // Apeleaza constructorul fara parametrii pentru fiecare element din sir

// Pentru a elibera memoria ( + apelare destructor)
delete p;
delete []studenti;
```

## Clase & Obiecte

**Clasele** reprezinta un schelet pentru un *obiect*.

### Definirea unei clase

Definirea unei clase se face folosind keyword-ul **class**

```c++
class Student{
    
};
```

### Crearea obiectelor

Un **obiect** este o instanță a unei clase.

Pentru a crea un obiect, trebuie sa apelam **constructorul** clasei. O clasa poate avea mai mulți constructori prin **supraîncărcarea funcțiilor**.

Prin constructor creăm o instanță a unei clase și are rol de inițializare.

Definirea unui constructor se face creând o metodă cu acelși nume ca al clasei.

**Destructorul** se apeleaza automat in momentul in care obiectul creat va fi distrus. Are ca scop efectuarea unui clean-up (în special a memoriei alocate dinamice)

Definirea unui destructor se face creând o metoduă cu același nume ca  al clasei precedat de ~.

Fiind metode speciale, constructor-ul si destructor-ul nu au definit un tip de ieșire.

```c++
#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    int nr_matricol;
    string nume;
public:

    // Declararea unui constructor
    Student(int nr_matricol, string nume) {
        this->nr_matricol = nr_matricol;
        this->nume = nume;
    }

    // Declararea unui destructor
    ~Student() {
        nr_matricol = 0;
        nume.clear();
    }

} // Se apeleaza constructorul pentru s1
s1 (1, "1");

int main() {
    // Se apeleaza constructorul pentru s2
    Student s2 (2, "3");

    // Se apeleaza destructorul pentru s2
}

// Se apeleaza destructorul pentru s1
```

### Metode implicite

Orice clasa are implicit daca nu are deja definit:
 * un constructor fara parametrii
 * un constructor de copiere ()
 * un destructor
 * supraincarcarea operatorului de asignare (=)

Astfel, codul urmator este valid:

```c++
class Student{

};

int main() {
    // Instantierea clasei Student, se apeleaza constructorul fara parametrii
    Student s;

    // Apelarea constructorului de copiere
    Student s2(s);
    Student s3 = s;

    // Apelarea constructorului fara parametrii
    Student s4;

    // Apelarea operatorului se asignare
    s4 = s2;

    // Apelarea destructorului in ordinea inversa a definirii
    // Se apeleaza destructorul pentru s4
    // Se apeleaza destructorul pentru s3
    // Se apeleaza destructorul pentru s2
    // Se apeleaza destructurul pentru s1
}
```

### Date membre & functii membre (metode) 

Clasele pot sa **encapsuleaza** alte variabile si functii.

```c++
class Student{
    int nr_matricol;
    string nume;
    void doSomething();
};
```

### Vizibilitate

Vizibilitatea unei date membre sau a unei metode se refera de locul de unde poate sa fie accesata

| Specificator de access      | Efect |
| ----------- | ----------- |
| private      | poate fi accesat doar in interiorul clasei |
| protected    | poate fi accesat doar in interiorul clasei, sau din interiorul unei clase derivate|
| public | poate fi accesat fie din clasa, fie din obiect|

Implicit, toate datele definite in clasa sunt **private**.

```c++
class Student{
// private: -> Nu este necesar intrucat datele sunt implicit private, însă îl putem pune pentru vizibilitate

/* 
  Date membre & functii private
*/

protected:

/* 
  Date membre & functii protected
*/

// Se aplica pentru toate pana la urmatorul specificator de access

public:

/* 
  Date membre & functii publice
*/

private: 
// Putem revenii oricand la alta vizibilitate
};
```

### Lucrul cu metode

O metoda a unei clase are access la toate datele si metodele definite in cadrul acesteia.

In interiorul unei metode datele membre pot fi accesate direct, cat timp nu exista un conflict de nume (shadowing).

In cazul in care acest lucru se intampla, putem folosii pointer-ul **this** care permite accesul la clasa carei ii corespunde metoda.

``` c++
#include <iostream>
using namespace std;

class Student{
private:
    int nr_matricol;
    void exemplu_functie_privata() {

    }
public:
    // Functie setter pentru nr_matricol
    void setNrMatricol(int nr_matricol) {
        // Intrucat argumentul are acelasi nume ca o data membra, aceasta nu poate fi folosita direct
        // Folosim pointer-ul this pentru a accesa aceste date
        this->nr_matricol = nr_matricol;
    }

    void increaseNrMatricol() {
        // Se apeleaza asupra datei membre intrucat in acest scope nu exista alt nr_matricol definit.
        nr_matricol++;
        exemplu_functie_privata();
    }

    // Functie getter pentru nr_matricol
    int getNrMatricol() {
        return nr_matricol;
    }
};

int main() {
    Student s;

    // Datele private NU pot fi accesate din instanta clasei
    // cout << s.nr_matricol;
    // error: 'nr_matricol' is a private member of 'Student'

    // Accesul la aceste date poate fi facut prin metode publice
    
    // Folosirea unui setter pentru a seta valoarea.
    s.setNrMatricol(5);

    // Folosirea unui getter pentru accesarea datelor public pentru afisare
    cout<<s.getNrMatricol();
}
```

### Friend

Folosind specificatorul **friend** putem face ca o functie externa sau o alta clasa (orice functie din interiorul ei) sa aiba acces la datele private ale unei clase.

```c++
// Definim clasa aici ca sa putem sa o referentiem in clasa Student
class Secretariat;

class Student {
    int nr_matricol;

    // Definim clasa Seceretariat ca clasa friend
    friend class Secretariat;
    
    friend int exportNrMatricol(Student &student) {
        return student.nr_matricol;
    }
};

class Secretariat {
    // Folosim clasa student
    void doSomething(const Student &student) {
        // Avem acces la date membre private
        cout << student.nr_matricol;
    }
};
```

### Supraîncărcarea operatorilor

Ne permite să definim comportamentul unui obiect in fața operatorilor.

```c++
class Student{
    int nr_matricol;
    string nume;
public:
    // Supraincarcare operatorului ca functie membra
    // Primeste ca argument o referinta ca sa previna copierea ca argument
    Student& operator=(Student &aux) {
        // previne copierea in cazul in care e acelasi obiect
        if (this == &aux) {
            return *this;
        }
        this->nr_matricol = aux.nr_matricol;
        this->nume = aux.nume;

        // Intoarce o referinta ca sa previna o copiere la asignare in caz ca dam chain assignment.
        return *this;
    }

    // Supraincarcarea operatorului ca functie non-membra folosind friend
    // Desi functia este definita in interiorul clasei, compilatorul vede specificatorul friend si stie ca defapt este o functie non membra
    friend Student& operator+(Student& student, int x) {
        Student *aux = new Student(student);
        aux -> nr_matricol += x;
        return *aux;
    }

};

//// Supraincarcarea operatorului ca functie non-membra
//Student& operator+(Student& student, int x) {
//    Student *aux = new Student(student);
//    aux->setNrMatricol(student.getNrMatricol() + x);
//    return *aux;
//}
```

Nu pot fi supraincarcati urmatorii operatori:
  * "." (accesarea unui membru, operatorul "punct")
  * "? :" (ternar / conditional operator)
  * "::" (operator de rezolutie)
  * operatorul ".*" (pointer to member)
  * sizeof
  * typeid

Operatorii urmatori pot fi supraincarcati doar ca functie membra:
  * "="
  * "( )" 
  * "[ ]" 
  * "->"


Supraincarcarea operatorilor de comparare se face printr-o functie ce returneaza o variabila de tip bool

```c++
friend bool operator>(const Student &a, const Student &b)
```

Supraincarcarea operatorilor este esentiala atunci cand vrem sa folosim diferite functii utilitare (de exemplu sort pe un std::vector)


### Variabile constante

Putem definii variabile constante folosind `const`. Acesta permite ca valoarea acelei variabile să se schimbe (primim eroare de compilare)

```c++
int main() {
    // definirea unui int const
    const int x = 10; // varbiabilele constante pot primii valoare doar la inițializare

    const int y = 21;


    const int * p_x = &x; // pointer la const int

    // valoarea pointer-ului poate fi schimbata
    p_x = &y;

    // dar valoare din pointer nu
    // (*p_x) = 10; 
    // error: read-only variable is not assignable


    const int * const cp_x = &x; // pointer constant la o variabila de tipul const int

    // valoare pointer-ului nu mai poate fi schimbata
    // cp_x = &y;
    // error: cannot assign to variable 'cp_x' with const-qualified type 'const int *const'
}
```

### Obiecte constante

Crearea unui obiect constant duce la necesitate initializării acestuia la momentul declarării.

O dată creat, datele membre ale acestuia nu mai pot fi schimbate.

Pentru a asigura asta, asupra obiectelor declarate constante pot fi apelate doar metode care declară că nu modifică obiectul

```c++
class Data {
    int x;
public:
    Data(int x) {
        this->x = x;
    }

    // modificatorul const promite că nu modifică obiectul
    int getX() const {
        return x;
    }

    // desi metoda nu modifica obiectul, nu poată fi apelată asupra obiectelor declarate const
    int get_X_non_const() {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

};

int main() {
    const Data x(5);
    x.getX();
    
//    x.get_X_non_const();
//    error: 'this' argument to member function 'get_X_non_const' has type 'const Data', but function is not marked const
}
```

### Câmpuri mutable

Câmpurile declarate `mutable` în interiorul clasei pot fi schimbate, chiar dacă sunt apelate de funcții declarate `const`

```c++
class Data {
    mutable int x;
public:
    Data(int x) {
        this->x = x;
    }

    void setX(int x) const {
        this->x = x;
    }
};

int main() {
    const Data x(5);
    x.setX(10);
}
```

## Relatii între obiecte

### Compunerea

Compunerea intre doua obiecte apare atunci cand un obiect face parte din celalalt. Disparitia obiectului "parinte" va duce la disparitia celuilalt.

```c++
class Heart {

};

class Human {
private:
    Heart heart;
public:
    Human() {
        this->heart = Heart();
    }
    Human(Heart &heart) {
        this->heart = heart;
    }
};
```

### Agregarea

Agregare apare atunci când un obiect deține un alt obiect, însă dispariția primului obiect nu implică dispariția celui de-al doilea.

```c++
class Persoana {

};

class Apartament {
private:
    vector<Persoana*> locatar;
public:
    void addPerson(Persoana *persoana) {
        locatar.push_back(persoana);
    }
    ~Apartament() {
        // Distrugerea apratamentului le permite locatarilor să se mute
        locatar.clear();
    }
};
```

## Exerciții

1. Completați codul următor astfel încât să funcționeze:

```c++

int main() {
    Carte C("Book Name", "Author Name", 2024);

    Carte D;

    std::cin >> D;

    if (C == D) {
        std::cout << "Cartile sunt la fel";
        return 1;
    }

    std::cout << D.genereazaSimilaritate();

    Carte e = C + D;

    std::cout << e;
}
```

2. Implementati clasa "ListaDublaInlantuita"

Considerați clasa 

```c++
struct Nod{ 
    int info; 
    Nod* prev, next;
}
```

Clasa ListaDublaInlantuita va suporta:

- constructor implicit
- constructor cu un nod destart
- adaugare la final
- stergere nod capat
- stergere nod inceput
- cautare dupa un int