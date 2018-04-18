#include <iostream>
#include <vector>
#include <string>
#include <fstream>		// file stream
#include <sstream>		// string stream

/** Typedef 
	A typedef is an alias for a variable name - in other words, it's like a nickname you can give
	for variable types. Once you've typedef-ed a variable type, you can then use the nickname 
	exactly when you'd use the variable name. It's particularly helpful for length variable
	names. 

	I've included two typedefs here, one for function pointers (details below), the other for
	std::vector<std::string>, which is a farely lengthy variable name to type out. Then, 
	whenever I need to use an std::vector<std::string>, I can just write VecString. 

	You should stay away from using typedefs in your class header/cpp files because if anyone 
	else were to use your classes, they'd be forced to deal with your typedefs as well. What
	if they want to typedef a variable to be a different name? Or what if they need a typedef 
	you defined to represent a different variable type? Hence, typedefs should only go in your
	int main() cpp file. 
*/
typedef int (*IntFunPtr) (int);
typedef std::vector<std::string> VecString;

/** Function pointers
	Function pointers allow us to pass functions into other functions. Why we would need something
	like this is (hopefully) represented in my example below. Say we have a function that modifies
	the contents of the array. However you want to square all the components, whereas I want to simply
	add two to each. Instead of using having to write two "modifyArray" functions, one that's hard-
	coded to square numbers, and the other being hard-coded to add two to numbers, we can define 
	one modifyArray function and have one of its parameters be a function pointer. Then, when you 
	call it, you pass in a "square" function, and I pass in an "addTwo" function.

	However, function pointers are confusing for various reasons. The biggest one is that the variable
	type for a function pointer and the name of the variable holding that function pointer are mixed
	together. It's not as nice as like, "int x", where the variable type and variable name sit next
	to each other very nicely. For example,

	int (*f) (int) is a function pointer (with variable name f) to a function that takes in an int 
	and returns an int

	double (*g) (double, int) is a function pointer (with variable name g) to a function that takes in 
	a double and an int, and returns a double.

	The easiest way to not have to deal with this confusion is to typedef function pointers (see 
	above for a typedef). That typedef above basically says, IntFunPtr is now the name of the 
	variable type for function pointers for functions that takes in an int and returns and in. If you 
	look a few lines down, you'll see me use it as the variable type for the third argument in my
	modifyArray function. 
*/ 

int square(int x) {
	return x*x;
}

int addTwo(int x) {
	return x + 2;
}

void modifyArray(int* a, size_t size, IntFunPtr f) {
	for (size_t i = 0; i < size; ++i) {
		*(a + i) = f(*(a + i));
	}
}

int main() {
	/** Example #1
		Write a function called modifyArray that takes in three arguments:
			1) an array of ints (use a pointer here, not the 10A way, to pass in the array)
			2) the size of the array
			3) a pointer to a function that takes in an int and returns an int
		The modifyArray function will then apply the function pointer to each of the elements
		in the array, overwriting the old element each time.

		For example, if my array were {1, 2, 3, 4} and my function squares ints,
		then the result should be an array that contains {1, 4, 9, 16}.
	*/
	int a[5] = {1, 2, 3, 4, 5};

	// square is a function I defined above int main()
	// You can swap it out for addTwo as well! Or anything you want to define!
	modifyArray(a, 5, square);

	for (size_t i = 0; i < 5; ++i) {
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;

	/** Example #2
		Read in integers.txt and save the contents into a std::vector<int>.
	*/

	/** When we read in from files, we need to declare our own "cin"-like object. These have
		type std::ifstream, and I like to call it fin because it looks like cin.

		Then, fin needs to be associated with a file that it's supposed to read from. Hence, I
		need call fin.open() with the filename plugged in. Now, anytime I read in from fin, 
		it'll be read from the file (but the file WILL NOT BE CHANGED).
	*/
	std::ifstream fin;
	fin.open("integers.txt");

	/** We should ALWAYS include this kind of if statement after opening a file that we want to
		read in because the .open() function won't actually tell us if the file wasn't successfully 
		opened. Opening a file could fail if we made a mistake in writing the file name or if the
		file doesn't exist in the correct place. 
	*/
	if (fin.fail()) 
		std::cout << "integers.txt failed to open." << std::endl;

	int x;
	std::vector<int> v;

	/** This while loop says, "while fin can still read in from the file into the int x, push
		x into the vector v." This means that, as long as the text file contains only integers,
		this while loop can make it all the way to the end of the file, reading everything into
		the vector v.

		There are two ways that this while loop will end. The most obvious one is when fin has 
		finished reading everything in the file. If there's nothing else to read, then fin can't
		read into x anymore, so the statement "fin >> x" evaluates to false. The second way the
		while loop can quit is if fin runs into something in the file that it can't read into an 
		int. I demonstrated this in discussion by putting a random string in the middle of the
		numbers in the file, and then observing that if I ran the code, the reading of the file
		stops right when fin tries to read the string. 

		We will soon see how to deal with cases like that.
	*/
	while (fin >> x) {
		v.push_back(x);
	}	

	// Printing the vector out as a sanity check 
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

}