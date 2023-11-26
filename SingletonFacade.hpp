#ifndef LAB1TEMPLATE_SINGLETONFACADE_HPP
#define LAB1TEMPLATE_SINGLETONFACADE_HPP

#include <vector>
#include "City.hpp"
#include "Tour.hpp"


class SingletonFacade {
private:
    SingletonFacade()=default;
public:
    static SingletonFacade &getInstance() {
        static SingletonFacade singleton_facade;
        return singleton_facade;
    }
    SingletonFacade(const SingletonFacade &) = delete;
    SingletonFacade &operator=(const SingletonFacade &) = delete;

    ~SingletonFacade() = default;
};


#endif //LAB1TEMPLATE_SINGLETONFACADE_HPP
