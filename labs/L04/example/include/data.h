#ifndef DATA_H
#define DATA_H
#include <ctime>
#include <iostream>

// struct/clasa mic(a), e semi-acceptabil sa fie totul in header(cel putin la proiect
struct Data{
    int zi;
    int luna;
    int an;

    Data(int zi, int luna, int an): zi(zi), luna(luna), an(an) {

    }

    friend std::ostream& operator<<(std::ostream& out, const Data &data) {
        out << data.zi << "." << data.luna << "." << data.an;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Data &data) {
        std::cout << "zi=";
        in >> data.zi;
        std::cout << "luna=";
        in >> data.luna;
        std::cout << "an=";
        in >> data.an;
        return in;
    }

    static Data now() {
        const std::time_t now = std::time(nullptr);

        const std::tm* localTime = std::localtime(&now);

        return {
            localTime->tm_mday,
            localTime->tm_mon + 1,
            localTime->tm_year + 1900
        };
    }

    int dayDifference(const Data &other) const {
        return Data::dayDifference(*this, other);
    }

    static int dayDifference(const Data &date1, const Data &data2) {
        return std::difftime(date1.toTime(), data2.toTime()) / (60 * 60 * 24);
    }


private:
    std::time_t toTime() const {
        std::tm date1 = {};
        date1.tm_year = an - 1900;
        date1.tm_mon = luna - 1;
        date1.tm_mday = zi;

        return std::mktime(&date1);
    }

};
#endif //DATA_H
