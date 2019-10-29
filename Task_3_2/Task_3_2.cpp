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
void test_operator() {
	std::cout << "\n\nCreate and show massive size 7 of info \n";
	const int size = 7;
	Queue::info init[size];
	for (int i = 0; i < size; i++) {
		std::cin >> init[i];
	}
	for (int i = 0; i < size; i++) {
		std::cout << init[i];
	}
	/*std::cout << "\n\nCreate and show queue with massive initialization\n";
	Queue::Queue test_q(init, size);
	std::cout << test_q;

	std::cout << "\n\nAdd element from keyboard and show queue\n";
	std::cin >> test_q;
	std::cout << test_q;

	std::cout << "\n\nPls put one element to join in to queue\n";
	Queue::info test_info;
	std::cin >> test_info;
	test_q += test_info;
	std::cout << test_q << test_info;

	*/
					Queue::Queue test_q;
	std::cout << "\n\nCreate and show massive size 5 of info \n";
	const int size1 = 5;
	Queue::info init1[size1];
	for (int i = 0; i < size1; i++) {
		std::cin >> init1[i];
	}
	for (int i = 0; i < size1; i++) {
		std::cout << init1[i];
	}
	std::cout << "\n\nQ=Q1\n";
	Queue::Queue test_q1(init1, size1);
	test_q = test_q1;
	std::cout << test_q << test_q1;
	std::cout << "\n\nQ2=Q\n";
	Queue::Queue test_q2(init1, size1);
	test_q2 = test_q;
	std::cout << test_q << test_q2;
	std::cout << "\n\nQ3+=Q4\n";
	Queue::Queue test_q3(init, size);
	Queue::Queue test_q4(init1, size1);
	test_q3 += test_q4;
	std::cout << test_q3 << test_q4;
	std::cout << "\n\nBufs=Q-1\n";
	Queue::Queue test_q5(init, size);
	Queue::Queue test_q6(test_q5);
	Queue::info buf1 = --test_q5, buf2 = test_q6--;
	buf2 = test_q6--;
	std::cout << buf1 << buf2 << test_q5 << test_q6;
	std::cout << "\n\nQ5=Q6+Bufs\n";
	test_q5 = buf1 + test_q6 + buf1 + buf2;
	std::cout << test_q5 << test_q6;

	/*Queue::Queue test_q7(init, size);
	Queue::Queue test_q8(*test_q7);
	std::cout << test_q7 << test_q8;
	test_q5 = &test_q6;*/
}
int main() {
	test_operator();
	return 0;
}