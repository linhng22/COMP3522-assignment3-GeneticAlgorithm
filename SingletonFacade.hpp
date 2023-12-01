#ifndef LAB1TEMPLATE_SINGLETONFACADE_HPP
#define LAB1TEMPLATE_SINGLETONFACADE_HPP

#include <vector>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"


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

    void run();

    ~SingletonFacade() = default;
};


#endif //LAB1TEMPLATE_SINGLETONFACADE_HPP
