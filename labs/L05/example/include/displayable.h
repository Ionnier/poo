#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H
#include <iostream>
class Displayable {
public:
    virtual ~Displayable() = default;
    friend std::ostream& operator<<(std::ostream& out, const Displayable& displayable) {
        displayable.afisare(out);
        return out;
    }
private:
    virtual void afisare(std::ostream&) const = 0;
};
#endif //DISPLAYABLE_H
