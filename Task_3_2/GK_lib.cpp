#include "GK_lib.h"
#include <iostream>

namespace GK {
	int getInt() {
		int value;
		while (true) {
			std::cin >> value;
			if (std::cin.peek() == '\n') {
				std::cin.get();
				break;
			}
			else {
				std::cout << "Retype input (value must be \
                int number)" << std::endl;
				std::cin.clear();
				while (std::cin.get() != '\n') {}
			}
		}
		return (value);
	}
	double getDouble() {
		double value;
		while (true) {
			std::cin >> value;
			if (std::cin.peek() == '\n') {
				std::cin.get();
				break;
			}
			else {
				std::cout << "Retype input (value must be \
                int number)" << std::endl;
				std::cin.clear();
				while (std::cin.get() != '\n') {}
			}
		}
		return (value);
	}
	char getChar() {
		char value;
		while (true) {
			std::cin >> value;
			if (std::cin.peek() == '\n') {
				std::cin.get();
				break;
			}
			else {
				std::cout << "Retype input (value must be \
                int number)" << std::endl;
				std::cin.clear();
				while (std::cin.get() != '\n') {}
			}
		}
		return (value);
	}
}

/* MADE BY GRIG_KOSILOV IN MEPHI 2019 */

namespace GK {
	int getInt();
	double getDouble();
	char getChar();
}

/* MADE BY GRIG_KOSILOV IN MEPHI 2019 */