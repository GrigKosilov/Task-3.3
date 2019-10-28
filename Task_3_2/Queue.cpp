#include "Queue.h"
#include "GK_lib.h"
#include <iostream>
#include "string.h"

namespace Queue {
	info::info() {
		num = 0;
		str[0] = '\0';
	}
	info& info::setInfo() {
		std::cout << "Num pls ";
		num = GK::getInt();
		std::cout << "Word pls ";
		std::cin >> str;
		return *this;
	}
	inline void info::getInfo() {
		std::cout << "num:" << num << ", str: " << str << "." << std::endl;
	}

	void Queue::resizef() {
		info* old_data = data;
		try { 
			data = new info[size]; 
		}
		catch (std::bad_alloc & ba){
			std::cout << "BAD ALLOC" << ba.what() << std::endl;
			exit(0);
		}

		int old_tail = tail;
		tail = 0;

		while (head < old_tail)
			data[tail++] = old_data[head++];
		head = 0;
		//delete[] old_data;
	}
		void Queue::allocf() {
		try {
			data = new info[size];
		}
		catch (std::bad_alloc & ba) {
			std::cout << "BAD ALLOCATION!" << ba.what() << std::endl;
			exit(0);
		}
	}
	void Queue::pushf(info data0) {
		if (tail >= size) {
			size += QUOTA;
			resizef();
		}
		if (emptiness == 1)
			emptiness = 0;
		writef(tail++, data0);
		return;
	}
		void Queue::writef(int pos, info data0) {
		data[pos].num = data0.num;
		int j = 0;
		for (; data0.str[j] != '\0'; j++)
			data[pos].str[j] = data0.str[j];
		data[pos].str[j] = '\0';
	}
	info Queue::popf() {
		if (emptiness == 1)
			throw "Òàáëèöà ïóñòà";
		info data1=readf(data[head++]);
		if (head == tail) {
			emptiness = 1;
			head = 0, tail = 0;
		}
		if (head > QUOTA) {
			size -= QUOTA;
			resizef();
		}
		return data1;
	}
		info Queue::readf(info data) {
		info data1;
		data1.num = data.num;
		int j = 0;
		for (; data.str[j] != '\0'; j++)
			data1.str[j] = data.str[j];
		data1.str[j] = '\0';
		return data1;
	}

	Queue::Queue() : size(QUOTA), head(0), tail(0), emptiness(1) {
		allocf();
	}
	Queue::Queue(info data0) : size(QUOTA), head(0), tail(0), emptiness(1) {
		allocf();
		pushf(data0);
	}
	Queue::Queue(info* data0, int n) : size(QUOTA), head(0), tail(0), emptiness(1) {
		allocf();
		for (int i = 0; i < n; i++)
			pushf(data0[i]);
	}
	Queue::Queue(const Queue& queue0) : size(QUOTA), head(0), tail(0), emptiness(1) {
		allocf();
		for (int i = queue0.head; i < queue0.tail; i++)
			pushf(queue0.data[i]);
	}
	Queue::Queue(Queue&& queue0) : size(queue0.size), head(queue0.head), tail(queue0.tail), emptiness(0) {
		data = queue0.data;
		queue0.head = 0, queue0.tail = 0; queue0.emptiness = true; queue0.data = nullptr;
	}
	Queue& Queue::setIn() {
		std::cout << "Put your data, pls" << std::endl;
		info data1;
		pushf(data1.setInfo());
		return *this;
	}
	Queue& Queue::setVar(info data0) {
		pushf(data0);
		return *this;
	}
	void Queue::getAll() {
		std::cout << "This is a Queue: \n";
		int i = 0;
		while (emptiness != 1) {
			std::cout << "#" << i++ << ": ";
			popf().getInfo();
		}
		if (i == 0)
			std::cout << "Sorry, queue is empty." << std::endl;
	}
	info Queue::getVar() {
		return popf();
	}
	void Queue::check() {
		if (emptiness == 1) std::cout << "Queue is empty." << std::endl;
		else std::cout << "Queue is availible for writing." << std::endl;
	}
}

/*
×¸ òàêîå static?

Íà óðîâíå ôóíêöèè
static îçíà÷àåò, ÷òî çíà÷åíèå ïîääåðæèâàåòñÿ ìåæäó âûçîâàìè ôóíêöèé.
Ñåìàíòèêà ïåðåìåííûõ ôóíêöèè static ïîõîæà íà ãëîáàëüíûå ïåðåìåííûå,
ïîñêîëüêó îíè íàõîäÿòñÿ â ñåãìåíòå äàííûõ ïðîãðàììû (à íå ñòåê èëè êó÷à),
ñì. ýòîò âîïðîñ äëÿ áîëåå ïîäðîáíîé èíôîðìàöèè î âðåìåíè æèçíè static.
*/
