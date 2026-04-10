#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateNot.h"
/**
 * @test 驗證 NOT Gate 的反轉邏輯與輸入限制
 * @details
 * 1. **基本邏輯測試**：驗證 0 變 1 (true) 與 1 變 0 (false) 的基本反轉功能。
 * 2. **無輸入防呆**：當未透過 addInputPin 提供的輸入時，驗證是否拋出 std::invalid_argument。
 * 3. **無效 Pin 腳測試**：傳入未初始化的 iPin 時，驗證系統是否能正確攔截錯誤。
 * @note NOT Gate 在邏輯電路中屬於單輸入組件，若輸入數量不等於 1 應視為異常。
 * @see gateNot::getOutput()
 */
TEST(GateTest, NotGateInput) {
    gateNot notGate1,notGate2,notGate3,notGate4;
    // 只給一個輸入
    notGate2.addInputPin(new iPin(false));
    notGate3.addInputPin(new iPin(true));
    notGate4.addInputPin(new iPin());
    // 驗證是否會拋出 std::invalid_argument
    EXPECT_EQ(notGate2.getOutput()[0], true) << "NotGate is not working";
    EXPECT_EQ(notGate3.getOutput()[0], false) << "NotGate is not working";

    EXPECT_THROW(notGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(notGate4.getOutput(), std::invalid_argument);
}
