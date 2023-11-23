#include "Tour.hpp"

Tour::Tour(const vector<City *>& CityList) {
    this->CitiesToVisit = CityList;
}

void Tour::addCityToTour(City *city) {
    CitiesToVisit.push_back(city);
}

City *Tour::getCityInTour(size_t index) {
    return CitiesToVisit.at(index);
}

const vector<City *> &Tour::getCitiesToVisit() const {
    return CitiesToVisit;
}

size_t Tour::getSizeOfTour() const {
    return getCitiesToVisit().size();
}

double Tour::getDistanceBetweenCity(City *city1, City *city2) {
    double distance = sqrt(pow((city2->getX() - city1->getX()), 2)
                            + pow((city2->getY() - city1->getY()), 2));
    return distance;
}






