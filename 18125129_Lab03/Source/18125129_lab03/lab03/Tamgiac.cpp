#include "Tamgiac.h"
#include "MyVect.h"
#include "Painter.h"
Point TGVuongCan::getOther(Point a, Point b)
{
	MyVect abVect(a, b);
	float x_ab = abVect.getX();
	float y_ab = abVect.getY();
	float y_c = sqrt((x_ab * x_ab / (1 + y_ab / x_ab) * (1 + y_ab / x_ab))) + a.getY();
	float x_c = (-y_ab*(y_c -a.getY())) / x_ab + a.getX();
	Point c(x_c, y_c);
	return c;
}

TGVuongCan::TGVuongCan(Point a, Point b)
{
	this->start = a;
	this->end = b;
	this->edge = a.distanceTo(b);
	this->other = getOther(a, b);
	Point cenTemp = a.midMointTo(other);
	this->center = b.midMointTo(cenTemp);
}

void TGVuongCan::draw()
{
	setLibColor();
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(this->start.getX(), this->start.getY());
	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f(this->other.getX(), this->other.getY());
	glVertex2f(this->other.getX(), this->other.getY());
	glVertex2f(this->start.getX(), this->start.getY());
	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string TGVuongCan::getType()
{
	return "Tam giac vuong can";
}

Point TGVuongCan::getCenter()
{
	return this->center;
}

TamGiac::TamGiac()
{
}

void TamGiac::fillColor(int x, int y, int colr_id)
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

TGDeu::TGDeu(Point a, Point b)
{
	this->edge = a.distanceTo(b);
	this->center = a;
	this->start = b;
	this->end.setCoor((b.getX()-center.getX())*cos(120*3.1415/180)- ((b.getY() - center.getY())*sin(120*3.1415/180))+center.getX(),((b.getX()-center.getX())*sin(120*3.1415/180))+(b.getY()-center.getY())*cos(120*3.1415/180)+center.getY());
	this->other.setCoor((end.getX() - center.getX()) * cos(120 * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(120 * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(120 * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(120 * 3.1415 / 180) + center.getY());

	/*for (int i = 0; i < 360; i++) {
		if(i == 120){
			float theta = i * 3.1415 / 180;
			this->end.setCoor(center.getX() + edge * cos(theta), center.getY() + edge * sin(theta));
			cout << 1 << endl;
		}
		if (i == 240) {
			float theta = i * 3.1415 / 180;
			this->other.setCoor(center.getX() + edge * cos(theta), center.getY() + edge * sin(theta));
			cout << 2 << endl;
		}
		if (i == 0) {
			float theta = i * 3.1415 / 180;
			this->start.setCoor(center.getX() + edge * cos(theta), center.getY() + edge * sin(theta));
			cout << 3 << endl;
		}
	}*/
	//Sua lai
}

void TGDeu::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(this->start.getX(), this->start.getY());
	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f(this->other.getX(), this->other.getY());
	glVertex2f(this->other.getX(), this->other.getY());
	glVertex2f(this->start.getX(), this->start.getY());
	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);

}

string TGDeu::getType()
{
	return "Tam Giac Deu";
}

Point TGDeu::getCenter()
{
	return this->center;
}
