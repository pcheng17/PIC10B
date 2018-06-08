#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

/** I think most people will come up with one of the following two versions.
	The fast version relies on knowing the range of numbers that show
	up in the vector, which I've provided to you in the problem statement.
*/ 
int find_unique_slow(const std::vector<int>& v);
int find_unique_medium(std::vector<int> v);
int find_unique_fast(const std::vector<int>& v);

int main() {
	std::ifstream fin("integers100000.txt");
	if (fin.fail()) { std::cout << "integers100000.txt failed to open." << std::endl; }

	int n;
	std::vector<int> v;
	while (fin >> n) {
		v.push_back(n);
	}

	std::cout << "Fast version: " << find_unique_fast(v) << std::endl;
	std::cout << "Medium version: " << find_unique_medium(v) << std::endl;
	std::cout << "Slow version: " << find_unique_slow(v) << std::endl;
	return 0;
}

int find_unique_slow(const std::vector<int>& v) {
	// For each number, v[i], in the vector...
	for (size_t i = 0; i < v.size(); ++i) {
		// ...initialize a counter...
		size_t count = 0;

		// ...and loop through the entire vector, checking to see if v[i] matches with any v[j].
		for (size_t j = 0; j < v.size(); ++j) {
			// If v[i] == v[j], then we must update the counter.
			if (v[i] == v[j]) {
				++count;
			}
		}

		// If count == 1, then we only saw one match, and actually, that one match was just the 
		// number matching itself. Therefore, we found the number that shows up only once.
		if (count == 1) {
			return v[i];
		}
	}
}

// Intentionally passing the vector by value because I don't want the sort of this function to mess 
// with the unordered-ness of the numbers for all other cases. 
int find_unique_medium(std::vector<int> v) {
	// Sort the vector
	std::sort(v.begin(), v.end());

	// Now, the number that shows up once will be the only number whose neighbors
	// are different from itself. We need to check the ends separately because 
	// they only have one neighbor each. 
	
	// First element
	if (v[0] != v[1]) {
		return v[0];
	}

	// Last element
	if (v[v.size()-1] != v[v.size()-2]) {
		return v[v.size()-1];
	}

	// All interior elements
	for (size_t i = 1; i < v.size() - 1; ++i) {
		if (v[i] != v[i-1] && v[i] != v[i+1]) {
			return v[i];
		}
	}
}

// This function could use the fact that I did say that the numbers are all
// less than 1000, but we don't necessarily need it. 
int find_unique_fast(const std::vector<int>& v) {
	// First, find the maximum number in the vector
	// Remember, we already know the vector consists of all positive numbers
	int max = v[0];
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i] > max) {
			max = v[i];
		}
	}	

	// Initialize a vector of length equal to max of all 0's.
	// counts[i] will keep track of the number of times (i+1) shows up. 
	// To be more specific...
	// 		counts[0] will count the number of 1s
	// 		counts[1] will count the number of 2s
	//		counts[2] will count the number of 3s
	// 		etc.
	// Hence, if a 3 shows up in the vector, we will add one to counts[2].
	std::vector<size_t> counts(max, 0);

	// For each number, v[i], in the vector...
	for (size_t i = 0; i < v.size(); ++i) {
		// ...increment the counts vector at position v[i] - 1
		++counts[v[i] - 1];
	}

	// Loop through the counts vector to find the one count that's equal to 1.
	// If it occurs in position i, then that means the number i+1 only showed up once.
	for (size_t i = 0; i < counts.size(); ++i) {
		if (counts[i] == 1) {
			return i+1;
		}
	}
}