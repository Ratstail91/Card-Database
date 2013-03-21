#ifndef COUNTER_H_
#define COUNTER_H_

struct Counter {
	Counter() {
		calls = 0;
	}

	int operator++() {
		calls++;
		return calls;
	}

	int operator++(int) {
		int i = calls;
		calls++;
		return i;
	}

	int calls;
};

#endif
