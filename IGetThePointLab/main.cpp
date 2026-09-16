#include <cmath>
#include <iostream>
#include <string>

using std::pow;
using std::cout;
using std::string;

class Point {
private:
	double x;
	double y;
public:
	Point(double inputX, double inputY) {
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

	Point operator*(double multiplier) {
		x *= multiplier;
		y *= multiplier;
		return *this;
	}

	// prefix increments x
	Point operator++() {
		x = x + 1;
		return *this;
	}

	// postfix increments y
	Point operator++(int) {
		y = y + 1;
		return *this;
	}

	// prefix decrements x
	Point operator--() {
		x = x - 1;
		return *this;
	}

	// postfix decrements y
	Point operator--(int) {
		y = y - 1;
		return *this;
	}

	void printFormatted() {
		cout << '(' << x << ", " << y << ')';
	}

};

std::ostream& operator<<(std::ostream& output, Point p) {
	output << '(' << p.getX() << ", " << p.getY() << ')';
	return output;
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

	return 0;
}