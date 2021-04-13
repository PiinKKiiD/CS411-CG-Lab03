#include "glut.h"
#include "Shape.h"
#include <iostream>
#include <vector>

using namespace std;
class Painter {
private:
	Painter();
	static Painter s_instance;

	vector<Shape*> listOfShape;


public:
	static Painter& getInstance() {
		return s_instance;
	}
	Painter(const Painter&) = delete;

	//Functions

};
Painter Painter::s_instance;