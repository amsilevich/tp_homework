//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>
#include <stdexcept>

TEST_F(LeapTestCase, t1) {
    ASSERT_THROW(IsLeap(-100), std::invalid_argument);
}

TEST_F(LeapTestCase, t2) {
    ASSERT_TRUE(IsLeap(400));
}

TEST_F(LeapTestCase, t3) {
    ASSERT_FALSE(IsLeap(500));
}

TEST_F(LeapTestCase, t4) {
    ASSERT_TRUE(IsLeap(404));
}

TEST_F(LeapTestCase, t5) {
    ASSERT_FALSE(IsLeap(405));
}

