#include "Population.hpp"
#include <algorithm>
#include <iomanip>
#include <random>
#include <sstream>

using namespace std;


void Population::clear_cin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

vector<Tour *> Population::createPopulation(std::vector<City *> CitiesToVisit, int PopulationSize) {
    vector<Tour *> population;
    for (int i = 0; i < PopulationSize; ++i) {
        shuffleCities(CitiesToVisit);
        population.push_back(new Tour(CitiesToVisit));
        population[i]->computeDistance();
    }
    return population;
}

string Population::createCityName(int n) {
    ostringstream ss;
    ss << "#" << setfill('0') << setw(NAME_WIDTH) << hex << n;
    return ss.str();
}

vector<City *> Population::createCities(int CitiesInTour) {
    vector<City *> CitiesToVisit;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < CitiesInTour; ++i) {
        City * city = new City(createCityName(i),generateXY(),generateXY());
        CitiesToVisit.push_back(city);
    }
    return CitiesToVisit;
}

void Population::shuffleCities(vector<City *> &cities) {
    shuffle(cities.begin(), cities.end(), mt19937(random_device()()));
}

Tour *Population::findElite(vector<Tour *> *population) {
    auto elite = min_element(population->begin(), population->end(),[](Tour *a, Tour *b) {
        return a->getDistanceRating() < b->getDistanceRating();
    });
    return *elite;
}

double Population::generateXY() {
    const double LOWER_LIMIT = 0;
    const double UPPER_LIMIT = 1000;
    double f = (double) rand() / RAND_MAX;
    return LOWER_LIMIT + f * (UPPER_LIMIT - LOWER_LIMIT);
}

void Population::selectingSets(vector<Tour *> &setA, vector<Tour *> &setB, const vector<Tour *> &original) {
    random_device rd;
    mt19937 gen(rd());
    vector<size_t> indices(original.size());
    iota(indices.begin(), indices.end(), 0);
    shuffle(indices.begin(), indices.end(), gen);

    for (size_t i = 0; i < SIZE_OF_SETS && i < original.size(); ++i) {
        ((i % 2 == 0) ? setA : setB).push_back(original[indices[i]]);
    }
}

void Population::crossParents(Tour *eliteA, Tour *eliteB, vector<Tour *> &nextGen) {
//    for (size_t i = 0; i < PopulationSize - 1; ++i) {
//        size_t index = rand() % eliteA->getSizeOfTour();
        random_device rd;
        mt19937 generator(rd()); //rd creates random seed
        uniform_int_distribution<> distribution(0, eliteA->getSizeOfTour());
        size_t index = distribution(generator); //pick a random index

        Tour *childTour = new Tour();

        //copy all cities whose indices are up to and including the random index from tourA
        for (size_t a = 0; a < index; ++a) {
            childTour->addCityToTour(eliteA->getCityInTour(a));
        }

        //copy the remaining cities from tourB that haven't been copied from tourA
        for (size_t b = 0; b < eliteB->getSizeOfTour(); ++b) {
            City *cityB = eliteB->getCityInTour(b);
            if (!childTour->containsCity(cityB)) {
                childTour->addCityToTour(cityB);
            }
        }

        //mutate the new tour
        uniform_real_distribution<> distribution1(0, 100);
        for (size_t i = 1; i < childTour->getSizeOfTour(); ++i) {
            double random = distribution1(generator);
            if (random < MUTATION_RATE) {
                childTour->swapCity(i, i + 1);
            }
        }

        childTour->computeDistance();
    nextGen.push_back(childTour);
//    }
}

vector<City *> Population::openAndReadFile() {
    vector<City *> cities;
    fstream myFile;
    string line;
    string name;
    double x;
    double y;

    myFile.open("../cities.txt", ios::in);

    if (!myFile.is_open()) {
        cerr << "Can not open file" << endl;
        exit(1);
    } else {
        while (getline(myFile, line)) {
            if (!line.empty()) {
                istringstream iss{line};
                iss >> name >> x >> y;
                City *c = new City(name, x, y);
                cities.push_back(c);
            }
        }
        myFile.close();
    }
    return cities;
}




