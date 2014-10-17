#ifndef __NEXTDATE_H__
#define __NEXTDATE_H__

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define ERR_INVALID_DATE 0

#define YEAR_MIN 1970
#define YEAR_MAX 2014

#define MONTH_MIN 1
#define MONTH_MAX 12

#define DAY_MIN 1
extern const int DAY_MAX[MONTH_MAX + 1];

/*
 * return a non-zero 8 digit integer as the next date in the format YYYYMMDD from 19700102 to 20150101, ERR_INVALID_DATE(0) if error occurs
 * Thereby, the input range should be from 19700101 to 20141231
 *
 * NOTE!! We do not consider the condition that Feb. has 29 days 
 * 
 * example of usage:
 *  @input  = nextdate( 2001, 1, 1 )
 *  @output = (int)20010102
 */
int nextdate( int year, int month, int day );

#endif
