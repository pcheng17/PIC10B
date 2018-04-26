#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

class Integer 
{
public:
	Integer();
	Integer(int x);

	Integer& operator++();
	Integer operator++(int unused);

	Integer& operator--();
	Integer operator--(int unused);

	Integer& operator+=(const Integer& rhs);
	Integer& operator-=(const Integer& rhs);
	Integer& operator*=(const Integer& rhs);

	int difference(const Integer& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const Integer& rhs);

private:
	int x;
};

Integer operator+(const Integer& lhs, const Integer& rhs);
Integer operator-(const Integer& lhs, const Integer& rhs);
Integer operator*(const Integer& lhs, const Integer& rhs);

bool operator<(const Integer& lhs, const Integer& rhs);
bool operator>(const Integer& lhs, const Integer& rhs);
bool operator==(const Integer& lhs, const Integer& rhs);
bool operator<=(const Integer& lhs, const Integer& rhs);
bool operator>=(const Integer& lhs, const Integer& rhs);

#endif // INTEGER_H