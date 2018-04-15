#include <iostream>
#include <vector>
#include <string>


int main() {

	/** The variable a lives on the stack
		Anything that's declared without the words new lives on the stack, e.g. anything you 
		declared in PIC 10A lived on the stack.
	*/
	int a = 1;

	/** While the variable (pointer) py lives on the stack, "new int" allocates memory on the heap that can
		eventually be used to hold an int value. "new int" returns the address of the memory location 
		so py can save it. This way, we always have access to this location in memory (via a pointer).

		Note: things on the heap ARE NOT variables in that, they do not have names attached to the values. 
		The only way to access something on the heap is through an appropriate pointer, i.e. a pointer that
		points to the correct type.
	*/ 
	int* py = new int;

	/** Setting the value to which py points to 2.

		We can actually allocate memory on the heap AND set its value all in one line:
			int* py = new int(2);
			double* pd = new double(3.14);
			std::string* ps = new std::string("hello");
	*/ 
	*py = 2;

	/** Now, let's say I need to make py point to another int I want to allocate on the heap. I can't just
		write "py = new int" because then I completely lose access to the 2 we just set, which is called 
		a "memory leak." Basically, memory leak is how we refer to the situation where your code loses 
		track of memory that has been allocated on the heap. Remember, things on the heap don't have 
		variable names, so the moment you overrite an address to a location on the heap, you have no way
		of getting that address back, so that location in memory is forever gone for the rest of your program.

		So what do we do? See below!
	*/

	// I save the address in py into another int*, pz, so we have a copy of it! Now, we can overrite py!
	int* pz = py;

	// Redirects the pointer py to a new location in memory on the heap that will save an int 
	py = new int;

	// Setting the value to which py points to 3
	*py = 3;

	std::cout << py << std::endl;			// Some address
	std::cout << *py << std::endl;			// 3
	std::cout << pz << std::endl;			// Some address (not equal to py though)
	std::cout << *pz << std::endl;			// 2


	/* VERY IMPORTANT: Every NEW needs to be paired with a DELETE!!! 

		Delete will follow the pointer to where its pointing on the heap and destroy the contents 
		of that memory location. This doesn't destroy the memory location there, it just gets rid 
		of anything that was saved there, freeing up memory for the program to potentially use later. 

		The heap does not have its own garbage cleanup, meaning, memory that gets allocated on the
		heap will never get released until the end of the entire code unless we do something about 
		it. It's crucial that we remember to call delete on pointers that refer to locations on the heap
		the moment we're done with that location. 
		
		Of course, when your code finishes running, all memory that was allocated for any variable
		(stack or heap) gets released, so memory leaks won't damage your computer at all. However, they 
		are very bad when they occur while your program is running because this means your program has less
		memory available to use. Really badly written code can have so much memory leak that the code hogs
		up ALL of the memory on the heap, causing your code to crash. 

		Back to our code: there were two "new" keywords above, so we must have two "delete" 
		keywords here! One for py, one for pz, because both of them at this point are addresses to
		locations in memory on the heap.

		AGAIN: Every NEW needs to be paired with a DELETE!!!
	*/
	delete py;
	delete pz;

	/** Finally, it is good practice (I almost want to say it's required, but it's not) to set pointers
		that don't point to anything to nullptr. This way, we don't have any dangling pointers. Later on 
		in 10B, we'll see very concrete examples of why setting pointers that point to nothing to nullptr
		is actually extremely important.

		NOTE: You CANNOT set a pointer to nullptr before calling delete! Let's say you do. Setting a pointer
		to nullptr means you "remove" the arrow of the pointer, so the pointer points to nothing. Then, if you 
		were to call delete now, delete has no address to go to do its garbage cleanup. 
	*/
	py = nullptr;
	pz = nullptr;

	// Last time (for now): Every NEW needs to be paired with a DELETE!!!

	return 0;
}