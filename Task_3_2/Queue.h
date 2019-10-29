#include <iostream>
#define STRING_SIZE 100

namespace Queue {
	struct info {
		int num;
		char str[STRING_SIZE];

		info();
		//~info() { delete[] str; }
		info& setInfo();
		inline void getInfo();

		friend std::ostream& operator << (std::ostream& out, info& data);
		friend std::istream& operator >> (std::istream& in, info& data);
	};
	class Queue {
	private:
		static const int QUOTA = 3;
		int size;
		int head = 0, tail = 0;
		bool emptiness=1;
		info* data;

		void allocf();
		void writef(int, info);
		void resizef();
		info readf(info);
	protected:
		void pushf(info);
		info popf();
	public:
		Queue();
		Queue(info);
		Queue(info*, int);
		Queue(const Queue&);
		Queue(Queue&&);
		~Queue() {  delete[] data;  }
		
		Queue& setIn();
		Queue& setVar(info);
		void getAll();
		info getVar();
		void check();
		
		friend std::ostream& operator << (std::ostream&, Queue&);//вынуть и показать все
		friend std::istream& operator >> (std::istream&, Queue&);//добавление одного из входного
		Queue& operator += (const Queue&); //Добавили в this всё из q0
		Queue& operator = (const Queue&); //Удалили this и положили в него q0
		Queue& operator = (Queue&&); //Поменяли местами this и q0
		Queue& operator () (Queue&); //Вынимаем всё из q0 и вставляем в this
		info operator -- (); //Вынуть один по правилам очереди
		info operator -- (int); //Вынуть один по правилам очереди
		Queue friend operator + (const Queue&, const Queue&); //добавить один из переменной
		Queue plusf (const Queue&, const Queue&);
		//Queue operator + (const info&); //добавить один из переменной
	};

}

/* MADE BY GRIG_KOSILOV IN MEPHI 2019 */