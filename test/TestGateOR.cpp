#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateOR.h"

/**
 * @test 驗證 OR Gate 的輸入不足防呆
 * @details
 * 1. 測試僅提供 1 個輸入時，呼叫 getOutput() 是否拋出 std::invalid_argument。
 * 2. 測試提供空指標或未定義 iPin 腳時，系統的異常處理。
 * @note 根據設計規範，OR Gate 至少需要 2 個輸入才能運算。
 */
TEST(GateTest, ORGateInsufficientInput) {
    gateOR orGate1, orGate2;
    // 只給一個輸入
    auto p1 = std::make_unique<iPin>(false);
    auto p2 = std::make_unique<iPin>(true);
    auto p3 = std::make_unique<iPin>();
    orGate1.addInputPin(p1.get());
    orGate2.addInputPin(p2.get());
    // 驗證是否會拋出 std::invalid_argument
    EXPECT_THROW(orGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(orGate2.getOutput(), std::invalid_argument);
    orGate2.addInputPin(p3.get());
    EXPECT_THROW(orGate2.getOutput(), std::invalid_argument);
}

/**
 * @test 驗證 2 輸入 OR Gate 的完整真值表
 * @details
 * 遍歷 4 種組合 (00 ~ 11)情況下的計算正確性。
 */
TEST(GateTest, ORGate2InputTruthTable) {
    for (int i = 0; i < 4; i++) {
        gateOR orGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 2; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            orGate.addInputPin(pins.back().get());
        }

        int expected = (i == 0) ? 0 : 1; // only 00 binary is false
        EXPECT_EQ(orGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * @test 驗證 3 輸入 OR Gate 的完整真值表
 * @details 遍歷 8 種組合 (000 ~ 111)情況下的計算正確性。
 */
TEST(GateTest, ORGate3InputTruthTable) {
    for (int i = 0; i < 8; i++) {
        gateOR orGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 3; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            orGate.addInputPin(pins.back().get());
        }

        int expected = (i == 0) ? 0 : 1;
        EXPECT_EQ(orGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * @test 驗證 4 輸入 OR Gate 的完整真值表
 * @details 遍歷 16 種組合 (0000 ~ 1111)情況下的計算正確性。
 */
TEST(GateTest, ORGate4InputTruthTable) {
    for (int i = 0; i < 16; i++) {
        gateOR orGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 4; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            orGate.addInputPin(pins.back().get());
        }

        int expected = (i == 0) ? 0 : 1;
        EXPECT_EQ(orGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}