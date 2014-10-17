#include <stdio.h>
#include <gtest/gtest.h>
#include "nextdate.h"

TEST( NextDateTest, BoundaryDate ) {
	EXPECT_EQ( 19700102, nextdate( YEAR_MIN, MONTH_MIN, DAY_MIN ) );
	EXPECT_EQ( 20150101, nextdate( YEAR_MAX, MONTH_MAX, DAY_MAX[MONTH_MAX] ) );
}

