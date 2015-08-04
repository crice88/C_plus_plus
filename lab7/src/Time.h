/*
 * Time.h
 *
 *  Created on: Jan 1, 2014
 *      Author: williamhooper
 */

#ifndef TIMELAB_SRC_TIME_H_
#define TIMELAB_SRC_TIME_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * Time class
 *
 * The Time class contains time as hours:minutes:seconds:milliseconds (AM/PM).
 */
class Time
{
public:
	/**
	 * Constructor with zero values
	 */
    Time();

    Time(long time);
    Time(int hours, int minutes, int seconds, int milli);
    virtual ~Time();

    /**
     * Return time as a long
     */
    long asLong() const;

    /**
     * Display as a string in the format hours:minutes:seconds:milliseconds.
     * For example 1:45:30:56 PM
     *
     * The time is displayed as 24 hours if the 24 hour flag is set true.
     */
    std::string toString() const;

    /**
     * Enable/disable 24 hour time display
     */
    void set24Hour(bool value);

    /**
     * Return true if 24 hour time display is enabled
     */
    bool is24Hour() const;

    /**
     * Output the time to an output stream as hours:minutes:seconds:milliseconds.microseconds
     */
    friend std::ostream& operator <<(std::ostream&, const Time&);


    /**
     * Define ordering relationships
     */
    friend bool operator <(const Time&, const Time&);

    friend bool operator ==(const Time &a, const Time &b);

    /**
     * Define addition and subtraction
     */
    Time operator +(const Time&) const;

    Time operator -(const Time&) const;

    /**
     * Copy constructor
     */
    Time(const Time & t);

    /**
     * Copy assignment
     */
	Time& operator =( const Time& rhs );

	/**
	* Getters
	*/
	int getHours() const;
	int getSeconds() const;
	int getMinutes() const;
	int getMilliseconds() const;

	/**
	* Setters
	*/
	void setHours(long x);
	void setMinutes(long x);
	void setSeconds(long x);
	void setMilliseconds(long x);


private:
    /**
     * Private members go here
     */
    long hours;
    long minutes;
    long seconds;
    long milliseconds;
    bool PMflag = false;

    void individualValues(long time);
    void error(string s);
};

#endif /* TIMELAB_SRC_TIME_H_ */
