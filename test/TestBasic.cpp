#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/basic/oPin.h"
TEST(GateTest, BasicInputTest) {
    iPin in1;
    EXPECT_THROW(in1.getOutput(), std::invalid_argument);
}
TEST(GateTest, BasicOutputGateTest) {
    oPin out1,out2(true);
    EXPECT_EQ(out2.getOutput()[0], true);
    EXPECT_THROW(out1.getOutput(), std::invalid_argument);
}