#include "Shape.h"

Shape::Shape()
{
}

void Shape::mouse()
{
    // Save the left button state
    if (button == GLUT_LEFT_BUTTON)
    {
        leftMouseButtonDown = (state == GLUT_DOWN);
    }

    else if (button == GLUT_RIGHT_BUTTON)
    {
        // \/ right MouseButton
        rightMouseButtonDown = (state == GLUT_DOWN);
    }

    // Save the mouse position
    this->x = x;
    this->y = y;
}
