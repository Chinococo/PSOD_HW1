#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateNot.h"
/**
 * 驗證 NOT Gate 的反轉邏輯，以及例外檢查
 */
TEST(GateTest, NotGateInput) {
    gateNot notGate1,notGate2,notGate3,notGate4;
    const auto p2 = std::make_unique<iPin>(false);
    const auto p3 = std::make_unique<iPin>(true);
    const auto p4 = std::make_unique<iPin>();
    notGate2.addInputPin(p2.get());
    notGate3.addInputPin(p3.get());
    notGate4.addInputPin(p4.get());

    EXPECT_EQ(notGate2.getOutput()[0], true) << "NotGate is not working";
    EXPECT_EQ(notGate3.getOutput()[0], false) << "NotGate is not working";
    // 如果notGate 沒輸入引腳
    EXPECT_THROW(notGate1.getOutput(), std::invalid_argument);
    // 如果notGate 輸入引腳沒定義數值
    EXPECT_THROW(notGate4.getOutput(), std::invalid_argument);
}
