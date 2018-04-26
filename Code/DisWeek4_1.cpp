#include <iostream>
#include "Integer.h"

using namespace std;

int main() {

	Integer a(2);
	Integer b(3);
	Integer c(4);
	Integer d;

	a += b;				// a is now 5
	b = c + a;			// b is now 9
	c = a - b;			// c is now -4
	d = b - c;			// d is now 13
	++b;				// b is now 10

	cout << a << endl;	// 5
	cout << b << endl;  // 10
	cout << c << endl;  // -4
	cout << d << endl; 	// 13

	return 0;
}




