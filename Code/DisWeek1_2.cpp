#include <iostream>

using namespace std;

void addOne(int* x)
{
	// Note the parentheses make it obvious as to what's happening here! 
	// Simply writing ++*x works too though.
	++(*x);		
	return;
}

void swap(int*& x, int*& y) 
{
	int* temp = x;
	x = y;
	y = temp;
}

int main() {
	/////////////////////////////////
	/** Example #1
		Take a look at the addOne function above. Though the function itself is kind of strange 
		(passing-by-pointer into the function seems unneccessary), the nature of the function 
		should be pretty straightforward. Will this function work as intended? Remember in 
		PIC 10A, in order for a function to make changes to a variable AND have those changes
		saved means we MUST pass-by-reference...
	*/

	int a = 1;
	addOne(&a);				// addOne takes in pointers to ints
	cout << a << endl;		// What will this line output?

	/** It still adds one to the integer even though we pass nothing by reference because 
		of pointers. The function takes a COPY of a pointer to the int, but that COPY
		still points to the int we want to add one to. 
	*/ 


	/////////////////////////////////
	/** Example #2
		Write a swap function that swaps two points-to-ints (or, two int*'s).
		The following code should then compile and run successfully!
	*/

	int x = 1;
	int y = 2;
	int* px = &x;
	int* py = &y;

	cout << "x = " << x << " and " << "y = " << y << endl;
	cout << "px points to " << *px << " and " << "py points to " << *py << endl;

	swap(px, py);

	cout << "x = " << x << " and " << "y = " << y << endl;
	cout << "px points to " << *px << " and " << "py points to " << *py << endl;

}