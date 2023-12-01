//Student1: Linh Nguyen (StudentID: A01313185)
//Student2: Anh Nguyen (StudentID: A01282003)

#include <iostream>
#include "SingletonFacade.hpp"

int main() {
    SingletonFacade &geneticAlgorithm = SingletonFacade::getInstance();
    geneticAlgorithm.run();
    return 0;
}
