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
#define DEFAULT_ONE 1
#define DEFAULT_ZERO 0
#define DEFAULT_HUNDRED 100


class Population {
public:
    /**
     * Create the name of the city
     * @param n a unique number of the city
     * @return a string for the name
     */
    static string createCityName(int n);

    /**
     * Create a random coordinate of the city
     * @return a double for x-coordinate or y-coordinate
     */
    static double generateXY();

    /**
     * Create the master list of all cities
     * @param CitiesInTour the number of cities in a tour
     * @return a vector of pointers to cities
     */
    static vector<City *> createCities(int CitiesInTour);

    /**
     * Shuffle all cities
     * @param cities a reference of group of cities
     */
    static void shuffleCities(std::vector<City *> &cities);

    /**
     * Create a population of tours
     * @param CitiesToVisit a list of cities to visit
     * @param PopulationSize the size of the population
     * @return a vector of pointers to tours
     */
    static vector<Tour *> createPopulation(std::vector<City *> CitiesToVisit, int PopulationSize);

    /**
     * Find the elite tour that has the shortest travelling distance
     * @param population the population of tours
     * @return pointer to the shortest tour
     */
    static Tour *findElite(vector<Tour *> *population);

    /**
     * Select random tours from the original population into 2 parent sets. Each set contains 5 tours.
     * @param setA the first parent set
     * @param setB the second parent set
     * @param original the original population
     */
    static void selectingSets(vector<Tour *> &setA, vector<Tour *> &setB, const vector<Tour *> &original);

    /**
     * Create a new tour by crossing two elite tours from 2 parent sets, then merge it into the new population
     * @param eliteA the shortest tour in parent set A
     * @param eliteB the shortest tour in parent set B
     * @param nextGen the new population
     */
    static void crossParents(Tour *eliteA, Tour *eliteB, vector<Tour *> &nextGen);

    /**
     * Mutate a tour: for every city in a new merged tour, roll a dice.
     *      If the dice result is < 15%, swap the city with the one next to it.
     *      If it's the last city, swap it with the tour at the front.
     * @param tour the tour being mutated
     */
    static void mutateTour(Tour *tour);

};


#endif //LAB1TEMPLATE_POPULATION_HPP
