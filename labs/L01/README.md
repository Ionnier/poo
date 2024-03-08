# Introducere laborator & recapitulare C/C++

- [Introducere laborator \& recapitulare C/C++](#introducere-laborator--recapitulare-cc)
  - [Requirements:](#requirements)
  - [Ce este C++?](#ce-este-c)
  - [Cum scriem C++?](#cum-scriem-c)
  - [First step in C++](#first-step-in-c)
  - [Declararea variabilelor](#declararea-variabilelor)
  - [Tipuri de date complexe](#tipuri-de-date-complexe)
  - [Scrierea funcțiilor](#scrierea-funcțiilor)
  - [Input \& Output](#input--output)
  - [Decision Control](#decision-control)
  - [Variable life cycle](#variable-life-cycle)
  - [Pointeri \& Adrese de memorie](#pointeri--adrese-de-memorie)
  - [Lucrul cu adrese de memorie](#lucrul-cu-adrese-de-memorie)
  - [Alocarea memoriei](#alocarea-memoriei)
  - [Aritmetica pointerilor](#aritmetica-pointerilor)
  - [Tipuri de date complexe](#tipuri-de-date-complexe-1)
  - [Exemple](#exemple)
    - [Citirea si afișarea unui număr de la tastatură](#citirea-si-afișarea-unui-număr-de-la-tastatură)
    - [Citirea și afișarea unui șir de numere de la tastatură (cu alocare dinamică)](#citirea-și-afișarea-unui-șir-de-numere-de-la-tastatură-cu-alocare-dinamică)
    - [Citirea unui struct printr-o funcție](#citirea-unui-struct-printr-o-funcție)
  - [Exerciții](#exerciții)
    - [See also](#see-also)


## Requirements:

 * Instalare [CLion]()
    * o să aveti nevoie de [licență educațională]()
    * CLion este un Integrated Development Environment (IDE), din acest motiv el vine "echipat" cu tot ce aveți nevoie ca să rulați tot ce o să se facă la curs
    * e facut de JetBrains deci o să fie extrem de familiar cu alte IDE-uri pe care le veți folosii în viitor (PyCharm, InteliJ)
 * Alternative (nerecomandat):
     * CodeBlocks
     * VS Code + un compilator
     * Microsoft Visual Studio
* Configurare [CLion + Git tutorial](https://github.com/mcmarius/poo/tree/master/env) @mcmarius
* Puteti folosii [Sourcetree](https://www.sourcetreeapp.com/) pentru a abstractiza rularea constantă a comenzilor (doar dupa ce va familiarizati cu ele)
  * îl recomand mai mult decât cel din IDE pentru că tinde să fie destul de încet
  * sunt cazuri și cazuri când le folosesc pe toate, gasițivă preferința 😁

## Ce este C++?

Este o extensie pentru C ca să suporte programare orientată obiect.

Pentru a rula un program scris în C++ acesta trebuie să fie compilat. Acesta va compila într-un executabil specific sistemului pe care rulează.

Sistemele UNIX-based, în funcție de distribuție vin cu compilatorul g++ deja instalat.

Pe Windows, putem să instalăm manual un compilator (de ex. prin MinGW).

## Cum scriem C++?

Codul scris în C++ va fi scris în fișiere care se termină cu extensia `.cpp` sau `.h` (pentru headere). Pot exista mai multe extensii, dar acestea sunt cele de bază. (extensia e irelevantă oricum).

## First step in C++

```c++
// directivă de preprocesare
#include <iostream>
// are scopul de a include definițiile ce sunt scrise în biblioteca iostream

// pentru a prevenii conflictul de nume
using namespace std;
// funcțiile sunt scrise în namespaces mai ales cele care ne așteptăm să fie apelate de alte persoane


// funcția main este cea care este executată la pornirea programului
int main() {
    cout << "Hello world!";
    return 0;
}
// în general returnează un int
// in UNIX -> 0  - sucess
//         -> 1+ - error
```

## Declararea variabilelor


```c++
// variabilele pot fi declarate global atunci când nu sunt declarate în interiorul unei funcții

int global_x;

// de evitat


int main() {
    // Tipuri de date standard:


    // bool = true / false (reprezentat pe 1 bit) (deci doar 0 / 1)
    bool x = true;

    // O dată ce o valoare este definită, ea poate fi reasignată
    x = false;

    // char = character ASCII (reprezentat pe 8 biți / 1 Byte) (deci doar numere -255 -> 255 care sunt interpretate ca caractere conform tabela ASCII )

    char y = 'a';

    // int = numere întregi (reprezentat pe 4 Bytes)
    // deci  doar numere între 2^-16 - 2^16

    int z = 10;

    // float = numere reprezentate în virgulă mobilă (8 Bytes)
    // double = numere reprezentate în virgulă mobilă cu dublă precizie (16 Bytes)

    // e mai complicat modul cum funcționează interpretarea biților pentru float / double și nu merită

    // include existența unui bit de semn urmat de niște biți pentru exponent și o mantisă

    // Module de interpretare a biților este diferit pentru numerele în virgulă mobilă vs cele fără

    // Pentru a trece peste diferite limitări de valori putem folosii unsinged

    unsigned int p = 10;

    // acum putem memora valori doar 0 - (2 ^ 32 - 1) întrucat avem un bit în plus

    // ^ - reprezentarea numerelor în format binar
}
```

## Tipuri de date complexe 

```c++
// Folosim Standard Template Library pentru a importa biblioteci cu roluri ajutătoare

// Minimul cunoscut până acum sunt 

#include <vector>
// ^ pentru șiruri de numere

#include <string>
// ^ pentru șiruri de caractere (cuvinte)

using namespace std;

int main() {
    // declararea unui sir de caractere (string)
    string example = "Hello World";

    // declararea unui vector de int si initializarea acestuia cu 5 elemente
    vector<int> sir = {
        1, 2, 3, 4, 5
    };

}

```


## Scrierea funcțiilor

```c++
// funcțiie în C++
// au formatul 
// nume_functie(argumente) urmat de acolade pentru scrierea funcției
// parametru_de_iesire 

// cand o funcție nu returnează nimic
// se foloseste void
void doSomething() {
    return; // nu returnează nimic
}

int adunare (int x, int y) {
    // keyword-ul return este folosit pentru a opri execuția funcției și a ieși din ea
    return x + y;
}

int main() {
    int x = 2;
    int y = 3;

    // cand apelam o funcție
    // se oprește execuția codului din care este apelată
    // parametrii trimiși ca input vor fi copiați (deci nu pot fi modificați în interiorul funcției)
    int z = adunare(x, y);

    // z == 5
}
```

## Input & Output

```c++
// includem biblioteca care conține funcțiile de citire și afișare
#include <iostream>

using namespace std;

int main() {
    // pentru afișare la consolă se folosește cout

    // console - output (cout)
    cout << "n= ";

    int n;

    // pentru citirea de la tastatura (pana la enter)
    // se folosete cin (console - input)
    cin >> n;

    cout << n;

}
```

## Decision Control

```c++
int main() {
    // avem if pentru conditionale
    bool x = true;

    if (x == true) {
        // do something if x is true
    } else {
        // do something if x isn't true
        // can be ommited
    }

    // condiții repetitive
    while (x == true) {
        // se execută cât timp x va fi true
        // se ieși din while oricând folosind
        break;
    }

    for (int i = 0; i < 10; i++) {
        // îl inițializează pe i cu 0, rulează cât timp i este mai mic ca 10, si la fiecare loop îl iterează cu 1
    }
    int i = 0;
    // Următoarele instrucțiuni sunt echivalente

    i++ // adaugă la i 1 
    i += 1 // adaugă la i 1
    i = i + 1 // face adunarea i + 1 si i-o atribuie lui i;
    ++i // adaugă la i 1, dar în altă ordine, mai întâi se execută linia cu valoarea curentă a lui i, și după îl încrementează

    do {
        // execute some code
        break;
    } while(true) // echivalent cu while, însă se execută porțiunea de cod din do, și abia după se verifică condiția din while
    
    // da match la element-ul i față de niște cazuri prestabilite
    switch(i) {
        case 1: {
            // do something when i is 1
            break // mandatory, otherwise the next case will be executed 
        }
        case 2: {
            // do something when i is 2
        }
        case 3: {
            // do something when i is 3
            // because 2 does not have break
            // this also executes when i is 2
        }
        default: {
            // when i does not match any case
            // execute the default block
            // break is optional because this is the last block
        }
    }
}
```

## Variable life cycle

```c++
// Variabilele rămân în viață doar până la finalul execuției funcției în care sunt declarate
// Variabilele declarate global rămân inițializate pe toată perioada execuției programului (de asta sunt de evitat)
void doSomething(int x) {
    // x-ul va fi o copie
    return;
}

int main() {
    // x-ul este inițializat
    int x = 5;
    
    doSomething(x);

    // la finalul funcției x-ul va dispărea
}
```

## Pointeri & Adrese de memorie

```c++
#include <iostream>
using namespace std;

int main() {
    // Undeva pentru x se aloca memorie (4 Bytes), iar memoria de la locul acela va reprezenta în biți numărul 5.
    int x = 5;

    // C-ul ne permite să memorăm aceasta adresă prin pointeri
    int *x p; // pointer la int, dat de prezenta *
    // Pointer = o variabila ce memoreaza adrese
    // Ce este la memoria aia este data de tipul pointerului
    // in cazul nostru va fi un pointer de int
    // deci la adresa memorata va fi un int

    // pentru a face rost de adresa unei variabile folosim &
    p = &x;
    // Acum p va avea adresa lui x;

    // În momentul de față putem să accesăm variabila x în alt stil.
    // Pointer-ul p știe adresa lui x, deci dacă citim ce avem la adresa aia, vom obține valoarea lui x;


    // pentru a face rost de valoarea ce se afla la un pointer
    // folosim operatorul de deferentiere
    // adica *

    int x_copy = *p;
    
    // cand scriem *p e ca si cum am folosii variabila x direct, sau mai bine spus memoria interpretata de la adresa lui x

    cout << x << endl; // endl = print '\n' in console, adica new line

    // va afisa 5

    cout << x_copy << endl; // va afisa 5


    // daca modificam valoarea lui x
    x = 6;

    cout << x << endl; // va afisa 6
    cout << x_copy << endl; // va afisa 5, x_copy are adresa propri care nu a fost modificata
    cout << *p << endl; // va afisa 6, pointer-ul mereu va da valoarea reala de la acea adresa
}
```

## Lucrul cu adrese de memorie

```c++
#include <iostream>
using namespace std;

void doSomething(int x) {
    // se va modifica copia locala a lui x
    x++;
    // deci modificarile nu vor fi simtite de variabila reala
}

void doSomethingElse(int *x) {
    // x-ul este deferențiat, deci accesăm memoria efectivă a valorii pasate
    (*x)++;
    // x-ul va fi modificat
}

int main() {
    int x = 5;

    cout << x << endl; // va afisa 5

    // doSomething va primii o copie a lui x
    doSomething(x);
    // nu o poate modifica

    cout << x << endl; // va afisa 5

    doSomethingElse(&x) // trimitem adresa lui x
    cout << x; // va afisa 6
    
}
```

## Alocarea memoriei

```c++
int main() {
    // Alocarea statica a memoriei
    // Alocarea statica se face in stack (deci e limitat)
    // Dar e mult mai rapida -> se face la compilare

    // Se declara un sir de int-uri de 100 de elemente
    int p[100];

    // ce este p?
    // p este un pointer catre o adresa de memorie
    // deci la locul de memorie unde p pointeaza
    // suficient de multă memorie pentru 100 de int-uri

    // cum accesam numerele din acel sir
    p[0] // -> luam primul element


    // Alocarea dinamica -> se face în heap 
    // Se face la runtime
    // Folosim keyword-ul new
    
    int *p_dynamic = new int[100];


    // ce este p_dynamic?
    // este un pointer
    // la adresa unde el pointeaza se aloca suficient de multa memorie astfel încât să fie 100 de elemente
    // deci sunt alocate 4 * 100 Bytes

    // Cum accesam elementele?

    p_dynamic[0] // accesam primul element

    // !!ATENTIE!!

    // cand alocam static
    // compilatorul stie singur ca trebuie sa dezaloce memorie
    // cand alocam dinamic, reprezinta responsabilitatea noastra sa facem asta
    // facem asta folosind operatorul delete

    delete [] p_dynamic;
    // dezalocam memoria alocata dinamic care era la p_dynamic
    // find un vector, folosim []
}
```

## Aritmetica pointerilor

```c++
int main() {
    int p[100];

    // p reprezintă o adresă de memorie, este un pointer

    // el o sa pointeze la primul element

    // cum il obtinem pe urmatorul?

    // in mod clasic
    // daca p pointeaza la o adresa
    // stim ca avem int-uri, deci trebuie sa sarim peste 4 Bytes

    // p
    // | - - - - | - - - - |
    //  mem_aloc   mem_aloc
    //     pt         pt
    //   primul el   al 2-lea
    //  int = 4 Bytes

    // Ca sa facem rost de al doilea element, sarim peste cei 4 biti.

    // C-ul stie sa faca asta singur

    int *adresa_al_doilea_element = V + 1 // sarim un bloc de memorie

    int al_doilea_elem = *(V+1) // dereferentiem ce e la adresa V+1

    // *(V+1) este echivalent cu

    int al_doilea_elem = V[1];
    
}
```

## Tipuri de date complexe

```c++
// putem definii alte tipuri de variabile
struct Punct{
    int x;
    int y;
};

int main() {
    Punct punct;
    // Putem accesa x si y folosind "."
    int xx = punct.x;
    int yy = punct.y;
    // Ele se comporta ca variabile normale

    // Memoria ocupata de un struct e egala cu suma componentelor
    sizeOf(Punct) == sizeOf(int) + sizeOf(int)

    // Cand avem adrese de struct-uri
    Punct *p = &punct;

    // Ca sa accesam variabilele, avem nevoie sa dereferentiem variabila si pot fi apelate direct

    (*p).x;

    // Exista un shorthand expression pentru asta
    
    p->x;
    
    // este echivalent cu cea de mai sus
}
```

## Exemple

### Citirea si afișarea unui număr de la tastatură
```c++
#include <iostream>
using namespace std;

int main() {
    // declaram variabila
    int x;

    // afisam un mesaj la consola ce indica ca citim variabila
    cout << "x=";
    
    // citim de la tastatura pe x
    cin >> x;

    cout << "x=" << x;
    // cout-ul poate fi înlănțuit
    // La fel și cin-ul

    return 0; // opțional return în C++
}
```

### Citirea și afișarea unui șir de numere de la tastatură (cu alocare dinamică)

```c++
#include <iostream>
using namespace std;

int main() {
    // un șir de numere 
    // un șir de numere este un șir de memorie dedicată int-urilor


    // declaram variabila
    int n;

    // afisam un mesaj la consola ce indica ca citim variabila
    cout << "nr_elemente=";
    
    // citim de la tastatura pe x
    cin >> n;

    // alocăm memorie pentru aceste int-uri
    int *V = new int[n]; 
    // int V[n] // o să observați că nu funcționează, alocarea statică necesită să cunoască numărul de elemente la compile time

    for (int i = 0; i < n; i++) {
        // pentru fiecare element care vrem să îl citim rulăm o citire la adresa lui de memorie
        cout << "V[" << i << "]=";

        // citirea efectivă a elementului
        cin >> V[i];
    }

    // afisarea
    for (int i = 0; i < n; i++) {
        cout << V[i];
    }   

    // Lipseste ceva? Atentie.
}
```

### Citirea unui struct printr-o funcție 

```c++
#include <iostream>
using namespace std;

struct Punct {
    int x;
    int y;
};

// primeste adresa ca sa poată fi modificat
void citire_punct(Punct *punct) {
   cout << "x= ";
   cin >> punct->x;
   cout << "y= ";
   cin >> punct->y;
}

void afisare_punct(Punct punct){
    // in modul cum apelam functia asta, mereu va fi copiat punctul din nou
    // la afisare nu ne intereseaza
    // (momentan)
    cout << "Punct(" << punct.x << "," << punct.y << ")\n";
}

int main() {
    Punct p;
    citire_punct(&p);
    afisare_punct(p);
}
```


## Exerciții

1. Citește două numere de la tastatură. Afișează maximul dintre ele.
2. Citește un număr variabil de numere de la tastatură. Afișează minimul dintre ele.
3. Citește de la tastatură un număr variabil de Puncte(vezi struct-ul Punct)
     * dacă se citește 1 punct, afișează-l
     * dacă se citesc 2 puncte, afișează 'Linie'
     * daca se citesc 3 puncte, afișează dacă cele 3 sunt coliniare
     * dacă se citesc 4 puncte, afișează dacă pot forma un pătrat
     * dacă se citesc mai multe, afișează "Nedeterminat"

Recomandare:

* folositi memorie alocata dinamic
* modularizați programele ca să vă obișnuiți cu locul unde să folosiți pointer și unde nu
* citiți parțial referințele



### See also
[Small Recap C](https://learnxinyminutes.com/docs/c/)

[Google C++ Styling Guide](https://google.github.io/styleguide/cppguide.html)