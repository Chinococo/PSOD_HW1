#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/basic/oPin.h"
/**
 * 驗證 iPin 在未設定初始值是否會抱錯
 */
TEST(GateTest, BasicInputTest) {
    iPin in1;
    EXPECT_THROW(in1.getOutput(), std::invalid_argument);
}

/**
 * 驗證 oPin 在外被指定時是否會抱錯
 */
TEST(GateTest, BasicOutputGateTest) {
    oPin out1;
    EXPECT_THROW(out1.getOutput(), std::invalid_argument);
}