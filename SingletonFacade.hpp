#ifndef LAB1TEMPLATE_SINGLETONFACADE_HPP
#define LAB1TEMPLATE_SINGLETONFACADE_HPP

#include <vector>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"


class SingletonFacade {
private:
    // Default constructor is private to prevent external instantiation.
    SingletonFacade()=default;
public:

    // Method to retrieve the instance of SingletonFacade
    static SingletonFacade &getInstance() {
        // Static instance creation ensures only one instance is created during the program's lifetime.
        static SingletonFacade singleton_facade;
        // Returns the reference to the SingletonFacade instance.
        return singleton_facade;
    }
    // Deleted copy constructor to prevent copying of SingletonFacade instance.
    SingletonFacade(const SingletonFacade &) = delete;

    // Deleted copy assignment operator to prevent assignment of SingletonFacade instance.
    SingletonFacade &operator=(const SingletonFacade &) = delete;


    void run();


    // Default destructor.
    ~SingletonFacade() = default;
};


#endif //LAB1TEMPLATE_SINGLETONFACADE_HPP
