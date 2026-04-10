#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateAND.h"


/**
 * @test 驗證 AND Gate 的輸入不足防呆機制
 * @details
 * 1. **少於兩個輸入**：當僅提供 1 個輸入時，驗證 getOutput() 是否拋出 std::invalid_argument。
 * 2. **無效狀態 Pin 腳**：當傳入未定義數值的 iPin 時，驗證系統是否能正確攔截並報錯。
 * @note 根據邏輯電路規範，AND Gate 屬於多輸入組件，運算基準至少需 2 個輸入。
 */
TEST(GateTest, AndGateInsufficientInput) {
    gateAND andGate1,andGate2;
    // 只給一個輸入
    andGate1.addInputPin(new iPin(false));
    andGate2.addInputPin(new iPin(true));
    // 驗證是否會拋出 std::invalid_argument
    EXPECT_THROW(andGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);
    // 有個iPin無法得到數值，驗證是否會拋出 std::invalid_argument
    andGate2.addInputPin(new iPin());
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);
}

/**
 * @test 驗證 2 輸入 AND Gate 的完整真值表
 * @details
 * 透過位移運算遍歷 00, 01, 10, 11 四種組合。
 * 預期結果： 全部輸入1(11)時輸出為 1，其餘組合輸出皆應為 0。
 */
TEST(GateTest, AndGate2InputTruthTable) {
    for (int i = 0; i < 4; i++) {
        gateAND andGate;
        for (int j = 0; j < 2; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }
        int expected = (i == 3) ? 1 : 0;
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * @test 驗證 3 輸入 AND Gate 的完整真值表
 * @details
 * 透過位移運算遍歷 000~111 八種組合。
 * 預期結果： 全部輸入1(111)時輸出為 1，其餘組合輸出皆應為 0。
 */
TEST(GateTest, AndGate3InputTruthTable) {
    for (int i = 0; i < 8; i++) {
        gateAND andGate;
        for (int j = 0; j < 3; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }
        int expected = (i == 7) ? 1 : 0;
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * @test 驗證 4 輸入 AND Gate 的完整真值表
 * @details
 * 透過位移運算遍歷 0000~1111 十六種組合。
 * 預期結果： 全部輸入1(1111)時輸出為 1，其餘組合輸出皆應為 0。
 */
TEST(GateTest, AndGate4InputTruthTable) {
    for (int i = 0; i < 16; i++) {
        gateAND andGate;
        for (int j = 0; j < 4; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }
        int expected = (i == 15) ? 1 : 0;
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}