## Discussion Code

I will be using this page to post all of my code from discussion so that no one needs to go through the extra authentication step just to log into CCLE.

### Final Exam Prep
This is my own [final exam prep](final_prep.html) for you guys, and hence has nothing to do with the actual final exam that Professor Falcon is writing. I purposely included problems that are more comprehensive and a little more difficult to get you guys thinking more.<br><br>
Here are the [solutions](final_prep_solutions.html).<br><br>
Click [here](Code/BST_code_v1.cpp) and [here](Code/BST_code_v2.cpp) for two versions of the TreeIterator class that could have been defined for the homework assignment. The first link brings you to the version that most people implemented, which assumes that each TreeNode has a pointer to its parent. The second version does not make such an assumption, and instead, uses a stack data structure within the TreeIterator.

#### Week 8, Thursday (5/24)
<a href="Code/List.h" download>List.h</a>, <a href="Code/ListTest.cpp" download>ListTest.cpp</a><br>
Here is my version of how the homework regarding implementation of a linked list could be done, minus the sort function. I included a few things that you guys haven't seen before, which are things that you aren't required to know for the class. However, they may be helpful for the next homework assignment.

#### Week 8, Tuesday (5/22)
<a href="Code/DisWeek8_1.cpp" download>DisWeek8_1.cpp</a><br>
Though we spent most of the time in discussion talking about the homework assignment regarding lists, I spent a little bit of time talking about set, which is something we're going to need to be very familiar with very soon. 

#### Week 7, Tuesday/Thursday (5/15, 5/17)
<a href="Code/DisWeek7_1.cpp" download>DisWeek7_1.cpp</a><br>
I talked about iterators in the context of vectors. I also demonstrated the new "range-based" for loop and the `auto` keyword. 

#### Week 6, Thursday (5/10)
<a href="Code/integers100000.txt" download>integers100000.txt</a><br>
A text file we might use in discussion.

#### Week 5, Tuesday (5/1)
<a href="Code/BaseDerived.cpp" download>BaseDerived.cpp</a><br>
We went through an overview of inheritance, polymorphism, and the importance of the `virtual` keyword. The code that I've attached is an example of why `virtual` is important, and why we must include a destructor in the base class. Remember, the moment we design classes that use inheritance, we immediately allow polymophism to be used. This means that we need to think about destructors and virtual functions.

#### Week 4, Tuesday (4/24)
<a href="Code/Integer.h" download>Integer.h</a>, <a href="Code/Integer.cpp" download>Integer.cpp</a>, <a href="Code/DisWeek4_1.cpp" download>DisWeek4_1.cpp</a><br>
We spent the entire discussion talking about operator overloads, using an Integer class as an example for their implementation. The declarations for the class and non-member functions are in the header file, while all of the definitions can be found in the associated cpp file. Then, a short `int main()` is included in DisWeek4_1.cpp to demonstrate that the operators do work. I included an overload for `operator<<` so I could output the results to verify everything works. We'll talk about that on Thursday. Here are the take-away points from today's discussion:
* An operator overload should only be a member function if it prioritizes the left-hand side argument, with the exception of `operator++` and `operator--` (both postfix and prefix versions). This includes `+=`, `-=`, `*=`, and `/=`.
* Thus, an operator overload should not be a member function if it doesn't prioritize either of the two arguments when calling the operator. This includes `+`, `-`, `*`, `/`, `<`, `<=`, `>`, `>=`, and `==`.
* Return by reference is only relevant for the operator overloads that are member functions. It's used exactly when the operator returns `*this`, i.e. an object that already exists beyond the scope of the function being called. 

#### Week 3, Thursday (4/19)
<a href="Code/DisWeek3_2.cpp" download>DisWeek3_2.cpp</a>, <a href="Code/readFile.txt" download>readFile.txt</a><br>
We talked about streams and put together code that counts the number of words and numbers in the file that I posted. Again, Mac users will find this [link](https://stackoverflow.com/questions/23438393/new-to-xcode-cant-open-files-in-c) really helpful in getting XCode projects set up to open files with `std::ifstream` and `std::ofstream` objects.

#### Week 3, Tuesday (4/17)
<a href="Code/DisWeek3_1.cpp" download>DisWeek3_1.cpp</a>, <a href="Code/integers.txt" download>integers.txt</a><br>
We officially talked about `typedef` and function pointers. Then, we briefly saw a quick introduction to file streams. We'll see way more on Thursday. I've also posted integers.txt, the text file that we practiced reading in from. For Mac users, this [link](https://stackoverflow.com/questions/23438393/new-to-xcode-cant-open-files-in-c) will be really helpful in getting your projects setup to open files with `std::ifstream` and `std::ofstream` objects. 

#### Week 2, Thursday (4/12)
<a href="Code/DisWeek2_2.cpp" download>DisWeek2_2.cpp</a><br>
I presented some examples of why `new` and `delete` are important to know. We also talked about different pointer types. I included the example that I wanted to use to talk about function pointers, but I didn't actually get around to it. In order to compile this code to see the output of the final example, you need to comment out almost everything else in `int main()`.

#### Week 2, Tuesday (4/10)
<a href="Code/DisWeek2_1.cpp" download>DisWeek2_1.cpp</a><br>
We spent the entire discussion talking about `new` and `delete`, which also involves a discussion of the stack and heap. I added a ton of comments that summarize what we actually talked about. 

#### Week 1, Thursday (4/5)
<a href="Code/DisWeek1_2.cpp" download>DisWeek1_2.cpp</a><br>
Practice with pointers. We talked about what pointers are, and looked at some examples of how they're used. 

#### Week 1, Tuesday (4/3)
<a href="Code/DisWeek1_1.cpp" download>DisWeek1_1.cpp</a><br>
A review of classes from PIC 10A. I also demonstrate the commenting style for functions that Professor Falcon requires. 

