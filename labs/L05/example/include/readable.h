#ifndef READABLE_H
#define READABLE_H
#include <iostream>
class Readable {
public:
    virtual ~Readable() = default;
    friend std::istream& operator>>(std::istream& in, Readable& readable) {
        readable.citire(in);
        return in;
    }
private:
    virtual void citire(std::istream&) = 0;
};
#endif //READABLE_H
