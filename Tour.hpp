#ifndef LAB1TEMPLATE_TOUR_HPP
#define LAB1TEMPLATE_TOUR_HPP

#include <vector>
#include "City.hpp"

using namespace std;
class Tour {
private:
    vector<City *> cities_to_visit;
    double FitnessRating{};
public:
    Tour()=default;
    explicit Tour(const vector<City *>& CityList);
};

#endif //LAB1TEMPLATE_TOUR_HPP
