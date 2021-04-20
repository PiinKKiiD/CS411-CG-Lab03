#include <string>
#include <iostream>
#include "Point.h"
#include "Color.h"
#include "glut.h"
using namespace std;
#ifndef SHAPE_H_
#define SHAPE_H_


class Shape {
public:
	Point start;
	Point end;
	Point center;
	int fill;
public:
	Shape();//Note here
	virtual void draw() = 0;
	virtual string getType() = 0;
	virtual Point getCenter() = 0;
	virtual void fillColor(int x, int y, int colr_id) = 0;
	void setLibColor();

};

#endif // !1


