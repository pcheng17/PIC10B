#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main() {

	/** Example #1 - Iterators!
		Only use them if you need to loop through a container without 
		actually knowing where you are!
	*/
	vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// Version 1
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Version 2
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Version 3 - range-based for loop
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;

	// Version 4
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;

	// Demonstrating the need for const/const-ref correctness in range-based for loops
	for (auto& x : v) {
		++x;
	}
	for (const auto& x : v) {
		cout << x << " ";
	}
	cout << endl;
}