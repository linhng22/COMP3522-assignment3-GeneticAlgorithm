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
    // Loop through the cities to calculate the total distance of the tour
    for(size_t i =0; i < this->getCitiesToVisit().size() - 1; ++i){
        // Accumulate the distances between consecutive cities
        distance += getDistanceBetweenCity(this->CitiesToVisit[i], this->CitiesToVisit[i+1]);
    }
    // Set the total distance as the FitnessRating of the tour
    this->FitnessRating = distance;
}

bool operator<(const Tour &lhs, const Tour &rhs) {
    // Check id the distance from the lhs is smaller than rhs
    if(lhs.getDistanceRating() < rhs.getDistanceRating()){
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const Tour &tour) {
    for (unsigned long long i = 0; i < tour.CitiesToVisit.size(); i++) {
        if (i != tour.CitiesToVisit.size() - 1) {
            os << *tour.CitiesToVisit[i] << "->";
        } else {
            os << *tour.CitiesToVisit[i] << endl;
        }
    }
    return os;
}

bool operator==(const Tour &lhs, const Tour &rhs) {
    return lhs.FitnessRating == rhs.FitnessRating;
}

bool Tour::containsCity(const City *otherCity) const {
    // Initialize a boolean variable to store if the city is contained in the tour
    bool isContained = any_of(CitiesToVisit.begin(),
                              CitiesToVisit.end(), [&otherCity](const City *pCity) {
        // Lambda function checks if any city in the tour matches the 'otherCity'
        return *pCity == *otherCity;
    });
    // Return the result whether the 'otherCity' is contained in the tour
    return isContained;
}

void Tour::swapCity(int first, int second) {
    // Get an iterator pointing to the beginning of the list of cities
    auto it = CitiesToVisit.begin();

    // Check if the 'first' city is the last city in the tour, then set 'second' to 0
    if ((int) CitiesToVisit.size() == first + 1) {
        second = 0;
    }
    // Swap the cities at positions 'first' and 'second'
    iter_swap(it + first, it + second);
}







