#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/basic/oPin.h"
TEST(GateTest, BasicInputTest) {
    iPin in1;
    EXPECT_THROW(in1.getOutput(), std::invalid_argument);
}
TEST(GateTest, BasicOutputGateTest) {
    oPin out1;
    EXPECT_THROW(out1.getOutput(), std::invalid_argument);
}