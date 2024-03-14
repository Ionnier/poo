//
// Created by Dragos BAHRIM on 14.03.2024.
//

#ifndef OOP_COMENTARIU_H
#define OOP_COMENTARIU_H
#include <string>
#include <vector>
using namespace std;
class Comentariu {
    string mesaj;
    vector<Comentariu> comentarii;
public:
    Comentariu(const string&);
    friend ostream &operator<<(ostream &out, const Comentariu c);
    void adauga_comentariu(const string &mesaj);
};
#endif //OOP_COMENTARIU_H
