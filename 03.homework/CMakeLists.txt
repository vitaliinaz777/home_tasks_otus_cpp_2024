cmake_minimum_required(VERSION 3.5)

project(03.game)

add_executable( guess_the_number	 
	guess_the_number.cpp
	print_arguments.h
	print_arguments.cpp
	make_random_value.h
	make_random_value.cpp
)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)