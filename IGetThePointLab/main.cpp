#include <iostream>

#include "Point.hpp"

using std::cout;
using std::cin;

int main() {
	Point p1 = Point(1.0, 2.0);
	Point p2 = Point(-1.5, 6.5);
	Point p3 = Point(1.0, 2.0);
	Point midpoint12 = p1 / p2;

	cout << p1 - p2 << '\n';
	cout << (p1 == p3) << '\n';
	cout << (p1 == p2) << '\n';
	cout << (p1 != p3) << '\n';
	cout << (p1 != p2) << '\n';
	cout << (p1 != p2) << '\n';
	cout << midpoint12 << '\n';
	cout << p1 * 2 << '\n';
	cout << p1 * 4 << '\n';
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