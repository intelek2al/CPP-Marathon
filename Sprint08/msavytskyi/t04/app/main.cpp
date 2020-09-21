#include "src/Serializer.h"
#include "src/SomeClass.h"
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <initializer_list>
#include <regex>

void inputParser(int argc, char *argv[], int* intVal, char* charVal, float *floatVal) {
  	std::regex rex1("([0-9]+)");
  	std::regex rex2("([^0-9])");
  	std::regex rex3("(\\d+\\.\\d+)");

    if (argc == 3 && std::strcmp(argv[1], "double") == 0) {
		if (std::regex_match(argv[2], rex3)) {
	    	*floatVal = std::stof(argv[2]);
	    } else {
	    	throw std::runtime_error("error");
	    }
    } else if (argc >= 3) {
		if (std::regex_match(argv[2], rex1)) {
	    	*intVal = std::stoi(argv[2]);
	    } else {
	    	throw std::runtime_error("error");
	    }
    }
    if (argc >= 4) {
		if (std::regex_match(argv[3], rex2)) {
			*charVal = argv[3][0];
		} else {
			throw std::runtime_error("error");
		}
    }
    if (argc == 5) {
    	if (std::regex_match(argv[4], rex3)) {
    		*floatVal = std::stof(argv[4]);
    	} else {
    		throw std::runtime_error("error");
    	}
    }
}

void worker(int argc, std::string input, int intVal, char charVal, float floatVal) {
	Serializer serial;
	if (argc == 2) {
		if (input == "int") {
			int value = serial.deserialize<int>(input);
			std::cout << "Deserialized int: " << value << std::endl;
		} else if (input == "double") {
			float value = serial.deserialize<float>(input);
			std::cout << "Deserialized float: " << value << std::endl;
		} else {
			SomeClass value = serial.deserialize<SomeClass>(input);
			std::cout << "Deserialized SomeClass: ";
			value.output();
			std::cout << std::endl;
		}
	} else if (argc == 3) {
		if (input == "int") {
			int value = intVal;
			serial.serialize(&value, input);
			std::cout << "int: " << value << " serialized" << std::endl;
		} else if (input == "double") {
			float value = floatVal;
			serial.serialize(&value, input);
			std::cout << "float: " << value << " serialized" << std::endl;
		} else {
			throw std::runtime_error("error");
		}
	} else if (argc == 5) {
		SomeClass value (intVal, charVal, floatVal);
		serial.serialize(&value, input);
		std::cout << "SomeClass: ";
		value.output();
		std::cout << " serialized" << std::endl;
	} else {
		throw std::runtime_error("error");
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 5) {
		std::cout << "./serializer [anyFileName] [intVal] [charVal] [floatVal]" << std::endl;
		exit(1);
	}
	int intVal = 0;
	char charVal = 0;
	float floatVal = 0;
	try {
		inputParser(argc, argv, &intVal, &charVal, &floatVal);
		worker(argc, argv[1], intVal, charVal, floatVal);
	} catch (std::runtime_error& re) {
		std::cerr << re.what() << std::endl;
		exit(1);
	}

    return 0;
}
