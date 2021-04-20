#include "Dau.h"
#include "Painter.h"
Dau::Dau()
{
}

DauCong::DauCong(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	width = c.distanceTo(btmRight) / 6;
	if (btmRight.getX() > c.getX()) {
		center = btmRight;
		end = c;
	}
}

void DauCong::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINES);
	Point temp = end;
	Point temp2 = center;
	//Ngang
	temp.setCoor(end.getX(), this->end.getY() + width);
	temp2.setCoor(temp2.getX() + width, temp2.getY() + width);
	glVertex2f(temp.getX(), temp.getY());
	glVertex2f(temp2.getX(), temp2.getY());
	glVertex2f(temp.getX(), temp.getY());

	temp.setCoor(temp.getX(), temp.getY() - 2 * width);
	temp2.setCoor(temp2.getX(), temp2.getY() - 2 * width);

	glVertex2f(temp.getX(), temp.getY());
	glVertex2f(temp.getX(), temp.getY());
	glVertex2f(temp2.getX(), temp2.getY());

	glVertex2f(temp2.getX(), temp2.getY());
	//Quay temp 90:
	float alpha = 90;

	temp.setCoor((temp.getX() - temp2.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - temp2.getY()) * sin(alpha * 3.1415 / 180)) + temp2.getX(), ((temp.getX() - temp2.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY()  - temp2.getY()) * cos(alpha * 3.1415 / 180) + temp2.getY());
	glVertex2f(temp.getX(), temp.getY());

	glVertex2f(temp.getX(), temp.getY());
	temp.setCoor(temp.getX() + 2*width, temp.getY());
	glVertex2f(temp.getX(), temp.getY());

	glVertex2f(temp.getX(), temp.getY());
	temp2.setCoor(temp2.getX() + 2 * width, temp2.getY());
	glVertex2f(temp2.getX(), temp2.getY());

	glVertex2f(temp2.getX(), temp2.getY());
	//Quay temp
	temp.setCoor((temp.getX() - temp2.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - temp2.getY()) * sin(alpha * 3.1415 / 180)) + temp2.getX(), ((temp.getX() - temp2.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - temp2.getY()) * cos(alpha * 3.1415 / 180) + temp2.getY());
	glVertex2f(temp.getX(), temp.getY());

	glVertex2f(temp.getX(), temp.getY());
	temp.setCoor(temp.getX() , temp.getY() + 2 * width);
	glVertex2f(temp.getX(), temp.getY());

	glVertex2f(temp.getX(), temp.getY());
	temp2.setCoor(temp2.getX() , temp2.getY() + 2 * width);
	glVertex2f(temp2.getX(), temp2.getY());

	glVertex2f(temp2.getX(), temp2.getY());
	//Quay temp
	temp.setCoor((temp.getX() - temp2.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - temp2.getY()) * sin(alpha * 3.1415 / 180)) + temp2.getX(), ((temp.getX() - temp2.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - temp2.getY()) * cos(alpha * 3.1415 / 180) + temp2.getY());
	glVertex2f(temp.getX(), temp.getY());

	glVertex2f(temp.getX(), temp.getY());
	temp.setCoor(temp.getX() - 2 * width, temp.getY() );
	glVertex2f(temp.getX(), temp.getY());

	glVertex2f(temp.getX(), temp.getY());
	temp2.setCoor(temp2.getX() - 2 * width, temp2.getY());
	glVertex2f(temp2.getX(), temp2.getY());

	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string DauCong::getType()
{
	return "Dau Cong";
}

Point DauCong::getCenter()
{
	return this->center;
}

void DauCong::fillColor(int x, int y, int colr_id)
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

DauTru::DauTru(Point c, Point btmRight)
{
	this->other.setCoor(2 * c.getX() - btmRight.getX(), 2 * c.getY() - btmRight.getY());
	this->center = c;
	this->end = btmRight;
	width = c.distanceTo(btmRight) / 7;
}

void DauTru::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(this->other.getX(), this->other.getY() + width);
	glVertex2f(this->end.getX(), this->end.getY() + width);

	glVertex2f(this->other.getX(), this->other.getY() - width);
	glVertex2f(this->end.getX(), this->end.getY() - width);

	glVertex2f(this->end.getX(), this->end.getY() + width);
	glVertex2f(this->end.getX(), this->end.getY() - width);


	glVertex2f(this->other.getX(), this->other.getY() + width);
	glVertex2f(this->other.getX(), this->other.getY() - width);

	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string DauTru::getType()
{
	return "Dau Tru";
}

Point DauTru::getCenter()
{
	return this->center;
}

void DauTru::fillColor(int x, int y, int colr_id)
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
