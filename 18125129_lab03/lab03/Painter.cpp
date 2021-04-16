#include "Painter.h"

Painter* Painter::instance = NULL;

Painter::~Painter()
{
	if (instance)
	{
		instance = NULL;
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
