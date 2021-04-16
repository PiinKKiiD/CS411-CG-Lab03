#pragma once
#ifndef POINT_H_
#define POINT_H_


class Point {
private:
	float x;
	float y;
public:
	Point(float xx, float yy);
	Point();
	float distanceTo(Point B);
	void setCoor(float xx, float yy);
	void setEqual(Point B);
	float getX();
	float getY();
	void operator=(Point b);
};

#endif // !POINT_H_
