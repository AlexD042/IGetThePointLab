#pragma once

class Point {
private:
	double x;
	double y;
public:
	// Constructor
	Point(double inputX = 0, double inputY = 0);
	
	// Getters/Setters
	double getX();
	double getY();
	void setX(double inputX);
	void setY(double inputY);

	// Operator Overloading
	double operator-(Point otherPoint);
	bool operator==(Point otherPoint);
	bool operator!=(Point otherPoint);
	Point operator/(Point otherPoint);
	Point operator*(double multiplier);
	Point operator++();
	Point operator++(int);
	Point operator--();
	Point operator--(int);
	double operator[](int i);
};

// Input/Output Handling
std::ostream& operator<<(std::ostream& output, Point p);
std::istream& operator>>(std::istream& input, Point& p);