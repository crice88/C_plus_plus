/*
 * Time.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: Colin Rice
 *      Class: CSCI 66
 *      Lab 7
 */

#include "Time.h"
#include <stdexcept>
#include <sstream>
#include <cmath>

int Time::getHours() const	// Getter for hours
{
	return hours;
}

int Time::getMinutes() const	// Getter for minutes
{
	return minutes;
}

int Time::getSeconds() const	// Getter for seconds
{
	return seconds;
}

int Time::getMilliseconds() const	// Getter for milliseconds
{
	return milliseconds;
}

void Time::setHours(long x)	// Setter for hours
{
	if( x > 23 || x < 0) error("Bad Input!");
	this->hours = x;
}

void Time::setMinutes(long x)	// Setter for minutes
{
	if( x > 59 || x < 0 ) error("Bad Input!");
	this->minutes = x;
}

void Time::setSeconds(long x)	// Setter for seconds
{
	if(x > 59 || x < 0) error("Bad Input!");
	this->seconds = x;
}

void Time::setMilliseconds(long x)	// Setter for milliseconds
{
	if(x > 999 || x < 0) error("Bad Input!");
	this->milliseconds = x;
}

Time::Time(int h, int m, int s, int ms) // Takes input as int, stores individual vales as int
{
	if( h > 23 || h < 0) error("Bad Input!");	// Checking boundaries
	if( m > 59 || m < 0 ) error("Bad Input!");
	if(s > 59 || s < 0) error("Bad Input!");
	if(ms > 999 || ms < 0) error("Bad Input!");
	if(h > 12)
		PMflag = true;

	hours = h;
	minutes = m;
	seconds = s;
	milliseconds = ms;
}

Time::Time(long time)	// Accepts time as long and sets variables accordingly
{
	individualValues(time);
}

Time::Time() // Sets default time to all zeros
{
	hours = 0;
	minutes = 00;
	seconds = 00;
	milliseconds = 00;
	PMflag = false;
}

Time::Time( const Time & t)	// Copies all values of time t to local object
{
	hours = t.hours;
	minutes = t.minutes;
	seconds = t.seconds;
	milliseconds = t.milliseconds;
	set24Hour( is24Hour() );
}

Time& Time::operator =( const Time& rhs )	// Assigns a time object the values of another time object
{
	if(this == & rhs)	// If values are equal, return this
		return *this;
	this->hours = rhs.hours;
	this->minutes = rhs.minutes;
	this->seconds = rhs.seconds;
	this->milliseconds = rhs.milliseconds;
	this->set24Hour(rhs.is24Hour());
	return *this;
}

void Time::individualValues(long time)	// Code segment credit to Bill Hooper
{
	if (time > 99999999 || time < 0) error("Bad Input!");	// More boundary checking

	milliseconds = time % 1000;
	if(milliseconds > 999 || milliseconds < 0) error("Bad Input!");
	time /= 1000;

	seconds = time % 60;
	if(seconds > 59 || seconds < 0) error("Bad Input!");
	time /= 60;

	minutes = time % 60;
	if( minutes > 59 || minutes < 0 ) error("Bad Input!");
	time /= 60;

	hours = time;
	if( hours > 24 || hours < 0 ) error("Bad Input!");
	if ( hours > 12)
		PMflag = true;
}

long Time::asLong() const	// Code segment credit to Bill Hooper
{
	long longValue;

	longValue = (long) hours;
	longValue = (longValue * 60) + minutes;
	longValue = (longValue * 60) + seconds;
	longValue = (longValue * 1000) + milliseconds;
	return longValue;
}

string Time::toString() const	// Creates a string with h, m, s, and ms, displays to console
{
	ostringstream s1;
	string timeOfDay;

	if(is24Hour() == true || PMflag == true)
		timeOfDay = "PM";
	else
		timeOfDay = "AM";
	s1 << hours << ":" << minutes << ":" << seconds << ":" << milliseconds << " " << timeOfDay << endl;
	return s1.str();
}

