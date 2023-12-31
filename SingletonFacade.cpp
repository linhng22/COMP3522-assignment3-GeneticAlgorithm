#include "SingletonFacade.hpp"
#include "algorithm"


void SingletonFacade::run() {
    //Create a master list of cities, each city has a unique name and a random set of coordinates
    vector<City *> cities = Population::createCities(CITIES_IN_TOUR);

    //create a population of tours
    vector<Tour *> population = Population::createPopulation(cities, cities.size());

    // Find the shortest tour (elite)
    Tour *originalElite = Population::findElite(&population);
    cout << "Original elite: Distance: " << originalElite->getDistanceRating() << endl << *originalElite << endl;

    //Loop in algorithm
    cout << "STARTING ALGORITHM" << endl;
    double originalFitness = originalElite->getDistanceRating();
    double fitness = originalFitness;
    int iterationNum = 0;
    Tour * elite = originalElite;

    while( originalFitness/fitness < IMPROVEMENT_FACTOR && iterationNum < ITERATIONS) {
        //1. Move the elite to the front of the list
        auto eliteIterator = std::find(population.begin(), population.end(), elite);
        int eliteIndex = eliteIterator - population.begin();
        population[eliteIndex] = population[0];
        population[0] = elite;

        //2. Create a temporary list of tours (Crosses - new population)
        vector <Tour *> crosses;
        crosses.push_back(elite);

        //3. Create new tours by crossing parents, then merge new tours into the new population
        for (size_t i = 0; i < population.size() - 1; ++i){
            vector<Tour *> setA;
            vector<Tour *> setB;
            Population::selectingSets(setA, setB, population); // select 5 random tours to setA and setB

            Tour *eliteA = Population::findElite(&setA); //find elite tour in set A
            Tour *eliteB = Population::findElite(&setB); //find elite tour in set B

            //Cross 2 parents (eliteA and eliteB), merge the result into new population (Crosses)
            Population::crossParents(eliteA, eliteB, crosses);
        }

        //4. Replace tours in population with tours in crosses
        population.clear();
        population = crosses;

        //5. Mutate new merged tour in population
        for (size_t i = DEFAULT_ONE; i < population.size(); ++i) {
            Population::mutateTour(population[i]);
        }

        //6. Find the new elite in the new population
        Tour * newElite = Population::findElite(&crosses);
        cout << "Iteration: " << iterationNum << endl;
        if (newElite->getDistanceRating() < fitness) {
            fitness = newElite->getDistanceRating();
            elite = newElite;
            cout << "NEW ELITE FOUND:" << endl
            << "Distance: " << fitness << endl
            <<"Improvement over base: " << originalFitness/fitness << "\n" << endl;
        } else {
            crosses.erase(crosses.begin());
            Tour * bestNonElite = Population::findElite(&crosses);
            cout << "Elite distance:" << fitness << endl
                 << "Best non-elite distance: " << bestNonElite->getDistanceRating() << endl
                 << "Improvement over base: " << originalFitness / fitness << "\n" << endl;
        }

        iterationNum+=1;
    }

    //Print the final result
    cout << "--- FINISHED ALGORITHM ---" << endl
         << "Total iterations: " << iterationNum << endl
         << "Original elite:" << endl
         << "Distance: " << originalElite->getDistanceRating() << endl << *originalElite << endl
         << "Best elite: " << endl
         << "Distance: " << elite->getDistanceRating() << endl << *elite << endl
         << "Improvement factor reached!" << endl
         << "Improvement factor: " << originalFitness/fitness << endl;
}

