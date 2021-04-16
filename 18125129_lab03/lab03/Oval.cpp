#include "Oval.h"
#include "settings.h"
HinhTron::HinhTron(Point s, Point e)
{
	this->start = s;
	this->end = e;
	radius = start.distanceTo(end);
	cout << radius << "---------" << endl;
}

void HinhTron::operator=(Oval const& a)
{
	this->start = a.start;
	this->end = a.end;
	radius = start.distanceTo(end);
	cout << radius<<"---------" << endl;
}

void HinhTron::draw()
{
	Point center = this->start;
	int r = this->radius;
	setLibColor();
	float theta;
	glPointSize(2);
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1415 / 180;
		glVertex2f(center.getX() + r * cos(theta), center.getY() + r * sin(theta));
	}
	glEnd();
}

string HinhTron::getType()
{
	return "Hinh Tron ne.";
}

Oval::Oval()
{
}


void Oval::draw()
{
}

HinhElip::HinhElip(Point s, Point e)
{
	this->start = s;
	this->end = e;
	biRa = start.distanceTo(end);
	smRa = 0.5 * biRa;
}

void HinhElip::draw()
{
	setLibColor();
	float theta;
	Point center = this->start;
	float bigR = this->biRa;
	float smallR = this->smRa;
	glPointSize(2);
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1415 / 180;
		glVertex2f(center.getX() + bigR * cos(theta), center.getY() + smallR * sin(theta));
	}
	glEnd();
}

string HinhElip::getType()
{
	return "Ellipse";
}
