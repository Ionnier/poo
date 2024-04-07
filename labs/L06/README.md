## Laborator 6

### Type Conversion

##### Conversii implicite

E făcută de compilator 

```c++
double x = 65.684395834095348503;
cout << x << endl; // 65.6844

bool x_bool = x;
cout << x_bool << endl; // 1 (true)

char x_char = x;
cout << x_char << endl; // A (variabila ASCII)

int x_int = x;
cout << x_int << endl; // 65

float x_float = x;
cout << x_float << endl; // 65.6844
```

#### Conversii implicite pe clase

```c++
class A {};

class B {
public:
  // conversie din A (constructor):
  B (const A& x) {}
  // conversie din A (assignment)
  B& operator= (const A& x) {return *this;}
  // conversie in A (type-cast operator)
  operator A() {return A();}
};

void doSomething(const A &a) {
    
}

void doSomethingElse(const B &b) {
    
}

int main ()
{
  A a;
  // apelare constructor
  B bar(a);
  // conversie in A  (type-cast operatpr)
  doSomething(bar);
  // conversie din A (constructor)
  doSomethingElse(a);
  return 0;
}
```

#### Explicit

Pentru a prevenii exemplul precedent unde se apeleaza constructorul pentru executia unei functii

```c++
class A {};

class B {
public:
  // conversie din A (constructor):
  explicit B (const A& x) {}
};

void doSomethingElse(const B &b) {
    
}

int main ()
{
  A a;
  // explicit blocheaza apelarea constructorului deci nu poate fi apelat
  // doSomethingElse(a);
  return 0;
}
```

#### Type-Cast

Conversiile care pot cere o reînterpretare a memoriei pot avea nevoie de un cast explicit.

```c++
class A {};

class B {
public:
  // conversie din A (constructor):
  explicit B (const A& x) {}
};

void doSomethingElse(const B &b) {
    
}

int main ()
{
  A a;
  // notatie functionala
  doSomethingElse( B (a) );

  // c like  cast
  doSomethingElse( (B) a);
  return 0;
}
```

#### Static cast

Face conversii implicite, poate apela conversii explicite si poate casta prin moșteniri.

Este mult mai safe de folosit decat type-cast-ul obisnuit.

```c++
class A {};

class B {
 
};

int main ()
{
  A *a;
  A *test;
  
  B *b;
 
  // test = static_cast<A *>(b); // error: invalid 'static_cast' from type 'B*' to type 'A*'

  test = (A *) b; // compiles, but doesn't work as expected
}
```

#### Dynamic Cast

[Here](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)

#### Const Cast

Folosit pentru a modifica variabile ascunse prin pointeri declarati const

```c++
int main ()
{
  const int x = 6;
  
  int *y = const_cast<int *>(&x);
  
//   *y = 10; undefined behaviour, should be avoided
//   cout << *y; // 10
//   cout << x; // 6
  
  int x1 = 6;
  const int *y1= &x1;
  
  int *z = const_cast<int *>(y1);
  
  *z = 10;
  
  cout << *z; // 10
  cout << x1; // 10

}
```

#### Reinterpret cast

Folosit atunci cand vrem sa interpretam valoarea de la acea adresa de memorie sub un alt tip


```c++
struct A {
    char a;
    char b;
};

struct B {
    short int a;
};

int main ()
{
  A a;
  a.a = 1;
  a.b = 1;

  //   00000001 00000001
  //   B *c = (A *) (&a); // nu compileaza
  //   cout << c->a;
  //   0000000100000001


  B *b = reinterpret_cast<B*>(&a);

  cout << b->a;
  
}
```

### Smart pointers

#### Dumb smart pointers

```c++
class SmartPointer {
    int* address; // pointer
public:
    // constructor
    SmartPointer(int *p = nullptr): address(p) {}
    
    // destructor
    ~SmartPointer() { delete address; }
 
    // dereferentiere
    int& operator*() { return *address; }
};


int main() {
    int *x = new int;
    SmartPointer p(x);
    // SmartPointer y(x); // double free
    cout << *p;
}
```

### Shared pointers & weak pointers

[Via @mcmarius](https://github.com/mcmarius/poo/tree/master/tema-2#shared_ptr)


### Unique pointers
[Via @mcmarius](https://github.com/mcmarius/poo/tree/master/tema-2#unique_ptr)
