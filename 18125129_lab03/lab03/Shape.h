#include "Point.h"
#include "glut.h"
#ifndef SHAPE_H_
#define SHAPE_H_


class Shape {
private:
	int button; int state;
		int x; int y;
public:
	Shape();
	virtual void Draw() =0;
	void mouse();
};

#endif // !1


