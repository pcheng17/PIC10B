#include <iostream>
#include "Integer.h"

Integer::Integer() : x(0) {}

Integer::Integer(int x) : x(x) {}

Integer& Integer::operator++() {
	x = x + 1;
	return *this;
}

Integer Integer::operator++(int unused) {
	Integer clone(*this);
	x = x + 1;
	return clone;
}

Integer& Integer::operator--() {
	x = x - 1;
	return *this;
}

Integer Integer::operator--(int unused) {
	Integer clone(*this);
	x = x - 1;
	return clone;
}

Integer& Integer::operator+=(const Integer& rhs) {
	x = x + rhs.x;
	return *this;
}

Integer& Integer::operator-=(const Integer& rhs) {
	x = x - rhs.x;
	return *this;
}

Integer& Integer::operator*=(const Integer& rhs) {
	x = x * rhs.x;
	return *this;
}

int Integer::difference(const Integer& rhs) const {
	return x - rhs.x;
}

Integer operator+(const Integer& lhs, const Integer& rhs) {
	Integer sum = lhs;
	sum += rhs;
	return sum;
}

Integer operator-(const Integer& lhs, const Integer& rhs) {
	Integer diff = lhs;
	diff -= rhs;
	return diff;
}

Integer operator*(const Integer& lhs, const Integer& rhs) {
	Integer prod = lhs;
	prod *= rhs;
	return prod;
}

bool operator<(const Integer& lhs, const Integer& rhs) {
	return lhs.difference(rhs) < 0;
}

bool operator>(const Integer& lhs, const Integer& rhs) {
	return lhs.difference(rhs) > 0;
}

bool operator==(const Integer& lhs, const Integer& rhs) {
	return lhs.difference(rhs) == 0;
}

bool operator<=(const Integer& lhs, const Integer& rhs) {
	return !(lhs > rhs);
}

bool operator>=(const Integer& lhs, const Integer& rhs) {
	return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const Integer& rhs) {
	os << rhs.x;
	return os;
}