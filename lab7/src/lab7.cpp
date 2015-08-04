//============================================================================
// Name        : lab7.cpp
// Author      : Colin Rice
// Version     :
// Description : Lab 7, Getters, setters, and exceptions
//============================================================================

#include <iostream>
#include <sstream>
#include "Time.h"
#include <stdexcept>

using namespace std;
int main()
{
	try	// Testing out of range exceptions with constructors
	{
		Time t30(-1,0,0,0);	// Under 0
	}
	catch(out_of_range& e)
	{
		cout << "Testing range for hours: " << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 24
	{
		Time t31(25,0,0,0);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Under 0
	{
		Time t32(0,-1,0,0);
	}
	catch(out_of_range& e)
	{
		cout << "Testing range for minutes: " << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 60
	{
		Time t33(0,61,0,0);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Under 0
	{
		Time t34(0,0,-1,0);
	}
	catch(out_of_range& e)
	{
		cout << "Testing range for seconds: " << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 60
	{
		Time t35(0,0,61,0);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Under 0
	{
		Time t36(0,0,0,-1);
	}
	catch(out_of_range& e)
	{
		cout << "Testing range for milliseconds: " << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 1000
	{
		Time t37(0,0,0,1001);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Testing out of range for all setters
	{
		Time t38(1,0,0,0);	// Under 0
		t38.setHours(-3);
	}
	catch(out_of_range& e)
	{
		cout << "Testing bounds for setHours" << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 60
	{
		Time t39(1,0,0,0);
		t39.setHours(60);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Under 0
	{
		Time t39(0,0,0,0);
		t39.setMinutes(-3);
	}
	catch(out_of_range& e)
	{
		cout << "Testing bounds for setMinutes" << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 60
	{
		Time t38(1,0,0,0);
		t38.setMinutes(64);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Under 0
	{
		Time t38(1,0,0,0);
		t38.setSeconds(-3);
	}
	catch(out_of_range& e)
	{
		cout << "Testing bounds for setSeconds" << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 60
	{
		Time t38(1,0,0,0);
		t38.setSeconds(100);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Under 0
	{
		Time t38(1,0,0,0);
		t38.setMilliseconds(-3);
	}
	catch(out_of_range& e)
	{
		cout << "Testing bounds for setMilliseconds" << endl;
		cerr << "Sorry, " << e.what() << endl;
	}

	try	// Over 60
	{
		Time t38(1,0,0,0);
		t38.setMilliseconds(6000);
	}
	catch(out_of_range& e)
	{
		cerr << "Sorry, " << e.what() << endl;
	}

	cout << "***Now testing the Getters***" << endl;	// Testing the Getters
	cout << "***Testing Getters***" << endl;
	Time t28(2,4,5,600);
	ostringstream s2;
	cout << "Starting Value: " << t28 << endl;
	s2 << t28.getHours() << t28.getMinutes() << t28.getSeconds() << t28.getMilliseconds() << endl;
	cout << "Ending Values: " << s2.str() << endl;

	cout << "***Now testing the Setters***" << endl;	// Testing the Setters
	cout << "***Testing Setters***" << endl;
	Time t29(1,0,0,0);
	ostringstream s3;
	cout << "Starting Value: " << t29 << endl;
	t29.setHours(3);
	t29.setMinutes(14);
	t29.setSeconds(25);
	t29.setMilliseconds(523);
	s3 << t29.getHours() << t29.getMinutes() << t29.getSeconds() << t29.getMilliseconds() << endl;
	cout << "Ending Values: " << s3.str() << endl;

	cout << "***Now testing the Copy constructor***" << endl;	// Testing the copy constructor
	cout << "***Testing constructor***" << endl;
	Time t22(1000);
	cout << "Starting Value: " << t22 << endl;
	Time t23(t22);
	cout << "Ending Values: " << t23 << "and " << t22 << endl;

	cout << "***Now testing the Copy assignment***" << endl;	// Testing the copy assignment operator
	cout << "***Testing assignment***" << endl;
	Time t24(1500);
	cout << "Starting Value: " << t24 << endl;
	Time t25 = t24;
	cout << "Ending Values: " << t25 << "and " << t24 << endl;

	cout << "***Now testing the Copy assignment using a different assignment method***" << endl;	// Testing the copy assignment operator
	cout << "***Testing assignment***" << endl;
	Time t26(6, 10, 10, 10);
	cout << "Starting Value: " << t26 << endl;
	Time t27;
	t27 = t26;
	cout << "Ending Values: " << t27 << "and " << t26 << endl;

	cout << "***Now testing the overloaded operators***" << endl;
	cout << "***Testing addition***" << endl;	// Testing the addition properties
	Time t1(1);
	Time t2(2);
	cout << "Starting value: " << t1 << endl;
	cout << "Starting value: " << t2 << endl;
	Time t3 = t1 + t2;
	cout << "Ending Value: " << t3.toString() << "\n" << endl;

	cout << "***Testing subtraction***" << endl;	// Testing the subtraction properties
	Time t4(16);
	Time t5(19);
	cout << "Starting value: " << t5 << endl;
	cout << "Starting value: " << t4 << endl;
	Time t6 = t5 - t4;
	cout << "Ending Value: " << t3.toString() << "\n" << endl;

	cout << "***Testing ostream***" << endl;	// Testing the << operator
	ostringstream s1;
	Time t7(15, 0, 16, 32);
	cout << "Starting value: " << t7 << endl;
	s1 << t7;
	cout << "Ending Value: " << s1.str();

	cout << "***Testing < (true)***" << endl;	// Testing the < operator, true
	Time t8(10000);
	Time t9( 4, 35, 45, 465);
	cout << "Starting value: " << t8 << endl;
	cout << "Starting value: " << t9 << endl;
	cout << "Ending Value: " << ( t8 < t9 ) << "\n" << endl;

	cout << "***Testing < (false)***" << endl;	// Testing the < operator, false
	cout << "Starting value: " << t9 << endl;
	cout << "Starting value: " << t8 << endl;
	cout << "Ending Value: " << ( t9 < t8 ) << "\n" <<endl;

	cout << "***Testing == (true)***" << endl;	// Testing the == operator, true
	Time t10(15000);
	Time t11(15000);
	cout << "Starting value: " << t10 << endl;
	cout << "Starting value: " << t11 << endl;
	cout << "Ending Value: " << ( t10 == t11) << "\n" << endl;

	cout << "***Testing == (false)***" << endl;	// Testing the == operator, false
	cout << "Starting value: " << t9 << endl;
	cout << "Starting value: " << t10 << endl;
	cout << "Ending Value: " << (t9 == t10) << "\n" << endl;

	cout << "***Testing wrap-around with addition***" << endl;	// Wrap-around addition
	Time t12(13, 40, 59, 900 );
	Time t13(10, 22, 14, 504);
	cout << "Starting value: " << t12 << endl;
	cout << "Starting value: " << t13 << endl;
	Time t14 = t12 + t13;
	cout << "Ending Value: " << t14 << endl;

	cout << "***Testing wrap-around with subtraction***" << endl;	// Wrap-around subtraction
	Time t15(3, 10, 10,20);
	Time t16(13, 20, 12, 30);
	cout << "Starting value: " << t15 << endl;
	cout << "Starting value: " << t16 << endl;
	Time t17 = t15 - t16;
	cout << "Ending Value: " << t17 << endl;

	// Basic functions test
	Time t18(13, 45, 52, 125);

	cout << "***Now testing the basic functionality***" << endl;
	cout << "Time as long: " << t18.asLong() << endl;	// Check asLong
	t18.set24Hour(false);
	cout << "Time 24 hour flag: "  <<  t18.is24Hour() << endl;
	cout << "Time as 12 hour: " << t18.toString() << endl;
	t18.set24Hour(true);
	cout << "Time 24 hour flag: "  <<  t18.is24Hour() << endl;
	cout << "Time as 24 hour: " << t18.toString() << "\n" << endl;

	Time t19(13, 45, 52, 125);
	Time t20;
	Time t21(14457600);

	cout << "Starting Value: " << t19 << endl;
	cout << "Time as long: " << t19.asLong() << endl;	// Check 24 hour flag and toString
	cout <<  "24 Hour Flag: " << t19.is24Hour()<< endl;
	t19.set24Hour(false);
	cout << "24 Hour Flag set to false: " << t19.toString() << "\n" << endl;

	cout << "Starting Value: " << t20 << endl;
	cout << "Time as long: " << t20.asLong() << endl;
	cout <<  "24 Hour Flag: " << t20.is24Hour()<< endl;
	t20.set24Hour(false);
	cout << "24 Hour Flag set to false: " << t20.toString() << "\n" << endl;

	cout << "Starting Value: " << t21 << endl;
	cout << "Time as long: " << t21.asLong() << endl;
	cout <<  "24 Hour Flag: " << t21.is24Hour()<< endl;
	t21.set24Hour(false);
	cout << "24 Hour Flag set to false: " << t21.toString() << "\n"<< endl;

	cout << "***Now testing the Copy constructor again***" << endl;	// Testing the copy constructor again, to make sure values are still present
	cout << "***Testing constructor***" << endl;
	cout << "Ending Values: " << t23 << "and " << t22 << endl;

	cout << "***Now testing the Copy assignment again***" << endl;	// Testing the copy assignment operator again, to make sure values are still present
	cout << "***Testing assignment***" << endl;
	cout << "Ending Values: " << t25 << "and " << t24 << endl;


	return 0;
}
