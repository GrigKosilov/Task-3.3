#include "Queue.h"
#include <iostream>
#include "GK_lib.h"

void test_queue() {
	std::cout << "\n\nCreate and show massive size 7 of info \n";
	const int size = 7;
	Queue::info init[size];
	for (int i = 0; i < size; i++) {
		init[i].setInfo();
	}
	for (int i = 0; i < size; i++) {
		init[i].getInfo();
	}
	std::cout << "\n\nCreate and show queue with massive initialization\n";
	Queue::Queue test_q(init, size);
	test_q.getAll();

	std::cout << "\n\nAdd element from keyboard, get element from queue to varible and show it\n";
	test_q.setIn();
	Queue::info test_info = test_q.getVar();
	test_info.getInfo();

	std::cout << "\n\nShow queue and its status\n";
	test_q.getAll();
	test_q.check();

	std::cout << "\n\nGet info from keyboard, add element from varible, check status  and show queue\n";
	test_info.setInfo();
	test_q.setVar(test_info);
	test_q.check();
	test_q.getAll();

	std::cout << "\n\nThats all\n";
}
int main() {
	test_operator();
	return 0;
}
