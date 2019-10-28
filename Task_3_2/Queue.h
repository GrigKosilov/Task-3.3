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
		
		friend std::ostream& operator << (std::ostream&, Queue&);//
		friend std::istream& operator >> (std::istream&, Queue&);//
		Queue& operator += (const Queue&); //Добавили в this всё из q0//
		Queue& operator = (const Queue&); //Удалили this и положили в него q0//
		Queue& operator = (Queue&&); //Поменяли местами this и q0
		Queue& operator () (Queue&); //Вынимаем всё из q0 и вставляем в this

		// Queue& operator + (const Queue&);
		// info& operator -- ();
		// const info& operator -- (int);
	};

}

/* MADE BY GRIG_KOSILOV IN MEPHI 2019 */