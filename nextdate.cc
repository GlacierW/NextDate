#include <stdio.h>
#include "nextdate.h"

const int DAY_MAX[MONTH_MAX + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int nextdate( int year, int month, int day ) {
	return ERR_INVALID_DATE;
}
