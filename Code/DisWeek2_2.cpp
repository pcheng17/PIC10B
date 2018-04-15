#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
/** Typedefs are used to simplify variable types

	This typedef here is so that, if I want to use a function pointer that points at
	a funtion that takes in an int and returns an int, then the variable type of this
	pointer is now IntFunPtr.

	Look at argument list of modifyArray to see how I use it
*/
typedef int (*IntFunPtr) (int);

int square(int x) {
	return x*x;
}

void modifyArray(int* a, size_t size, IntFunPtr f) {
	for (size_t i = 0; i < size; ++i) {
		*(a + i) = f(*(a + i));
	}
}

int main() {
	/** Our goal is to create a vector<Student*> of pointers to Student objects
		Let's start from PIC 10A practices and build up to what we need for PIC 10B
	*/

	/** From PIC 10A, we might write something like this, which works, but it's not exactly
		what we want since we would like a vector of Student*'s.

		Also, as a side note that's not particularly important right now, but...

		This approach is not as efficient as you might think. The x variable we create
		right before the push_back is a variable that has local scope to the for loop,
		meaning that it will get destroyed everytime the for loop repeats itself. Hence, in
		order for the push_back function to actually successfully push Student x into the vector
		and have it stay in the vector, it must have created a copy of x, where this copy
		has larger scope than x itself. This means, for every student we want to insert
		into the vector, we're actually creating two instances!
	*/
	std::vector<Student> v;
	for (size_t i = 0; i < 10; ++i) {		// Assuming only 10 members
		// Ask the user for a name
		Student x(name);
		v.push_back(x);
	}

	/** Now, let's try and try and create our vector of Student*'s, but simply by adapting
		the code above naively.

		The code below shows good effort, but it's not quite there yet because of the same reason
		as before. The push_back will save a copy of the pointer to x into the vector, but the moment
		the for loop repeats itself, the x variable gets destroyed, leaving a dangling pointer behind.
	*/
	std::vector<Student*> w;
	for (size_t i = 0; i < 10; ++i) {
		// Ask the user for a name
		Student x(name);
		v.push_back(&x);
	}

	/* Okay, so what do we need? The "new" keyword!

		"new Student(name)" allocates memory on the heap for a Student object with the specified
		name. Then it returns a pointer to this Student object for the push_back function to push
		into our vector. When the for loop repeats, the Student object does not get destroyed
		because it's on the heap! The pointer doesn't get destroyed because it's saved in a vector
		with scope larger than the for loop. Everything worked! On top of this, we've only created
		exactly one instance of the Student object, as opposed to two instances if we were to use
		the PIC 10A version.
	*/

	std::vector<Student*> w;
	for (size_t i = 0; i < 10; ++i) {
		// Ask the user for a name
		w.push_back(new Student(name));
	}

	/** Every new keyword needs a delete to destroy the object AFTER we are done with it. So,
		we use a for loop to loop through the vector of all the pointers that point at objects
		on the heap and call delete on each one. After calling delete, we reset the pointer
		to nullptr (as a good habit) so pointers aren't pointing to nothing.
	*/
	for (size_t i = 0; i < w.size(); ++i) {
		delete w[i];
		w[i] = nullptr;
	}

	/** Example #1 - Parsing pointer types
		READ FROM RIGHT TO LEFT

		Both examples provided for p2 and p4 are the same! It doesn't matter what you use.
	*/

	int * p1;                   // pointer to an int

	const int * p2; 				// pointer to an int that's const
	int const * p2;				// pointer to a const int

	int * const p3;				// const pointer to an int

	const int * const p4;		// const pointer to an int that's const
	int const * const p4;		// const pointer to a const int


	/** Example #2 - Another example of new
		Write some code (no need for a function) that asks the user for a number,
		and then create an array of that size filled with whatever numbers you want.
	*/
	size_t size;
	std::cout << "Enter a number: ";
	std::cin >> size;

	// new also allows us to create arrays with non-const integer types!
	int* arr = new int[size];

	for (size_t i = 0; i < size; ++i) {
		*(arr + i) = rand() % 11;
	}

	/** Only one new is used to allocate space for an array, so only one delete is needed.
		However, we must use "delete[]" with a set of square brackets after it to indicate
		that the pointer we're trying to call delete on is a pointer to an array.
	*/
	delete[] arr;
	arr = nullptr;


	/** Example #3
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
	modifyArray(a, 5, square);

	for (size_t i = 0; i < 5; ++i) {
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;



}