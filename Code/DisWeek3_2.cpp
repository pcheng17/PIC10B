#include <iostream>
#include <iomanip>			// output formatting
#include <fstream>			// ifstream, ofstream
#include <sstream>			// istringstream, ostringstream
#include <string>

int main() {

	std::string fileName = "readFile.txt";
	std::ifstream fin(fileName);				// or on the next line, fin.open(fileName);

	/** I use this if statement whenever I need to open a file to read in from. This way I will always know
		if an error occured with opening the file, whether it's because I typo-ed in the filename, or if 
		the file just doesn't exist.
	*/
	if (fin.fail()) {
		std::cout << "Couldn't open " << fileName << std::endl;
	}

	int numberCount = 0, wordCount = 0;
	int number;
	std::string line, word;
	char x;

	// While getline can still read another line from the file...
	while (getline(fin, line)) {							
								
		/** Initialize an istringstream object with the contents of line 
			(so now it's like we can read from the line variable as if it were us typing in the line)
		*/
		std::istringstream instr(line);					

		/** instr.get(x) gets the next char in the buffer. We can put this in the while loop condition 
			because the .get() function returns the stream that we're calling .get(x) on. If nothing 
			can be "get," the stream enters a fail-state, which basically means that we can't read 
			from it anymore. A stream in fail-state is equivalent to "false," so the while loop will end. 
		*/
		while (instr.get(x)) {
			// If the char represents a number...
			if ('0' <= x && x <= '9') 
			{
				instr.unget();			// unget the character (basically put the character back)
				instr >> number;		// read in the number we're currently trying to parse
				++numberCount;			// update numberCount
			} 
			// otherwise, if the char represents a capital or lower case letter...
			else if (('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z')) 
			{
				instr.unget();			// unget the character
				instr >> word;			// read in the word we're currently trying to parse
				++wordCount;			// update wordCount
			}

			/** Note that the if statements don't trigger if we .get() any symbols or whitepace characters (e.g. ' ', '\t', '\n')
				which is great because we don't want to do anything with those. Hence, even though >> doesn't read in any spaces, 
				the .get() function will help us remove them from the buffer.
			*/
		}
	}
	fin.close();		// Good practice to .close() files once we're done. Won't cause memory leaks without this, but still.

	// Just for fun, I'm going to write the following two lines to a new file
	std::ofstream fout("output.txt");
	fout << std::setw(15) << "Word count: " << wordCount << std::endl;
	fout << std::setw(15) << "Number count: " << numberCount << std::endl;
	fout.close();
}