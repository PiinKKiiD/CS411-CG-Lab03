#ifndef SHAPE_H_
#define SHAPE_H_
#include "Point.h"
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


