#include "Dagiacdeu.h"
#include "Painter.h"
NguGiacDeu::NguGiacDeu(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
}

void NguGiacDeu::draw()
{
	setLibColor();
	glBegin(GL_LINES);
	float alpha = al;
	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string NguGiacDeu::getType()
{
	return "Ngu Giac Deu";
}

Point NguGiacDeu::getCenter()
{
	return this->center;
}

void NguGiacDeu::fillColor(int x, int y, int colr_id)
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

DaGiacDeu::DaGiacDeu()
{
}

LucGiacDeu::LucGiacDeu(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
}

void LucGiacDeu::draw()
{
	setLibColor();

	glBegin(GL_LINES);
	float alpha = al;
	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha += al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());


	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string LucGiacDeu::getType()
{
	return "Luc Giac Deu";
}

Point LucGiacDeu::getCenter()
{
	return this->center;
}

void LucGiacDeu::fillColor(int x, int y, int colr_id)
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
