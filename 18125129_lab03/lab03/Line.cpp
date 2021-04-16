#include "Line.h"

Line::Line(Point s, Point e)
{
	this->start = s;
	this->end = e;
}

string Line::getType()
{
	return "Line";
}

void Line::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(this->start.getX(), this->start.getY());
	glVertex2f(this->end.getX(), this->end.getY());
	glEnd();
}
