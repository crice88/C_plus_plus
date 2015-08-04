/*
 * Point.h
 *
 *  Created on: Oct 25, 2014
 *      Author: williamhooper
 */

#ifndef POINT_H_
#define POINT_H_


class Point {
public:
    Point(int x = 0, int y = 0);
    Point(const Point & t);
    virtual ~Point() {};

    int getX() const {return x;};	// get X value
    int getY() const {return y;};	// get Y value

    Point& operator =( const Point& rhs );

private:
    int x, y;
};


#endif /* POINT_H_ */
