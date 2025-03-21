#include <iostream>
#include <string>
#include "print_arguments.h"
#include "make_random_value.h"


int main(int argc, char** argv) {
    
    // Call the function to print the arguments
    int result{0};
    result = print_arguments(argc, argv);
    if(result != 0) {
        return result;
    }

    // Game loop
    const int target_value = make_random_value();
	int current_value = 0;
	bool not_win = true;
	std::cout << "Enter your guess:" << std::endl;
	do {
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);

	return 0;
}