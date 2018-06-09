/** This version of TreeIterator assumes each TreeNode DOES NOT have a TreeNode* 
	pointing to its parent. I'm posting this version as well because a small handful 
	of students tried to do it this way, but found it rather difficult. Read each line 
	carefully because this version differs from the other version by a lot.

	VERY IMPORTANT: This version of the TreeIterator DOES NOT integrate very easily
	into your version of a BST with parent pointers, EVEN if you were to just take the 
	parent pointers out of each TreeNode!!! The reason why is because the lack of a 
	parent pointer forces a TreeIterator to have to save a std::stack<TreeNode*>.
	This means that initializing a TreeIterator becomes much harder to do, i.e. 
	you CANNOT just save a pointer for the position and a pointer for a container.

	I've also included the begin function for BST at the very end to show you
	how the TreeIterator pointing to the smallest element of the tree is initialized
	in this case.
*/

#include <stack>

class TreeIterator
{
public:
	TreeIterator();
	TreeIterator(const std::stack<TreeNode*>& s, const BinarySearchTree* c);

	~TreeIterator() {}

	int operator*() const;

	TreeIterator& operator++();
	TreeIterator operator++(int);

	friend operator==(const TreeIterator& lhs, const TreeIterator& rhs);
private:
	/** Instead of saving a TreeNode* for the position, we'll be saving a stack
		of TreeNode*. Recall that a stack is a data structure where we only have 
		access to the thing that's most recently placed on the stack... hence 
		the name, stack! 

		The top TreeNode* of this stack will always be the current position. 
		All of the TreeNode*s below the top one are all the TreeNode*s that we had to
		walk through down the tree to get to the current TreeNode*. This is essentially
		saving all of the parents of the current node in the order in which we visited
		them.
	*/
	std::stack<TreeNode*> stack;
	const BinarySearchTree* container;

	// potentially some friends?
};

TreeIterator::TreeIterator() : stack({}), container(nullptr) {}

TreeIterator::TreeIterator(const std::stack<TreeNode*>& s, const BinarySearchTree* c)
	: stack(s), container(c) {}

// Dereference operator
int TreeIterator::operator*() const {
	// We assert that the stack isn't empty because if it were 
	// empty, then we must not be inside the tree (since the top
	// of the stack will always be the current position).
	assert((stack.size() != 0) && container);
	return (stack.top()->data);		// . happens first, then ->, so no extra parentheses needed
}

// Prefix increment
TreeIterator& TreeIterator::operator++() {
	assert((stack.size() != 0) && container);

	// If current position has a right child...
	if (stack.top()->right) {
		// ...push the right child on top of the stack (meaning we move there)...
		stack.push(stack.top()->right);
		// ...then go as far left as possible (push all left children on to the stack).
		while (stack.top()->left) {
			stack.push(stack.top()->left);
		}
	} else {	
		// However, if current position doesn't have a right child, we move up until we
		// get to a larger number, which amounts to popping things off the top of the stack
		// until we reveal a larger number.

		// Save the data that we're currently at
		int oldData = stack.top()->data;

		// We must move up AT LEAST once, so automatically pop the top
		stack.pop();

		// Now, work our way up the tree (i.e. down the stack) until we get 
		// to a larger number
		while (stack.size() != 0 && stack.top()->data < oldData) {
			stack.pop();
		}
	}
	return *this;
}
	
// Postfix increment (relies on prefix!)
TreeIterator TreeIterator::operator++(int) {
	TreeIterator clone(stack, container);
	++(*this);
	return clone;
}

bool operator==(const TreeIterator& lhs, const TreeIterator& rhs) {
	// Remember, the top of the stack is ALWAYS the current position
	return (lhs.stack.top() == rhs.stack.top()) && (lhs.container == rhs.container);
}

bool operator!=(const TreeIterator& lhs, const TreeIterator& rhs) {
	return !(lhs == rhs);
}

TreeIterator BinarySearchTree::begin() const {
	std::stack<TreeNode*> stack;
	if (root) {
		stack.push(root);
	}
	while (stack.top()->left) {
		stack.push(stack.top()->left);
	}
	return TreeIterator(stack, this);
}