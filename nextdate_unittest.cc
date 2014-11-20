#include <stdio.h>
#include <gtest/gtest.h>
#include "nextdate.h"

TEST( NextDateSpecTest, BoundaryDate ) {
	EXPECT_EQ( 19700102, nextdate( YEAR_MIN, MONTH_MIN, DAY_MIN ) );
	EXPECT_EQ( 20150101, nextdate( YEAR_MAX, MONTH_MAX, DAY_MAX[MONTH_MAX] ) );
}

TEST( NextDateSpecTest, WeakNormal_Month_31Days ) {
	
	// Months with 31 days: Jan. Mar. May. Jul. Aug. Oct. Dec.
	EXPECT_EQ( 20110116, nextdate(2011, JAN, 15) );
	EXPECT_EQ( 20120131, nextdate(2012, JAN, 30) );
	EXPECT_EQ( 20130201, nextdate(2013, JAN, 31) );
	
	EXPECT_EQ( 20110316, nextdate(2011, MAR, 15) );
	EXPECT_EQ( 20120331, nextdate(2012, MAR, 30) );
	EXPECT_EQ( 20130401, nextdate(2013, MAR, 31) );
	
	EXPECT_EQ( 20110516, nextdate(2011, MAY, 15) );
	EXPECT_EQ( 20120531, nextdate(2012, MAY, 30) );
	EXPECT_EQ( 20130601, nextdate(2013, MAY, 31) );
	
	EXPECT_EQ( 20110716, nextdate(2011, JUL, 15) );
	EXPECT_EQ( 20120731, nextdate(2012, JUL, 30) );
	EXPECT_EQ( 20130801, nextdate(2013, JUL, 31) );
	
	EXPECT_EQ( 20110816, nextdate(2011, AUG, 15) );
	EXPECT_EQ( 20120831, nextdate(2012, AUG, 30) );
	EXPECT_EQ( 20130901, nextdate(2013, AUG, 31) );
	
	EXPECT_EQ( 20111016, nextdate(2011, OCT, 15) );
	EXPECT_EQ( 20121031, nextdate(2012, OCT, 30) );
	EXPECT_EQ( 20131101, nextdate(2013, OCT, 31) );
	
	EXPECT_EQ( 20111216, nextdate(2011, DEC, 15) );
	EXPECT_EQ( 20121231, nextdate(2012, DEC, 30) );
	EXPECT_EQ( 20140101, nextdate(2013, DEC, 31) );
}

TEST( NextDateSpecTest, WeakNormal_Month_30Days ) {
	
	// Months with 30 days: Apr. Jun. Sep. Nov.
	EXPECT_EQ( 20110416, nextdate(2011, APR, 15) );
	EXPECT_EQ( 20120430, nextdate(2012, APR, 29) );
	EXPECT_EQ( 20130501, nextdate(2013, APR, 30) );	
	
	EXPECT_EQ( 20110616, nextdate(2011, JUN, 15) );
	EXPECT_EQ( 20120630, nextdate(2012, JUN, 29) );
	EXPECT_EQ( 20130701, nextdate(2013, JUN, 30) );
	
	EXPECT_EQ( 20110916, nextdate(2011, SEP, 15) );
	EXPECT_EQ( 20120930, nextdate(2012, SEP, 29) );
	EXPECT_EQ( 20131001, nextdate(2013, SEP, 30) );
	
	EXPECT_EQ( 20111116, nextdate(2011, NOV, 15) );
	EXPECT_EQ( 20121130, nextdate(2012, NOV, 29) );
	EXPECT_EQ( 20131201, nextdate(2013, NOV, 30) );
}

TEST( NextDateSpecTest, WeakNormal_Month_28Days ) {
	
	// Month with 28 days: Feb.	
	EXPECT_EQ( 20110216, nextdate(2011, FEB, 15) );
	EXPECT_EQ( 20120228, nextdate(2012, FEB, 27) );
	EXPECT_EQ( 20130301, nextdate(2013, FEB, 28) );
}

TEST( NextDateSpecTest, WeakRobust ) {
	
	// year min - 1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, 1, 1) );
	
	// month min - 1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MIN - 1, 1) );
	
	// day min - 1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, 1, DAY_MIN - 1) );
	
	/* ----------------------------------- */
	
	// year max + 1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, 1, 1) );
	
	// month max + 1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MAX + 1, 1) );
	
	// day max + 1 for months with 31/30/28 days
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, 4, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, 2, DAY_MAX[FEB] + 1) );
}

TEST( NextDateSpecTest, StrongRobust ) {
	
	// year min-1, month min-1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MIN - 1, 1) );
	
	// year min-1, day min-1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, 1, DAY_MIN - 1) );
	
	// month min-1, day min-1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MIN - 1, DAY_MIN - 1) );
	
	// year min-1, month min-1, day min-1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MIN - 1) );
	
	/* ----------------------------------- */
	
	// year max+1, month max+1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MAX + 1, 1) );
	
	// year max+1, day max+1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, 1, DAY_MAX[FEB] + 1) );
	
	// month max+1, day max+1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MAX + 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MAX + 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MAX + 1, DAY_MAX[FEB] + 1) );
	
	// year max+1, month max+1, day max+1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1) );

	/* ----------------------------------- */

	// one max+1, one min-1, one normal
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MAX + 1, DAY_MIN - 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MIN - 1, DAY_MAX[JAN] + 1) );
	
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, 1, DAY_MIN - 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, 1, DAY_MAX[FEB] + 1) );
	
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MIN - 1, 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, 1) );
	
	// one max+1, two min-1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MIN - 1) );
	
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MIN - 1) );
	
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MIN - 1, DAY_MAX[FEB] + 1) );
	
	// two max+1, one min-1
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MAX + 1, DAY_MIN - 1) );
	
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, MONTH_MIN - 1, DAY_MAX[FEB] + 1) );
	
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[JAN] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[APR] + 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1) );
}

TEST( NextDateCodeTest, CodeCoverageC0 ) {
    EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1) );
	EXPECT_EQ( 20140101, nextdate(2013, DEC, 31) );
}

TEST( NextDateCodeTest, CodeCoverageC1 ) {
    EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1) );
	EXPECT_EQ( 20121130, nextdate(2012, NOV, 29) );
	EXPECT_EQ( 20131201, nextdate(2013, NOV, 30) );
	EXPECT_EQ( 20140101, nextdate(2013, DEC, 31) );
}

TEST( NextDateCodeTest, CodeCoverageC2 ) {

    // same as CodeCoverageC1 since no loop in code
    EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, MONTH_MAX + 1, DAY_MAX[FEB] + 1) );
	EXPECT_EQ( 20121130, nextdate(2012, NOV, 29) );
	EXPECT_EQ( 20131201, nextdate(2013, NOV, 30) );
	EXPECT_EQ( 20140101, nextdate(2013, DEC, 31) );

}

TEST( NextDateCodeTest, CodeCoverageMCDC ) {

    // for the 1st branch
    EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MIN - 1, 1, 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MIN - 1, 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, 1, DAY_MIN - 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(YEAR_MAX + 1, 1, 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, MONTH_MAX + 1, 1) );
	EXPECT_EQ( ERR_INVALID_DATE, nextdate(2000, 2, DAY_MAX[FEB] + 1) );

    // for the 2nd & 3rd branch
	EXPECT_EQ( 20121130, nextdate(2012, NOV, 29) );
	EXPECT_EQ( 20140101, nextdate(2013, DEC, 31) );
}
