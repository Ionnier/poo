#include <iostream>
#include <cont.h>

using namespace std;

int main() {
    Cont d("csd");
    Cont c("asd");
    c.adaugaVideoclip("bsd");
    c.aboneza(&d);
    cout << c;
    return 0;
}
