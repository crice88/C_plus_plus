//============================================================================
// Name        : Point.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Point.h"
#include "Line.h"

using namespace std;

/**
 * Point constructor requires a X and Y coordinate
 *
 * @param x
 * @param y
 */
Point::Point(int x, int y) : x(x), y(y)
{

}

/**
 * Point copy constructor
 *
 * @param t
 */
Point::Point(const Point & p)
{
	x = p.x;
	y = p.y;
}

/**
 * Point copy assignment operator
 *
 * @param rhs
 * @return
 */
Point& Point::operator =(const Point& rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}
