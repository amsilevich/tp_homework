//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, t1) {
    ASSERT_EQ(Add(3, 5), 8);
}
