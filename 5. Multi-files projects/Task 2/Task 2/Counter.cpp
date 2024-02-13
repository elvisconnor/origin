#include "Counter.h"
#include <iostream>

Counter::Counter(int count) {
	this->count = count;
}
Counter::Counter() {
	this->count = 1;
}
void Counter::plus() {
	count++;
}
void Counter::minus() {
	count--;
}
void Counter::show() {
	std::cout << this->count << "\n";
}