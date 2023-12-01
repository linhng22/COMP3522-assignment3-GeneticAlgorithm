#ifndef LAB1TEMPLATE_CITY_HPP
#define LAB1TEMPLATE_CITY_HPP

#include <string>

using namespace std;

class City {
private:
    /**
     * Declare the city name
     */
    string name;

    /**
     * Declare X coordinate as double
     */
    double x;

    /**
     * Declare Y coordinate as double
     */
    double y;

    /**
     * Maximum value for x and y
     */
    const double UPPER_BOUND = 1000;

    /**
     * Minimum value for x and y
     */

    const double LOWER_BOUND = 0;
public:

    /**
     * City constructor that initializes name and coordinates
     * @param name city name
     * @param x x value
     * @param y  y value
     */
    City(std::string name, double x, double y);

    /**
     * Function that get Name of city
     * @return city Name
     */
    [[nodiscard]] const string &getName() const;

    /**
     * Function that get the  X coordinate
     * @return x value
     */
    [[nodiscard]] double getX() const;

    /**
     * Function that get Y coordinate
     * @return y value
     */
    [[nodiscard]] double getY() const;

    /**
     * Overload insertion operator for city.
     * @param os os
     * @param city city
     * @return description.
     */
    friend ostream &operator<<(ostream &os, const City &city);

    /**
     *  Overload equal operator for city
     * @param lhs city A
     * @param rhs city B
     * @return true or false
     */
    friend bool operator==(const City &lhs, const City &rhs);

    /**
     * Destructor of City.
     */
    virtual ~City() = default;
};


#endif //LAB1TEMPLATE_CITY_HPP
