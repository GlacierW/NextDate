#include <stdio.h>
#include "nextdate.h"

const int DAY_MAX[MONTH_MAX + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int nextdate( int year, int month, int day ) {
	
	int n_year  = year,
		n_month = month,
		n_day   = day;
	
	// validate year, month, and day
	if( 
		year  < YEAR_MIN
	||	month < MONTH_MIN
	||	day   < DAY_MIN
	||	year  > YEAR_MAX
	||	month > MONTH_MAX
	||	day   > DAY_MAX[month]
	) {
		return ERR_INVALID_DATE;
	}
	
	return 0xdeadbeef;
}
