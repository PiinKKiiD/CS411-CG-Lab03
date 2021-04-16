#include "Shape.h"
#ifndef TAMGIAC_H_
#define TAMGIAC_H_
class TamGiac: public Shape {
public:
	TamGiac();
	virtual void draw() = 0;
	virtual string getType() = 0;
};


class TGVuongCan : public TamGiac {
private:
	float edge;
	Point other;
	Point getOther(Point a, Point b);
public:
	TGVuongCan(Point, Point);
	void draw();
	string getType();
};

class TGDeu : public TamGiac {
private:
	float edge;
	Point other;
	Point center;
public:
	TGDeu(Point a, Point b);
	void draw();
	string getType();

};
#endif // !TAMGIAC_H_

