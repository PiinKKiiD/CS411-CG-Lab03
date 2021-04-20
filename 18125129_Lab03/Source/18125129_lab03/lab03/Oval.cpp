#include "Oval.h"
#include "settings.h"
#include "Painter.h"
HinhTron::HinhTron(Point s, Point e)
{
	this->start = s;
	this->end = e;
	this->center = s;
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
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1415 / 180;
		glVertex2f(center.getX() + r * cos(theta), center.getY() + r * sin(theta));
	}
	//cout << "fill hereeeee: " <<this->fill << endl;

	glEnd();
	if (this->fill > 0) {
		//cout << "fill here: " << fill << endl;
		this->fillColor(this->center.getX(), this->center.getY(), fill);
	}
}

string HinhTron::getType()
{
	return "Hinh Tron ne.";
}

Point HinhTron::getCenter()
{
	return this->center;
}

void HinhTron::fillColor(int x, int y, int colr_id)
{
	//cout << colr_id << " ne" << endl;
	if (colr_id == mauDo_id) {
		BoundaryFill(x, y, mauDo, mauVien);
		//RGBColor ol = GetPixel(this->center.getX(), this->center.getY());
		//floodFill(x, y, ol, mauDo);
	}
	else if (colr_id == mauVang_id) {
		BoundaryFill(x, y, mauVang, mauVien);
		//RGBColor ol = GetPixel(this->center.getX(), this->center.getY());
		//floodFill(x, y, ol, mauDo);
	}
	else if (colr_id == mauXanh_id) {
		BoundaryFill(x, y, mauXanh, mauVien);
		//RGBColor ol = GetPixel(this->center.getX(), this->center.getY());
		//floodFill(x, y, ol, mauDo);
	}
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
	this->center = s;
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
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1415 / 180;
		glVertex2f(center.getX() + bigR * cos(theta), center.getY() + smallR * sin(theta));
	}

	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string HinhElip::getType()
{
	return "Ellipse";
}

Point HinhElip::getCenter()
{
	return this->center;
}

void HinhElip::fillColor(int x, int y, int colr_id)
{
	if (colr_id == mauDo_id) {
		BoundaryFill(x, y, mauDo, mauVien);
	}
	else if (colr_id == mauVang_id) {
		BoundaryFill(x, y, mauVang, mauVien);
	}
	else if (colr_id == mauXanh_id) {
		BoundaryFill(x, y, mauXanh, mauVien);
	}
}
