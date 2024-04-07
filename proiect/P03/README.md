## Debugger

### The old way

Considerăm următorul program:

```c++
#include <iostream>
using namespace std;

void doSomething(const int &n) {
  for (int i = 0; i < n; ++i) {
     cout << ++i; 
  }
}

int main() {
  doSomething(5);
}
```

Compilăm folosind flag-ul ce dă enable la debugger:

```bash
$ g++ -g test.cpp
```

Rulam GNU Debugger-ul pe executabilul creat

```bash
$ gdb ./my_program
```

```bash
root@e74406cd8bb8:/# gdb ./a.out    
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "aarch64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./a.out...
```

Comenzi in debugger

* run -> porneste executarea programului
* break doSomething -> setează un loc de oprire in executie la momentul executarii functiei doSomething
* del 1 -> sterge un breakpoint
* print var -> afișează valoarea variabilei var
* next -> execută următoarea linie de cod
* continue -> continuă execuția până la următorul breakpoint sau până se termină
* backtrace -> afiseaza call stack-ul
* list -> afiseaza codul sursa
* watch var -> blocheaza executia codului atunci cand variabila var se schimba
* step -> debugger-ul da skip la executia functiilor, cu step intram in interiorul lor
* finish -> termină execuția funcției curente
* exit

### IDE

[CLion](https://www.jetbrains.com/help/clion/debugging-code.html#useful-debugger-shortcuts)


## Lambda functions


### Adrese la funcții

(din C) Pasarea unor funcții ca argumente se poate face prin pointeri la funcții.


```c++
#include <iostream>
#include <vector>
using namespace std;

bool isOdd(const int &x) {
    return x % 2 != 0;
}

bool isEven(const int &x) {
    return x % 2 == 0;

}
void showBasedOn(const vector<int> &x, bool (*function)(const int&)) {
    for(auto &i: x) {
        if (function(i)) {
            cout << i << " ";
        }
    }
}

int main() {
    vector <int> s = {1, 2, 3, 4, 5};
    
    showBasedOn(s, &isOdd);
    cout << endl;
    showBasedOn(s, &isEven);
    
    return 0;
}
```

### Interfețe funcționale

Unele limbaje (ex. Java) nu permit pasarea de adrese de funcții. Soluția? Interfețe funcționale, obiecte cu singurul scop de a rula o funcție.

```c++
#include <iostream>
#include <vector>
using namespace std;

class Comparator {
public:
    virtual bool execute(const int &x) const = 0;
};

class OddComparator: public Comparator {
public:
    bool execute(const int &x) const {
        return x % 2 != 0;
    }
};

class EvenComparator: public Comparator {
public:
    bool execute(const int &x) const {
        return x % 2 == 0;
    }
};


void showBasedOn(const vector<int> &x, const Comparator &compare) {
    for(auto &i: x) {
        if (compare.execute(i)) {
            cout << i << " ";
        }
    }
}

int main() {
    vector <int> s = {1, 2, 3, 4, 5};
    
    showBasedOn(s, *(new OddComparator()));
    cout << endl;
    showBasedOn(s, *(new EvenComparator()));
    
    return 0;
}
```

### Lambda function

Structura unei funcții lambda

```c++
[](const int &x) {return x;};
```
- [] -> permite pasarea variabilelor din contextul curent 
- () -> argumentele funcției
- {} -> codul executat 

```c++
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void showBasedOn(const vector<int> &x, const function<bool(const int &)> &comparator) {
    for(auto &i: x) {
        if (comparator(i)) {
            cout << i << " ";
        }
    }
}

int main() {
    vector <int> s = {1, 2, 3, 4, 5};
    
    auto oddComparator = [](const int &x) {
        return x % 2 != 0;
    };
    
    auto evenComparator = [](const int &x) {
        return x % 2 == 0;
    };
    
    int x = 3;
    auto greaterThan = [x](const int &y) {
        return y > 3;
    };
    
    showBasedOn(s, oddComparator);
    
    cout << endl;
    
    showBasedOn(s, evenComparator);
    
    cout << endl;
    
    showBasedOn(s, greaterThan);
    
    return 0;
}

```

## Mocking

### De ce?

Testele unitare ar trebui să testeze o singură parte din funcționalitate.
În realitate, clasele pot avea dependință la alte clase.

```c++
class A {
int x;

public:
    A(const int &x): x(x) {}

    virtual int doSomething(const int &a, const int &b) const {
        return a % x + b / x;
    }
};

class B {
    A *a;
public:
    B(A &a): a(&a){}

    int doSomething(const int &x, const int &y) {
        return a->doSomething(x, y) + 5;
    }
};
```

Clasa B are nevoie de un obiect de tipul A ca sa functioneze.

În timpul scrierii testeler trebuie să ne construim obiecte A ca să testăm B.

```c++
TEST(SuiteBTests, Test) {
    A a(2);

    B b(a);

    EXPECT_EQ(9, b.doSomething(2, 2));
}

TEST(SuiteBTests, Test2) {
    A a(3);

    B b(a);

    EXPECT_EQ(11, b.doSomething(3, 3));
}
```

Usually construirea de obiecte devine repetitiva, mai ales daca am avea nevoie de anumite funcționalități

Mocking-ul ne permite să evităm să construim aceste obiecte în mod direct.

##### Setup

in CMakeLists.txt (marcat cu !!!! linia care se schimba)

```cmake
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "include/*")
file(GLOB_RECURSE TESTS RELATIVE ${CMAKE_SOURCE_DIR} "test/*") !!!!!!!!
include_directories(include)
include_directories(src)
include_directories(test)

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(USE_ASAN "Use Address Sanitizer" OFF)

....

target_link_libraries(
        test_oop
        GTest::gtest_main
        GTest::gmock_main !!!!!!!!!!!!!!!!!!!
)

include(GoogleTest)
gtest_discover_tests(test_oop)
```

### How to?

Creăm în folder-ul tests un alt folder mocks.
Derivăm clasa pe care vreăm să o mock-uim rescriind funcțiile virtuale

```c++
#include <gmock/gmock.h>
#include <ex.cpp>
#include <gtest/gtest.h>

class MockA: public A {
public:
    MockA() : A(1) {}
//    int doSomething(const int &a, const int &b) override
    MOCK_METHOD(int, doSomething, (const int &a, const int &b), (const, override));
};
```

Folosim aceasta derivată în loc de obiectul propriu zis în teste.
```c++
#include <gtest/gtest.h>
#include "mocks/mocka.h"

TEST(SuiteBTests, Test) {
    MockA a;

    EXPECT_CALL(a, doSomething(testing::_, testing::_))
            .Times(1)
            .WillRepeatedly(testing::Return(0));

    B b(a);

    EXPECT_EQ(5, b.doSomething(2, 2));
}
```
[Example here](/proiect/P03/oop-template/)
[GMock Cheat Sheet](https://google.github.io/googletest/gmock_cheat_sheet.html)
