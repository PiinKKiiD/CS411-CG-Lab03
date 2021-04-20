#include "Shape.h"
#include "Painter.h"
Shape::Shape()
{
	fill = 0;
}

void Shape::setLibColor()
{
	
		glLineWidth(3);
		if (fill == 0)
			glColor3f(mauVien.r, mauVien.g, mauVien.b);
		else if (fill == mauXanh_id)
			glColor3f(mauXanh.r, mauXanh.g, mauXanh.b);
		else if (fill == mauDo_id)
			glColor3f(mauDo.r, mauDo.g, mauDo.b);
		else if (fill == mauVang_id)
			glColor3f(mauVang.r, mauVang.g, mauVang.b);

		//glColor3f(0.8f, 0.5f, 0.6f);
	
}
