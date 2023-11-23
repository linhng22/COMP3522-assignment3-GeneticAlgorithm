#ifndef LAB1TEMPLATE_GENETICALGORITHMS_HPP
#define LAB1TEMPLATE_GENETICALGORITHMS_HPP

#include "City.hpp"
#include <vector>
#include <random>

#define CITIES_IN_TOUR 32
#define POPULATION_SIZE 32
#define ITERATIONS 1000

class GeneticAlgorithms {
private:
    int CitiesInTour;
    int PopulationSize;
    GeneticAlgorithms() = default;
public:
    static GeneticAlgorithms &getInstance() {
        static GeneticAlgorithms instance;
        return instance;
    }
    GeneticAlgorithms(GeneticAlgorithms &instance) = delete;
    void operator=(GeneticAlgorithms &instance) = delete;

};


#endif //LAB1TEMPLATE_GENETICALGORITHMS_HPP
