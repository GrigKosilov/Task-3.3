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
	};

}

/* MADE BY GRIG_KOSILOV IN MEPHI 2019 */
