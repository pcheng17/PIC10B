#include <iostream>
#include <memory>

class Base
{ 
public:
    Base() : x(0) { std::cout << "Base constructor called" << std::endl; }

    /** Destructor must be declared virtual so destructing objects in the context 
    	of polymorphism works!
    */
	virtual ~Base() { std::cout << "Base destructor called" << std::endl; }
};

class Derived: public Base
{
public:
	/** Constructor of the derived class must construct an instance of its base class
		in the field initializer list!
	*/
    Derived() : Base() { std::cout << "Derived constructor called" << std::endl; }

	~Derived() { std::cout << "Derived destructor called" << std::endl; }
};

int main()
{	
	/** You should run the following lines in a helpful way by only uncommenting one version 
		at a time.
	*/

	/** Example 1 - 2 lines of output */
	// Base x;

	/** Example 2 - 4 lines of output */
    // Derived y;

	/** Example 3 - 4 lines of output, requires virtual */
    // Base* b = new Derived;
    // delete b;

	/** Example 4 - 4 lines of output, requires virtual, destructs by itself */
    // std::unique_ptr<Base> b(new Derived);
}	








