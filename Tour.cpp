#include "Tour.hpp"
#include <algorithm>

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
    return sqrt(pow((city2->getX() - city1->getX()), 2) + pow((city2->getY() - city1->getY()), 2));;
}

double Tour::getDistanceRating() const {
    return this->FitnessRating;
}

void Tour::computeDistance() {
    double distance = 0;
    for(size_t i =0; i < this->getCitiesToVisit().size() - 1; ++i){
        distance += getDistanceBetweenCity(this->CitiesToVisit[i], this->CitiesToVisit[i+1]);
    }
    this->FitnessRating = distance;
}

bool operator<(const Tour &lhs, const Tour &rhs) {
    if(lhs.getDistanceRating() < rhs.getDistanceRating()){
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const Tour &tour) {
    for (unsigned long long i = 0; i < tour.CitiesToVisit.size(); i++) {
        if (i != tour.CitiesToVisit.size() - 1) {
            os << tour.CitiesToVisit[i]->getName() << "->";
        } else {
            os << tour.CitiesToVisit[i]->getName() << endl;
        }
    }
    return os;
}
bool operator==(const Tour &lhs, const Tour &rhs) {
    return lhs.FitnessRating == rhs.FitnessRating;
}

bool Tour::containsCity(const City *otherCity) const {
    bool isContained = any_of(CitiesToVisit.begin(), CitiesToVisit.end(), [&otherCity](const City *pCity) {
        return *pCity == *otherCity;
    });
    return isContained;
}

void Tour::swapCity(int first, int second) {
    auto it = CitiesToVisit.begin();
    if ((int) CitiesToVisit.size() == first + 1) {
        second = 0;
    }
    iter_swap(it + first, it + second);
}







