#ifndef __NEXTDATE_H__
#define __NEXTDATE_H__

#define ERR_INVALID_DATE 0

#define MIN_YEAR 1970
#define MAX_YEAR 2014

#define MIN_MONTH 1
#define MAX_MONTH 12

#define MIN_DAY 1
extern const int MAX_DAY[MAX_MONTH + 1];

/*
 * return non-zero value as the next date, 0 on error
 * The output is a 8 digit integer in the format YYYYMMDD from 19700101 to 20141231
 *
 * example of usage:
 *  @input  = nextdate( 2001, 1, 1 )
 *  @output = (int)20010102
 */
int nextdate( int year, int month, int day );

#endif
