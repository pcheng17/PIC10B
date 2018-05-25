#ifndef _LIST_
#define _LIST_

#include <cassert>

class Node;
class List;

class Iterator 
{
public:
	Iterator(const List* l, Node* n);
	~Iterator();

	Iterator& operator++();
	Iterator& operator--();

	/** Dereference operator that the compiler uses in cases where the 
		dereference is required to be const, meaning it can't be used 
		to change anything about the List
	*/
	const int& operator*() const;

	/** Dereference operator that the compiler uses in cases where the 
		dereference is used to modify the value of a Node in the List.
	*/
	int& operator*(); 

	/** This allows my Iterator objects to be treated as a bool,
		where the conversion to true/false depends on my definition
		of this function.
	*/
	operator bool() const;

	friend bool operator==(const Iterator& lhs, const Iterator& rhs);

private:
	Node* pos;
	const List* container;

	friend class List;
};

class Node 
{
public:
	Node(int data);

private:
	Node* next;
	Node* prev;
	int data;

	friend class Iterator;
	friend class List;
};

class List 
{
public:
	List();
	~List();

	Iterator begin() const;
	Iterator end() const;

	Iterator head() const;
	Iterator tail() const;

	void reverse();
	void merge(const List& x);
	void insert(const Iterator& it, int data);
	void push_back(int data);
	void push_front(int data);

private:
	Node* first;
	Node* last; 

	friend class Iterator;
	friend class Node;
};

/******************************************
	Iterator member function definitions
*******************************************/
Iterator::Iterator(const List* l, Node* n) : pos(n), container(l) {}

Iterator::~Iterator() {}

Iterator& Iterator::operator++() {
	assert(pos);
	pos = pos->next;
	return *this;
}

Iterator& Iterator::operator--() {
	assert(pos);
	pos = pos->prev;
	return *this;
}

const int& Iterator::operator*() const {
	assert(pos);
	return pos->data;
}

int& Iterator::operator*() {
	assert(pos);
	return pos->data;
}

Iterator::operator bool() const {
	return (pos && container);
}

bool operator==(const Iterator& lhs, const Iterator& rhs) {
	return (lhs.pos == rhs.pos) && (lhs.container == rhs.container);
}

bool operator!=(const Iterator& lhs, const Iterator& rhs) {
	return !(lhs == rhs);
}

/******************************************
	Node member function definitions
*******************************************/
Node::Node(int data) : prev(nullptr), next(nullptr), data(data) {}


/******************************************
	List member function definitions
*******************************************/
List::List() : first(nullptr), last(nullptr) {}

List::~List() {
	Node* curr = first;
	Node* next = first;
	while (curr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
}

Iterator List::begin() const {
	return Iterator(this, first);
}

Iterator List::end() const {
	return Iterator(this, nullptr);
}

Iterator List::head() const {
	return Iterator(this, first);
}

Iterator List::tail() const {
	return Iterator(this, last);
}

void List::reverse() {
	Node* prev = nullptr;
	Node* next = nullptr;
	Node* curr = first;

	while (curr) {
		next = curr->next;
		prev = curr->prev;
		curr->next = prev;
		curr->prev = next;
		prev = curr;
		curr = next;
	}

	Node* temp = first;
	first = last;
	last = temp;
}


void List::merge(const List& x) {
	if (!first) {
		for (auto i : x) {
			push_back(i);
		}
	} else {
		Iterator it1(this, first->next);
		Iterator it2 = x.begin();
		while (it1 && it2) {
			insert(it1, *it2);
			++it1;
			++it2;
		}
		while (it2) {
			push_back(*it2);
			++it2;
		}
	}
}

void List::insert(const Iterator& it, int data) {
	assert(it);
	Node* node = new Node(data);
	node->prev = it.pos->prev; 
	node->next = it.pos;
	node->prev->next = node;
	it.pos->prev = node;
}

void List::push_back(int data) {
	if (!first) {
		first = new Node(data);
		first->prev = nullptr; 
		first->next = nullptr;
		last = first; 
	} else {
		last->next = new Node(data);
		last->next->prev = last;
		last->next->next = nullptr;
		last = last->next;
	}
}

void List::push_front(int data) {
	if (!first) {
		first = new Node(data);
		first->prev = nullptr;
		first->next = nullptr;
		last = first; 
	} else {
		first->prev = new Node(data);
		first->prev->prev = nullptr;
		first->prev->next = first; 
		first = first->prev;
	}
}


#endif // _LIST_
