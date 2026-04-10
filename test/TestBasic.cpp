#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/basic/oPin.h"
/**
 * @test 驗證 iPin 在未初始化狀態下的行為
 * @details
 * 測試當一個 iPin 物件剛被建立、尚未透過建構子或 setter 設定任何邏輯電平（0 或 1）時，
 * 呼叫 getOutput() 應視為無效操作。
 * @expect 預期拋出 std::invalid_argument 異常。
 */
TEST(GateTest, BasicInputTest) {
    iPin in1;
    EXPECT_THROW(in1.getOutput(), std::invalid_argument);
}

/**
 * @test 驗證 oPin 在未連接狀態下的行為
 * @details
 * oPin 通常作為電路的輸出終端，必須連接到某個邏輯閘或輸入源。
 * 本測試驗證當 oPin 處於「懸空（Floating）」狀態（未連接任何來源）時，
 * 嘗試獲取其輸出值是否會正確觸發錯誤攔截。
 * @expect 預期拋出 std::invalid_argument 異常。
 */
TEST(GateTest, BasicOutputGateTest) {
    oPin out1;
    EXPECT_THROW(out1.getOutput(), std::invalid_argument);
}