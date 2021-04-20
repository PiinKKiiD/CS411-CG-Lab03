#include "Hinhkhac.h"
#include "Painter.h"

HinhKhac::HinhKhac()
{
}
NgoiSao::NgoiSao(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	minEdge = c.distanceTo(btmRight) / 2;
}

void NgoiSao::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	float alpha = al;
	//ve diem dau: dinh1
	glVertex2f(this->end.getX(), this->end.getY());
	alpha = al/2;
	Point temp;
	//	Quay goc al/2;
	temp.setCoor((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	MyVect ttVect(temp, center);
	// tinh tien 1/2 Temp-Center
	temp.setCoor(temp.getX() + ttVect.getX() / 2, temp.getY() + ttVect.getY() / 2);
	//Ve Temp1:
	glVertex2f(temp.getX(), temp.getY());

	//Tra alpha ve = al

	alpha = al;
	// Ve dinh2 lon: quay end alpha do.
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	//Quay temp : alpha tim temp2:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	glVertex2f(temp.getX(), temp.getY());


	//Ve dinh3 lon: Quay end 2alpha
	alpha = 2*al;

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	//Quay temp: alpha tim temp3:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f(temp.getX(), temp.getY());


	//Ve dinh4 lon: Quay end 3alpha
	alpha = 3 * al;

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	//Quay temp: alpha tim temp4:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f(temp.getX(), temp.getY());


	//Ve dinh5 lon: Quay end 4alpha
	alpha = 4 * al;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	//Quay temp: alpha tim temp5:
	alpha = al;
	temp.setCoor((temp.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((temp.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((temp.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (temp.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f(temp.getX(), temp.getY());
	glEnd();

	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string NgoiSao::getType()
{
	return "Ngoi Sao";
}

Point NgoiSao::getCenter()
{
	return this->center;
}

void NgoiSao::fillColor(int x, int y, int colr_id)
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

MuiTen::MuiTen(Point c, Point btmRight)
{
	this->center = c.midMointTo(btmRight);
	this->start = c;
	this->end = btmRight;
	fullEdge = c.distanceTo(btmRight);
	tri = fullEdge / 5;
	rect = fullEdge - tri;
	this->center = c.midMointTo(btmRight);
	Point cr;
	MyVect ar(c, btmRight);
	ar_Vect = ar;

	MyVect tempCr(btmRight, c);
	tempCr = tempCr.multiBy(0.2);
	cr.setCoor(tempCr.getX() + btmRight.getX(), tempCr.getY() + btmRight.getY());
	this->cross = cr;
}

void MuiTen::draw()
{
	setLibColor();
	MyVect nor = ar_Vect.getNormal();
	nor = nor.multiBy(0.2);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(this->start.getX(), this->start.getY());
	glVertex2f(this->end.getX(), this->end.getY());

	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f(this->cross.getX() +nor.getX(), this->cross.getY()+nor.getY());

	glVertex2f(this->end.getX(), this->end.getY());
	nor = nor.multiBy(-1);
	glVertex2f(this->cross.getX() + nor.getX(), this->cross.getY() + nor.getY());

	glEnd();

}

string MuiTen::getType()
{
	return "Mui Ten";
}

Point MuiTen::getCenter()
{
	return this->center;
}

void MuiTen::fillColor(int x, int y, int colr_id)
{

}
