#include <iostream>
#include "List.h"

void print(const List& x) {
	std::cout << "List: ";
	for (auto i : x) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main() {
	List x;
	x.push_back(1);
	x.push_back(3);
	x.push_back(5);
	x.push_back(2);
	x.push_back(4);
	print(x);
	std::cout << std::endl;
	
	auto it = x.begin();
	++it; ++it;
	x.insert(it, 10);
	print(x);
	std::cout << std::endl;

	x.reverse();
	print(x);
	std::cout << std::endl;

	List y;
	y.push_back(9);
	y.push_back(11);
	y.push_back(6);
	y.push_back(12);
	y.push_back(7);
	y.push_back(20);
	y.push_back(17);
	print(y);
	x.merge(y);
	print(x);
	std::cout << std::endl;






	return 0;
}