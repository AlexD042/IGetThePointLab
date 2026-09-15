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

	void printFormatted() {
		cout << '(' << x << ", " << y << ')';
	}

};

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
	midp12.printFormatted();
	cout << '\n';

	return 0;
}