void Time::set24Hour(bool value)	// If false, time is in standard 12-hour format, PMflag set
{
	if( value == false )
	{
		if(hours > 12)
		{
			hours -= 12;
			PMflag = true;
		}
	}
	if( value == true )
	{
		if( hours < 12 && PMflag == true)
			hours += 12;
	}

}

bool Time::is24Hour() const	// Checks to see if time is in 24-hour format, or standard 12-hour
{
	if( hours > 12)
		return true;
	else
		return false;
}



void Time::error(const string s)	// Throws an error, and does not modify values
{
	//cerr << s;
	throw out_of_range(s);
}


Time::~Time() {
	// TODO Auto-generated destructor stub
}


std::ostream& operator <<(std::ostream&a, const Time&b)
{
	string timeOfDay;	// Takes a time, and puts it into an acceptable ostream object

	if(b.is24Hour() == true || b.PMflag == true)
		timeOfDay = "PM";
	else
		timeOfDay = "AM";
	a << b.hours << ":" << b.minutes << ":" << b.seconds << ":" << b.milliseconds << " " << timeOfDay << endl;
	return a;
}

/**
 * Define ordering relationships
 */
bool operator <(const Time&a, const Time&b)
{
	long t1 = a.asLong();	// Convert each time to a long value
	long t2 = b.asLong();

	if( t1 < t2 )	// Compare the values
		return true;
	else
		return false;
}

bool operator ==(const Time &a, const Time &b)
{
	long t1 = a.asLong();	// Convert each time to a long value
	long t2 = b.asLong();

	if( t1 == t2 )	// Check to see if the values are equal
		return true;
	else
		return false;
}

/**
 * Define addition and subtraction
 */

Time Time::operator +(const Time&a) const
{
	Time t1;

	t1.hours = this->hours + a.hours;	// Add the hours, minutes, seconds, and/or milliseconds together
	t1.minutes = this->minutes + a.minutes;
	t1.seconds = this->seconds + a.seconds;
	t1.milliseconds = this->milliseconds + a.milliseconds;

	while( t1.milliseconds > 999)	// Wrap around if greater than 24 hours
	{
		t1.milliseconds -= 1000;
		t1.seconds += 1;
	}
	while( t1.seconds > 59)	// Wrap around if greater than 24 hours
	{
		t1.seconds -= 60;
		t1.minutes += 1;
	}
	while( t1.minutes > 59)	// Wrap around if greater than 24 hours
	{
		t1.minutes -= 60;
		t1.hours += 1;
	}
	while( t1.hours > 23)	// Wrap around if greater than 23 hours
	{
		t1.hours -= 23;	// 23 to account for non-existent hour zero
	}
	return t1;
}

Time Time::operator -(const Time&a) const
{
	Time t1;

	t1.hours = this->hours - a.hours;	// Subtract the hours, minutes, seconds, or milliseconds
	t1.minutes = this->minutes - a.minutes;
	t1.seconds = this->seconds - a.seconds;
	t1.milliseconds = this->milliseconds - a.milliseconds;
	while(t1.hours < 0 || t1.minutes < 0 || t1.seconds < 0 || t1.milliseconds < 0)	// While values are not positive, continue looping
	{
		while( t1.hours < 0)	// While value is negative, add 60 (or 23), and subtract from succeeding digit
		{
			t1.hours += 23;	// 23 to account for non-existent, hour zero
		}
		while(t1.minutes < 0)
		{
			t1.minutes += 60;
			t1.hours -= 1;
		}
		while(t1.seconds < 0)
		{
			t1.seconds += 60;
			t1.minutes -= 1;
		}
		while( t1.milliseconds < 0)
		{
			t1.milliseconds += 1000;
			t1.seconds -= 1;
		}
	}
	//t1.individualValues(t1.asLong());
	return t1;
}
