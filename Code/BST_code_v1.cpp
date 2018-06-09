/** This version of TreeIterator assumes each TreeNode has a TreeNode* pointing to
	its parent! 

	I've also included the begin function for BST at the very end to show you
	how the TreeIterator pointing to the smallest element of the tree is initialized.
*/

class TreeIterator
{
public:
	TreeIterator(TreeNode* p, const BinarySearchTree* c);

	~TreeIterator() {}

	int operator*() const;

	TreeIterator& operator++();
	TreeIterator operator++(int);

	friend operator==(const TreeIterator& lhs, const TreeIterator& rhs);
private:
	TreeNode* pos;
	const BinarySearchTree* container;

	// potentially some friends?
};

TreeIterator::TreeIterator(TreeNode* p, const BinarySearchTree* c) : pos(pos), container(c) {}

// Dereference operator
int TreeIterator::operator*() const {
	assert(pos && container);
	return pos->data;
}

// Prefix increment
TreeIterator& TreeIterator::operator++() {
	assert(pos && container);

	// If we have a right child...
	if (pos->right) {
		// Go there...
		pos = pos->right;
		// ...and then go as far left as possible.
		while (pos->left) {
			pos = pos->left;
		}
	} else {	
		// However, if we don't have a right child, we move up until we get to a larger number
		int oldData = pos->data;
		while (pos->parent && pos->parent->data < oldData) {
			pos = pos->parent; 
		}
		// Need to move one more time to get to the node that we want to get to
		pos = pos->parent;
	}
	return *this;
}
	
// Postfix increment (relies on prefix!)
TreeIterator TreeIterator::operator++(int) {
	TreeIterator clone(pos, container);
	++(*this);
	return clone;
}

bool operator==(const TreeIterator& lhs, const TreeIterator& rhs) {
	return (lhs.pos == rhs.pos) && (lhs.container == rhs.container);
}

bool operator!=(const TreeIterator& lhs, const TreeIterator& rhs) {
	return !(lhs == rhs);
}

TreeIterator BinarySearchTree::begin() const {
	TreeNode* pos = root;
	while (pos->left) {
		pos = pos->left;
	}
	return TreeIterator(pos, this);
}