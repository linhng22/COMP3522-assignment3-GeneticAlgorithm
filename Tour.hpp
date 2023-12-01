#ifndef LAB1TEMPLATE_TOUR_HPP
#define LAB1TEMPLATE_TOUR_HPP

#include <vector>
#include "City.hpp"
#include <iostream>
#include <cmath>

using namespace std;
class Tour {
private:

    /**
     * Vector of cities to visit
     */
    vector<City *> CitiesToVisit;

    /**
     * Fitness rating for each tour
     */
    double FitnessRating{};
public:

    /**
     * Tour default constructor
     */
    Tour()=default;

    /**
     * Tour constructor that initializes vector of cities
     * @param CityList city list
     */
    explicit Tour(const vector<City *>& CityList);

    /**
     * Function that add city into a tour.
     * @param city city pointer.
     */
    void addCityToTour(City * city);

    /**
     * Function that get city to the tour.
     * @param index position of city in the tour.
     * @return city pointer
     */
    City * getCityInTour(size_t index);

    /**
     * Function that get the list cities in a tour.
     * @return  a vector of city tour.
     */
    [[nodiscard]] const vector<City *> &getCitiesToVisit() const;

    /**
     * Function that get the tour size.
     * @return tour size
     */
    [[nodiscard]] size_t getSizeOfTour() const;

    /**
     * Function that calculator the distance between 2 cities
     * @param city1 city A
     * @param city2 city B
     * @return distance
     */
    static double getDistanceBetweenCity(City * city1, City *city2);

    /**
     * Function that get the distance between the cities as they are listed in a tour
     * @return distance
     */
    [[nodiscard]] double getDistanceRating() const;

    /**
     * Function that calculator the distance of a tour.
     */
    void computeDistance();

    /**
     * Overload insertion
     * @param os  os
     * @param tour tour
     * @return description
     */
    friend ostream &operator<<(ostream &os, const Tour &tour);

    /**
     * Overload that compare 2 tours
     * @param lhs tour 1
     * @param rhs tour 2
     * @return compare
     */
    friend bool operator<(const Tour &lhs, const Tour &rhs);

    /**
     * Overload insertion operator for Tour
     * @param lhs tour 1
     * @param rhs tour 2
     * @return true or false
     */
    friend bool operator==(const Tour &lhs, const Tour &rhs);

    /**
     * Function that check if contains a city
     * @param OtherCity other city
     * @return tru/ false
     */
    bool containsCity(const City *OtherCity) const;

    /**
     * Function that swap 2 cities
     * @param first city 1
     * @param second city 2
     */
    void swapCity(int first, int second);

    /**
     * Destructor of Tour.
     */
    virtual ~Tour() = default;
};


#endif //LAB1TEMPLATE_TOUR_HPP
