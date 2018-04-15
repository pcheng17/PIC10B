#include <iostream>
#include <string>

using namespace std;

class BankAccount 
{
public:

	/** Default constructor
	*/
	BankAccount();			

	/** Constructor for BankAccount
		@param name - a string argument for the name of the BankAccount
	*/					
	BankAccount(string name);

	/** Constructor for BankAccount
		@param name - a string argument for the name of the BankAccount
		@param amount - a double argument for the amount in the BankAccount
	*/
	BankAccount(string name, double amount);

	/** Accessor member function for the name member variable
		@return a string for the name
	*/
	string getName() const;

	/** Accessor member function for the amount member variable
		@return a double for the amount
	*/
	double getAmount() const; 

	/** Mutator member function to set/reset the name variable
		@param new_name - a string argument for the new name
	*/
	void setName(string new_name);

	/** Mutator member function to set/reset the name variable
		@param d - a double argument for the deposit amount
	*/
	void deposit(double d);

	/** Mutator member function to set/reset the name variable
		@param w - a double argument for the withdraw amount
	*/
	void withdraw(double w);

private:
	string name;
	double amount;
};


int main() {
	/** Example #1 - Create a BankAccount class */
	BankAccount x("Peter", 100);
	x.deposit(20);
	cout << x.getName() << " has " << "$" << x.getAmount() << endl;

	return 0;
}

/** Use the field initializer list for constructors!! 
	The syntax is: mVarName(inputVarName) 
	where mVarName is the member variable name and inputVarName is the input variable name.
	This sets the value of inputVarName into mVarName. 
*/
BankAccount::BankAccount() : name(""), amount(0.0) {}	

BankAccount::BankAccount(string name) : name(name), amount(0.0) {}	

BankAccount::BankAccount(string name, double amount) : name(name), amount(amount) {}

string BankAccount::getName() const { return name; }
double BankAccount::getAmount() const { return amount; }

void BankAccount::setName(string new_name) {
	name = new_name;
}

void BankAccount::deposit(double d) {
	amount += d;
}

void BankAccount::withdraw(double w) {
	amount -= w;
	if (amount < 0) 
		amount = 0;
}










