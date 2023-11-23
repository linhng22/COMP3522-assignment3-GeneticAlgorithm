#include "City.hpp"

#include <utility>
#include <iostream>

City::City(string name, double x, double y) : name(std::move(name)){
    try {
        if(x >= LOWER_BOUND && x <= UPPER_BOUND && y>= LOWER_BOUND && y <= UPPER_BOUND){
            this->x = x;
            this->y = y;
        } else {
            throw(invalid_argument("x and y are out of bound. Make sure x and y are between range 0 and 1000"));
        }
    } catch(invalid_argument &e){
        cerr << "Exception: " << e.what() << endl;
    }
}

const string &City::getName() const {
    return name;
}

double City::getX() const {
    return x;
}

double City::getY() const {
    return y;
}

ostream &operator<<(ostream &os, const City &city) {
    os << "City Name:" << city.name << " \n City Coordinates: (x, y) = (" << city.x << ", " << city.y << ")" << endl;
    return os;
}

bool operator==(const City &lhs, const City &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

