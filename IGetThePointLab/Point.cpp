#include <cmath>
#include <iostream>

#include "Point.hpp"

using std::pow;

Point::Point(double inputX, double inputY) {
	x = inputX;
	y = inputY;
}

// Getters & Setters
double Point::getX() { return x; }
double Point::getY() { return y; }
void Point::setX(double inputX) { x = inputX; }
void Point::setY(double inputY) { y = inputY; }

// Distance between two points
double Point::operator-(Point otherPoint) {
	return sqrt((pow((otherPoint.getX() - x), 2)) + ((pow((otherPoint.getY() - y), 2))));
}

// Checks if two points are the same points
bool Point::operator==(Point otherPoint) {
	if (x == otherPoint.getX() && y == otherPoint.getY()) {
		return true;
	}
	return false;
}

// Checks if two points are not the same points
bool Point::operator!=(Point otherPoint) {
	if (x == otherPoint.getX() && y == otherPoint.getY()) {
		return false;
	}
	return true;
}

// Midpoint between two points
Point Point::operator/(Point otherPoint) {
	Point result = Point(0, 0);
	result.setX((x + otherPoint.getX()) / 2);
	result.setY((y + otherPoint.getY()) / 2);
	return result;
}

// Multiplies x & y by a constant
Point Point::operator*(double multiplier) {
	return Point(x * multiplier, y * multiplier);
}

// prefix increments x by 1
Point Point::operator++() {
	x = x + 1;
	return *this;
}

// postfix increments y by 1
Point Point::operator++(int) {
	y = y + 1;
	return *this;
}

// prefix decrements x by 1
Point Point::operator--() {
	x = x - 1;
	return *this;
}

// postfix decrements y by1
Point Point::operator--(int) {
	y = y - 1;
	return *this;
}

// access either x or y of a point
double Point::operator[](int i) {
	if (i == 0 || i == 'x' || i == 'X') {
		return x;
	}
	else if (i == 1 || i == 'y' || i == 'Y') {
		return y;
	}
	else {
		return 0;
	}
}

// Input/Output Handling

// Output a point formatted
std::ostream& operator<<(std::ostream& output, Point p) {
	output << '(' << p.getX() << ", " << p.getY() << ')';
	return output;
}

// Takes input of the form: "(x, y)"
std::istream& operator>>(std::istream& input, Point& p) {
	char c1; // '('
	input >> c1;

	double inputX; // 'x'
	input >> inputX;
	p.setX(inputX);

	char c2; // ','
	input >> c2;

	// spaces are ignored for cin

	double inputY; // 'y'
	input >> inputY;
	p.setY(inputY);

	char c3; // ')'
	input >> c3;

	return input;
}