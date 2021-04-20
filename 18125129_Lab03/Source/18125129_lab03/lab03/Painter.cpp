#include "Painter.h"

Painter* Painter::instance = NULL;

Painter::~Painter()
{
	if (instance)
	{
		instance = NULL;
		listOfShape.clear();
	}
}

Painter::Painter()
{
	cout << "Create 1" << endl;
}

vector<Shape*> Painter::getList()
{
	return listOfShape;
}

Painter* Painter::getInstance() {
	if (instance == NULL) {
		instance = new Painter();
	}
	return instance;
}

void Painter::addShape(Shape* a)
{
	listOfShape.push_back(a);
}

void Painter::showList()
{
	cout << &listOfShape << endl;
}

void Painter::fillColor(int x, int y, int color_id)
{
	if (listOfShape.size() == 0)
		return;
	Point pickedPoint(x, y);
	Shape* pickedShape = listOfShape[0];
	float minDis = pickedPoint.distanceTo(listOfShape[0]->getCenter());
	for (int i = 1; i < listOfShape.size(); i++) {
		if(pickedPoint.distanceTo(listOfShape[i]->getCenter())<minDis){
			minDis = pickedPoint.distanceTo(listOfShape[i]->getCenter());
			pickedShape = listOfShape[i];
		}
	}
	//if (pickedShape->getType() == "Line" || pickedShape->getType()=="Mui Ten") {

	//	return;
	//}
	//if (color_id == mauDo_id) {
	//	BoundaryFill(x,y, mauDo, mauVien);
	//}
	//else if (color_id == mauVang_id) {
	//	BoundaryFill(x,y, mauVang, mauVien);
	//}
	//else if (color_id == mauXanh_id) {
	//	BoundaryFill(x,y, mauXanh, mauVien);
	//}
	//cout << "int painter filco" << endl;
	pickedShape->fill = color_id;
}

