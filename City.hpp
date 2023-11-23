#ifndef LAB1TEMPLATE_CITY_HPP
#define LAB1TEMPLATE_CITY_HPP

#include <string>

using namespace std;

class City {
private:
    string name;
    double x;
    double y;
    const double UPPER_BOUND = 0;
    const double LOWER_BOUND = 1000;
public:
    City(std::string name, double x, double y);
    [[nodiscard]] const string &getName() const;
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    friend ostream &operator<<(ostream &os, const City &city);
    friend bool operator==(const City &lhs, const City &rhs);
    virtual ~City() = default;
};


#endif //LAB1TEMPLATE_CITY_HPP
