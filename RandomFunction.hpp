//
// Created by Anh Nguyen on 2023-11-23.
//

#ifndef LAB1TEMPLATE_RANDOMFUNCTION_HPP
#define LAB1TEMPLATE_RANDOMFUNCTION_HPP

#include <random>
using namespace std;

class RandomFunction {
private:
    random_device * rd;
    mt19937 * gen;
public:
    RandomFunction();
    double generateDoubleNum(double lowerLimit, double upperLimit);
    int generateInteger(int lowerLimit, int upperLimit);
};


#endif //LAB1TEMPLATE_RANDOMFUNCTION_HPP
