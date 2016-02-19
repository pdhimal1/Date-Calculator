/*
 * Prakash Dhimal
 * date.c 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "date.h"

#define SIZE_OF_DATE 11

//number of days in the month
int numDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct tm getDate()
{
	time_t t = time(NULL);
	//struct tm tmp;
	
	struct tm today = *localtime(&t);
	today.tm_mon = today.tm_mon+1;
	today.tm_year = today.tm_year+1900;

	return today;
}
int isLeapyear(int year)
{
	if (year%4 == 0 && (year%100 != 0 || year%400 == 0))
	{
		return 1;
	}
	else 
		return 0;
}

struct tm getDaybefore(struct tm today)
{
	int year = today.tm_year;
	int month = today.tm_mon;
	int DATE = today.tm_mday;
	
	//variables to store a new Date
	struct tm dateBefore;
	int newMonth;
	int newDate;
	int newYear;
	
	if (DATE == 1)
	{
		if(month == 1)
		{	
			newMonth = 12;
			newDate = numDays[newMonth];
			newYear = year-1;
		}

		else if(month == 3)
		{
			newMonth = month-1;
			newYear = year;
			if(isLeapyear(newYear))
			{
				numDays[2] = 29;
			}
			newDate = numDays[newMonth];
		}
		else
		{
			newMonth = month-1;
			newDate = numDays[newMonth];
			newYear = year;
		}	
	}

	else 
	{
		newDate = DATE-1;
		newMonth = month;
		newYear = year;
	}
	
	dateBefore.tm_mon = newMonth;
	dateBefore.tm_mday = newDate;
	dateBefore.tm_year = newYear;

	return dateBefore;	
}

struct tm getDayafter(struct tm today)
{
	int year = today.tm_year;
	int month = today.tm_mon;
	int DATE = today.tm_mday;
	
	//variables to store a new Date
	struct tm dateAfter;
	int newMonth;
	int newDate;
	int newYear;
	
	if(isLeapyear(year))
	{
		numDays[2] = 29;
	}

	//if last day of the month
	if (DATE == numDays[month])
	{
		//if dec 31st
		if(month == 12)
		{	
			newMonth = 1;
			newDate = numDays[newMonth];
			newYear = year+1;
		}
		//all other - leap year accounted in the numDays array
		else
		{
			newMonth = month+1;
			newDate = 1;
			newYear = year;
		}	
	}

	else 
	{
		newDate = DATE+1;
		newMonth = month;
		newYear = year;
	}
	
	dateAfter.tm_mon = newMonth;
	dateAfter.tm_mday = newDate;
	dateAfter.tm_year = newYear;

	return dateAfter;	
}

int differenceBetweenDates(struct tm date1, struct tm date2)
{
	int years;
	if (date1.tm_mon > date2.tm_mon)
		years = date1.tm_year - date2.tm_year;
	else if (date1.tm_mon == date2.tm_mon)
	{
		if (date1.tm_mday >= date2.tm_mday)
			years = date1.tm_year - date2.tm_year;
		else 
			years = date1.tm_year - date2.tm_year -1;
	}
	else 
		years = date1.tm_year - date2.tm_year -1;
	return years;
}

