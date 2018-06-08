#include <iostream>
#include <vector>
#include <fstream>

/** I think most people will come up with one of the following two versions.
	The fast version relies on knowing the range of numbers that show
	up in the vector, which I've provided to you in the problem statement.
*/ 
int find_unique_slow(const std::vector<int>& v);
int find_unique_fast(const std::vector<int>& v, int max);

int main() {

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

// This function uses the fact that we know the range of numbers that show up 
// in the vector, i.e. [1, max]
int find_unique_fast(const std::vector<int>& v, int max) {

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