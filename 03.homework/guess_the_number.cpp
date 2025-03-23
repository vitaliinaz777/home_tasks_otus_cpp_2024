#include <iostream>
#include <fstream>
#include <string>
#include "print_arguments.h"
#include "make_random_value.h"


int main(int argc, char** argv) {
	int current_value{};
	bool not_win = true;
	int attempts{};
	std::string name{};
	const std::string filename = "Score.txt";
	int max_value{100};

	// Парсим аргументы
	if (argc >= 2) {
		std::string arg1_value{ argv[1] };

		// -max
		if (arg1_value == "-max") {
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-parameter' requires some value!" << std::endl;
				return -1;
			}
			max_value = std::stoi(argv[2]);
		} else if(arg1_value == "-table") {
				std::fstream io_file{filename, std::ios_base::in};
				if (!io_file.is_open()) {
					std::cout << "File not found!" << std::endl;
					return -1;
				}
				std::cout << "High scores table: " << std::endl;
				while(io_file >> name >> attempts) {
					std::cout << name << " " << attempts << std::endl;
				}
				io_file.close();
				return 0;
			}
		else {
			std::cout << "Unknown argument!" << std::endl;
			return -1;
		}
	}
	
	
	
	const int target_value = make_random_value(max_value);

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