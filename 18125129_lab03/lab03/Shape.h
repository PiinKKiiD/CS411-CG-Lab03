#include <string>
#include <iostream>
#include "Point.h"
#include "glut.h"
using namespace std;
#ifndef SHAPE_H_
#define SHAPE_H_


class Shape {
public:
	Point start;
	Point end;
public:
	Shape();//Note here
	virtual void draw() = 0;
	virtual string getType() = 0;
	void setLibColor()
	{
		glColor3f(1.0f, 0.75f, 0.0f);
	};
};

#endif // !1


