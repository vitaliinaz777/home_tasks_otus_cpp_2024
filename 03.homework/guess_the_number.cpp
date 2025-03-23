#include <iostream>
#include <fstream>
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

    const int target_value = make_random_value();
	int current_value{};
	bool not_win = true;
	int attempts{};
	std::string name{};
	const std::string filename = "Score.txt";
	

	// Game loop
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::cin >> name;	
	std::cout << "Enter your guess:" << std::endl;
	do {
		attempts++;
		
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << " attempts: " << attempts << std::endl;
			break;
		}

	} while(true);

	// Сохраняем результат в файл
	// Открываем файл для записи и чтения
	std::fstream io_file{filename, std::ios_base::in | std::ios_base::out | std::fstream::app};
	// Записываем в конец файла
	io_file << name << " " << attempts << std::endl;
	io_file.flush();
	// Перемещаем каретку в начало файла
	io_file.seekg(0);
	
	std::cout << "High scores table: " << std::endl;
	// Читаем файл построчно
	while(io_file >> name >> attempts) {
		std::cout << name << " " << attempts << std::endl;
	}

	// Закрываем файл
	io_file.close();
}