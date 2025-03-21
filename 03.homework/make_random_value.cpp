#include "make_random_value.h"

int make_random_value() {
    const int max_value = 100;

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    const int random_value = std::rand() % max_value;

    std::cout << "Random value: "<< random_value << std::endl;

    return random_value;
}