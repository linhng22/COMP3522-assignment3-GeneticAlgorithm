
#include <iomanip>
#include "RandomFunction.hpp"

RandomFunction::RandomFunction() : rd(), gen() {
}

int RandomFunction::generateInteger(int lowerLimit, int upperLimit) {
    uniform_int_distribution<> distribution(lowerLimit, upperLimit);
    return distribution(*gen);
}

double RandomFunction::generateDoubleNum(double lowerLimit, double upperLimit) {
    uniform_real_distribution<> distribution(lowerLimit, upperLimit);
    return distribution(*gen);
}

