#pragma once
class TShape {

protected:
	double area_;
	double perimeter_;

public:
	double virtual getArea() = 0;
	double virtual getPerimetr() = 0;
};