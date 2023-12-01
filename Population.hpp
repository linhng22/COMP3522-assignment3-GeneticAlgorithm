#ifndef LAB1TEMPLATE_POPULATION_HPP
#define LAB1TEMPLATE_POPULATION_HPP

#include "City.hpp"
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include "Tour.hpp"


#define CITIES_IN_TOUR 32
#define POPULATION_SIZE 32
#define ITERATIONS 1000
#define PARENT_SIZE 5
#define NAME_WIDTH 3
#define SIZE_OF_SETS 10
#define MUTATION_RATE 15
#define IMPROVEMENT_FACTOR 2


class Population {
private:
    int CitiesInTour{};
    int PopulationSize{};
    typedef vector<Tour>::iterator tourIt;

    vector<Tour *> tours;
public:
    static void clear_cin();

    static string createCityName(int n);
    static double generateXY();
    static vector<City *> createCities(int CitiesInTour);
    static void shuffleCities(std::vector<City *> &cities);
    static vector<Tour *> createPopulation(std::vector<City *> CitiesToVisit, int PopulationSize);

    static Tour *findElite(vector<Tour *> *population);
    static void selectingSets(vector<Tour *> &setA, vector<Tour *> &setB, const vector<Tour *> &original);
    static void crossParents(Tour *eliteA, Tour *eliteB, vector<Tour *> &nextGen) ;

    static vector<City *> openAndReadFile();

};


#endif //LAB1TEMPLATE_POPULATION_HPP
