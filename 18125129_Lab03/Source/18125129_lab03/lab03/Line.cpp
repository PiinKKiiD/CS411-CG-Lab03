#include "Line.h"

Line::Line(Point s, Point e)
{
	this->center = s.midMointTo(e);
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

Point Line::getCenter()
{
	return this->center;
}

void Line::fillColor(int x, int y, int colr_id)
{
	this->fill = colr_id;
}
