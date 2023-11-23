#ifndef LAB1TEMPLATE_TOUR_HPP
#define LAB1TEMPLATE_TOUR_HPP

#include <vector>
#include "City.hpp"
#include <iostream>
#include <cmath>

using namespace std;
class Tour {
private:
    vector<City *> CitiesToVisit;
    double FitnessRating{};
public:
    Tour()=default;
    explicit Tour(const vector<City *>& CityList);
    void addCityToTour(City * city);
    City * getCityInTour(size_t index);
    [[nodiscard]] const vector<City *> &getCitiesToVisit() const;
    [[nodiscard]] size_t getSizeOfTour() const;
    static double getDistanceBetweenCity(City * city1, City *city2);
    [[nodiscard]] double getDistanceRating() const;
    void computeDistance();
    friend ostream &operator<<(ostream &os, const Tour &tour);
    friend bool operator<(const Tour &lhs, const Tour &rhs);
    friend bool operator==(const Tour &lhs, const Tour &rhs);
    bool containsCity(const City *OtherCity) const;
    void swapCity(int first, int second);
    virtual ~Tour() = default;
};


#endif //LAB1TEMPLATE_TOUR_HPP
