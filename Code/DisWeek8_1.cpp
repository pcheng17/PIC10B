#include <iostream>
#include <set>

int main() {

	/** The big properties to remember about a set:
		1. It doesn't save copies of objects you've inserted. 
		2. A set automatically sorts its elements according to the < operator.
	*/

	std::set<int> s; 
	s.insert(3);
	s.insert(5);
	s.insert(3);
	s.insert(1);

	
	/** Here's a brief review of how to loop through an STL container to simply
		print out its contents.

		Since s is an std::set<int>, then we can use its iterator (std::set<int>::iterator) to 
		loop through the set. As usual, s.begin() and s.end() return the the iterators associated 
		with the beginning and end (actually one past the literal end) of the set. However, since 
		begin() was implemented with a return type, this means the compiler should automatically
		know what type the variable that catches the return of begin() has to be. Thus, we can use

		auto it = s.begin();

		to initialize our iterator!
	*/ 
	// for (auto it = s.begin(); it != s.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	/** I also mentioned there's something called a range-based for loop, 
		which assumes that the container you're looping through has iterators that can be 
		obtained using begin() and end(). Since std::sets satisfy this property, we can 
		very easily use a range-based for loop to loop through the set to print out its 
		elements. 

		const-ref correctness must be taken into account here. However, don't worry if 
		that hasn't stuck yet. It'll stick once you've seen it enough :) 
	*/
	for (const auto& x : s) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
























