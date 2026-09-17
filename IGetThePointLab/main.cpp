#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using std::pow;
using std::cout;
using std::cin;
using std::string;

class Point {
private:
	double x;
	double y;
public:
	Point(double inputX = 0, double inputY = 0) {
		x = inputX;
		y = inputY;
	}

	// Getters & Setters
	double getX() { return x; }
	double getY() { return y; }
	void setX(double inputX) { x = inputX; }
	void setY(double inputY) { y = inputY; }

	// Distance between two points
	double operator-(Point otherPoint) {
		return sqrt((pow((otherPoint.getX() - x), 2)) + ((pow((otherPoint.getY() - y), 2))));
	}

	// Checks if two points are the same points
	bool operator==(Point otherPoint) {
		if (x == otherPoint.getX() && y == otherPoint.getY()) {
			return true;
		}
		return false;
	}

	// Checks if two points are not the same points
	bool operator!=(Point otherPoint) {
		if (x == otherPoint.getX() && y == otherPoint.getY()) {
			return false;
		}
		return true;
	}

	// Midpoint between two points
	Point operator/(Point otherPoint) {
		Point result = Point(0, 0);
		result.setX((x + otherPoint.getX()) / 2);
		result.setY((y + otherPoint.getY()) / 2);
		return result;
	}

	// Multiplies x & y by a constant
	Point operator*(double multiplier) {
		x *= multiplier;
		y *= multiplier;
		return *this;
	}

	// prefix increments x by 1
	Point operator++() {
		x = x + 1;
		return *this;
	}

	// postfix increments y by 1
	Point operator++(int) {
		y = y + 1;
		return *this;
	}

	// prefix decrements x by 1
	Point operator--() {
		x = x - 1;
		return *this;
	}

	// postfix decrements y by1
	Point operator--(int) {
		y = y - 1;
		return *this;
	}

	// access either x or y of a point
	double operator[](int i) {
		if (i == 0) {
			return (*this).getX();
		}
		else if (i == 1) {
			return (*this).getY();
		}
		else {
			return 0;
		}
	}

};

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

int main() {
	Point p1 = Point(1.0, 2.0);
	Point p2 = Point(-1.5, 6.5);
	Point p3 = Point(1.0, 2.0);
	Point midp12 = p1 / p2;

	cout << p1 - p2 << '\n';
	cout << (p1 == p3) << '\n';
	cout << (p1 == p2) << '\n';
	cout << (p1 != p3) << '\n';
	cout << (p1 != p2) << '\n';
	cout << (p1 != p2) << '\n';
	cout << midp12 << '\n';
	cout << p1 * 2 << '\n';
	cout << ++p1 << '\n';
	cout << p1++ << '\n';
	cout << --p1 << '\n';
	cout << p1-- << '\n';
	cout << p1[0] << '\n';
	cout << p1[1] << '\n';

	Point p;
	cin >> p;
	cout << p;

	return 0;
}