#include <stdio.h>
#include <gtest/gtest.h>
#include "nextdate.h"

TEST( NextDateTest, BoundaryDate ) {
	EXPECT_EQ( 19700102, nextdate( YEAR_MIN, MONTH_MIN, DAY_MIN ) );
	EXPECT_EQ( 20150101, nextdate( YEAR_MAX, MONTH_MAX, DAY_MAX[MONTH_MAX] ) );
}

TEST( NextDateTest, WeakNormal_Month_31Days ) {
	
	printf( "Months with 31 days: Jan. Mar. May. Jul. Aug. Oct. Dec.\n");
	
	EXPECT_EQ( 20110116, nextdate(2011, JAN, 15) );
	EXPECT_EQ( 20120131, nextdate(2012, JAN, 30) );
	EXPECT_EQ( 20130201, nextdate(2013, JAN, 31) );
	
	EXPECT_EQ( 20110316, nextdate(2011, MAR, 15) );
	EXPECT_EQ( 20120331, nextdate(2012, MAR, 30) );
	EXPECT_EQ( 20130401, nextdate(2014, MAR, 31) );
	
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

