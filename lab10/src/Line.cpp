/*
 * Line.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: williamhooper
 */

#include "Line.h"
#include "Point.h"
#include <cmath>
#include <string>
#include <stdexcept>
#include <iostream>

/**
 * Default Line constructor
 */
Line::Line()	// Default constructor, sets initial array size to 10 and assigns pointer to it
{
	arraySize = 10;
	elementSize = 0;
	pointArray = new Point[arraySize];
}

void Line::addBack(Point a)	// Adds a point to the back of the array
{
	if(elementSize == arraySize)	// If array is too small copy all data to a new array, reassign pointer
	{
		Point* tempArray = new Point[arraySize + 10];	// New temp array in free store
		for(int i = 0; i < arraySize; i++)
		{
			tempArray[i] = pointArray[i];
		}
		delete[] pointArray;
		pointArray = tempArray;
		pointArray[elementSize++] = a;
		arraySize = (10 + arraySize);
	}
	else
	{
		pointArray[elementSize++] = a;
	}
}

unsigned int Line::size() const	// Returns how many elements in the array (not total size)
{
	return elementSize;
}

int Line::length() const	// Performs distance calculations on each set of points, and sums them
							// (i/e index 2 and 1, then 3 and 2, then 4 and 3...)
{
	int d;
	for(int i = 0; i < (elementSize - 1); i++)
	{
		int xf, xi, yf, yi;
		xf = pointArray[i + 1].getX();
		yf = pointArray[i + 1].getY();
		xi = pointArray[i].getX();
		yi = pointArray[i].getY();
		d += sqrt(((xf - xi)*(xf - xi)) + ((yf - yi)*(yf - yi)));
	}
	return d;
}

void Line::clear()	// Deletes the pointer, reassigns it to a new array
{
	delete[] pointArray;
	arraySize = 10;
	elementSize = 0;
	pointArray = new Point[arraySize];
}

Point& Line::operator [](int index)	// Overloaded [], returns the point at user selected index, throws if oor
{
	if(arraySize < index)
	{
		error("Out of Bounds!!");
	}

	return pointArray[index];
}

void Line::error(std::string s)	// Error method
{
	std::cerr << s;
	throw std::out_of_range(s);
}
/**
 * Line deconstructor
 */
Line::~Line()
{
	delete[] pointArray;
}

