/*
 * Line.h
 *
 *  Created on: Nov 1, 2014
 *      Author: williamhooper
 */

#ifndef LINE_H_
#define LINE_H_

#include <stdexcept>
#include <string>
#include "Point.h"

/**
 * The line class contains a list of points. The line class is a container class.
 */
class Line {
public:
	Line();
	virtual ~Line();

	/**
	 * add a Point to the end of our line
	 */
	void addBack(Point p);

	/**
	 * return the number of Points in our line
	 */
	unsigned int size() const;

	/**
	 * clear the Points from our line
	 */
	void clear();

	/**
	 * length of our line
	 */
	int length() const;

	/**
	 * [] operator override
	 */
	Point& operator[](int index);

	void error(std::string s);
private:
	Point* pointArray;
	int arraySize;
	int elementSize;
};

#endif /* LINE_H_ */
