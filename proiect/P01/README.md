### Namespaces

```c++
// Pentru a evita conflicte ce pot apărea din cauza existenței a două funcții cu același nume și argumente
// Le putem declara în interiorul unui namespace

// Declaram primul namespace
namespace namespace_name {
    // Declaram o functie in interiorul namespace-ului
    void doSomething() {

    }
}

// Declaram al doilea namespace
namespace namespace_second {
    // Declaram o functie in interiorul namespace-ului
    void doSomething() {

    }
}

// Pentru a utiliza functiile din interiorul unui namespace

// Fie spunem ca folosim toate functiile din acel namespace

using namespace namespace_name;
int main() {
    // se apeleaza funcția din interiorul primului namespace întrucât asta am declarat
    doSomething();

    // Fie folosim operatorul de rezoluție pentru a accesa definițiile din interiorul namespace-ului
    namespace_second::doSomething();
}
```

## Declararea unei funcții (preluat din C)

```c++
// Ca să apelăm o funcție, trebuie ca această să fie declarată.

// Putem să separăm declararea de implementare

// Declaram functia
// Necesita tipul de return, numele si tipul argumentelor
int doSomethingElse(int);

// Declararea altei functii
void doSomething() {
    // Functia poate fi apelata pentru ca este definita in acest context
    doSomethingElse(5)
}

// Implementarea efectiva a functiei
int doSomethingElse(int x) {
    return x;
}

```



## Separarea implementării metodelor din clase

```c++
class Product {
private:
    int value;
    int weight;
public:
    Product(const int &value, const int &weight) {
        this->value = value;
        this->weight = weight;
    }
}

// Atunci când avem multe clase, cu multe metode, aceasta poate devenii destul de mare
// Deci devine greu de navigat
// Putem separa implementarea de definire
// Pastrand in clasa doar declararile
```

```c++
// Definitia clasei
class Product {
private:
    int value;
    int weight;
public:
    Product(const int &, const int &);
};

// Implementarea efectiva
Product::Product(const int &value, const int &weight) {
    this->value = value;
    this->weight = weight;
}
```

Mai mult decat atat, putem separa si fisierele celor doua.

Fisirele C++ care conțin doar definiții se numesc "headere" și au extensiile **.h**.

Fișierele care conțin implementare pot să rămână cu **.cpp**

Fișierul **product.h** va cuprinde:

```c++
class Product {
private:
    int value;
    int weight;
public:
    Product(const int &, const int &);
};
```

Fișierul **product.cpp** va cuprinde:

```c++
#include "product.h" // includere relativa, trebuie sa fie in acelasi folder

Product::Product(const int &value, const int &weight) {
    this->value = value;
    this->weight = weight;
}
```

## Makefiles

```makefile
build:
	clang++ ./main.cpp

run:
	./a.out

full: build run
``` 
(identarea se face cu tab)

Acompaniază codul nostru și reprezintă instrucțiunile care trebuie rulate ca să compilăm programul.

Când folosim CLion acesta va folosi CMake ([exemplu](../../labs/L02/example/CMakeLists.txt))

Avantajele folosirii unui Makefile e faptul că nu o să compileze toate fișierele ci doar cele care se schimbă (în funcție de cum e făcut).

În acest scop, într-un fișier Makefile o să specificăm ce fișiere vrem să compilăm ca să creăm executabilul.

### Git

[Configurare și utilizare făcută de @mcmarius](https://github.com/mcmarius/poo/tree/master/env#configurarea-%C8%99i-utilizarea-programului-git) (puteți citii toată pagina dacă sunteți interesați!)

[Short YouTube Video](https://www.youtube.com/watch?v=HkdAHXoRtos)

### Jump Start Project

1. Instalați CLion & Git
2. Creearea unui cont pe GitHub
3. Accesează [template-ul](https://github.com/Ionnier/oop-template)
4. Folosiți butonul "Use this template" pentru a vă crea un repository bazându-vă pe template-ul proiectului.
5. Accesați tab-ul de GitHub Actions pentru a activa Workflow-urile
6. Reveniți pe pagina cu proiectul
7. Apăsați pe butonul clone.
8. Selectați HTTPS (sau SSH dacă ați setat o cheie SSH)
9. Folosiți `git clone LINK_CLONE_PRELUAT_LA_PASUL_ANTERIOR` sau deschideti CLion fara sa aveti un proiect deschis si apasati pe "Clone from VCS"
10. Creati un branch nou folosind comanda `git branch etapa-1`
11. Intrati pe branch-ul respectiv folosind `git checkout etapa-1`
12. Faceti orice modificare pentru tema
13. Adăugati toate fisierele modificate în staging area folosind "git add ."
14. Realizați un commit folosind `git commit` (o să fiți întrebați să lăsați un mesaj, puteți folosi opțiunea -m pentru a furniza un mesaj direct când apelați comanda)
15. `git push` pentru a urca modificările în GitHub
16. O să vă apară pe repository un mesaj mic "You recently pushed to x, do you want to make a Pull Request?"
17. Dacă nu apare, mergeți pe tab-ul de Pull Request din Repository și apăsați pe "New Pull Request"
18. Selectați branch-urile `main <- tema-1`
19. Creați Pull Request-ul
20. Căutați câmpul de require approval from și introduceți: @Ionnier ca să vă pot da feedback pe modificări.

[Video al pașilor](https://unibucro0-my.sharepoint.com/:v:/g/personal/dragos_bahrim_s_unibuc_ro/EYCgC6ZD2ZhMiHXRGK8BbKcBP0cfHUwCiuBoSQ29wmVWyg?e=6gxeeF)

Note:

* ca să pot să apar la Review, trebuie să mă adăugați ca și colaborator pe repository-ul de GitHub. De pe pagina repository-ului, selectați tab-ul "Settings" -> "Collaborators" -> "Add people" -> search for @Ionnier [image](https://unibucro0-my.sharepoint.com/:i:/g/personal/dragos_bahrim_s_unibuc_ro/EX4VVllO0sVGufWCFlFl6gwBHAC_HvwP5BGwbhpgv560fQ?e=Nsfrpm)

* am folosit metoda de clonare prin SSH nu prin HTTPS pentru ca o aveam deja configurată, când o să folosiți HTTPS o să vi se deschidă un browser în care să vă autentificați (e posibil să își facă auto login)
* am folosit IDE-ul pentru pașii de creat branch, commit & push, dar comenzile sunt fix cele de mai sus 