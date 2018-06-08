#include <iostream>
#include <fstream>
#include <set>
#include <list>

/** I do give the hint that none of the numbers that are missing are consecutive, but
	I don't actually use that hint in this code just to show you guys that it's not 
	necessary to know that.
*/

int main() {
	std::ifstream fin("numbers.txt");
	if (fin.fail()) { std::cout << "numbers.txt failed to open." << std::endl; }

	/** Inserting everything into a set so all the numbers are automatically sorted
		when traversing through the set. This way, I can easily detect when numbers
		are missing.

		You can also push_back into a vector or list, but both would be more expensive 
		because both containers would still require you to sort all of the elements
		against each other, while a set only forces only one element to sorted at once. 
		Furthermore, the push_back action of a vector is actually extremely expensive because
		every push_back requires a reallocation of memory since the vector is growing
		in size.
	*/
	int n;
	std::set<int> s;
	while (fin >> n) {
		s.insert(n);
	}

	// I'm going to save all of the missing numbers into a list just because.
	// Again, you could use a vector here, but push_back for vectors is expensive,
	// and extremely cheap for lists. 
	std::list<int> missingNumbers;

	// For each element in the set...
	for (auto it = s.begin(); it != s.end(); ++it) {
		auto next = it;					// Make a copy of the current iterator
		++next;							// Move the copy forward by 1
		int diff = *next - *it;			// Find the difference between the moved iterator and ourselves
		if (diff > 1) {					// If diff > 1, then we know exactly what numbers are missing
			for (int i = 1; i < diff; ++i) {
				missingNumbers.push_back(*it + i);		// Save all the numbers that are missing
			}
		}
	}

	// Loop through the list of missing numbers and print everything out.
	// The text file is missing all of the prime numbers!
	std::cout << "Missing numbers:\n";
	for (const auto& n : missingNumbers) {
		std::cout << n << " ";
	}
	std::cout << "\n";
	std::cout << "The text file was missing all of the prime numbers." << std::endl;

	return 0;
}