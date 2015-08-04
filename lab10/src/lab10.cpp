//============================================================================
// Name        : lab10.cpp
// Author      : Colin Rice
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 10 Containers
//============================================================================

#include <iostream>
#include <sstream>
#include "Line.h"
#include "Point.h"

using namespace std;

int main()
{
	// Testing
	Line l;
	Point p(1, 3);
	Point p1(4, 5);
	Point p2(19, 3);
	Point p3(17, 3);
	Point p4(1, 81);
	Point p5(15, 15);
	Point p6(11, 11);
	Point p7(1, 22);
	Point p8(14, 85);
	Point p9(56, 46);
	Point p10(24, 32);
	Point p11(18, 39);
	Point p12(16, 4);
	Point p13(12,13);
	Point p14(6,4);

	l.addBack(p);	// Testing size and length
	l.addBack(p1);
	cout << l.size() << endl;	// 2
	cout << l.length() << endl;	// 3

	l.addBack(p2);	// Testing "if" condition, extending original array
	l.addBack(p3);
	l.addBack(p4);
	l.addBack(p5);
	l.addBack(p6);
	l.addBack(p7);
	l.addBack(p8);
	l.addBack(p9);
	l.addBack(p10);
	l.addBack(p11);

	cout << l.size() << endl;	// 12
	cout << l.length() << endl;	// 349

	l.clear();	// Testing clear method
	l.addBack(p12);
	l.addBack(p13);
	l.addBack(p14);
	cout << l.size() << endl;	// 3
	cout << l.length() << endl;	// Testing length on odd number of points
								// 19

	l[11];	// Testing out of bounds exception

	return 0;
}
