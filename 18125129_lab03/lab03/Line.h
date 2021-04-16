#include "Shape.h"
#ifndef LINE_H_
#define LINE_H_
class Line : public Shape {
public:
	Line(Point s, Point e);
	string getType();
	void draw();
};
#endif