#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateOR.h"

/**
 * 驗證 OR Gate
 * 1. 測試僅提供 1 個輸入時，呼叫 getOutput()
 * 2. 測試僅提供有為定義的 inPin 輸入時，呼叫 getOutput()，無法得到正確數值
 */
TEST(GateTest, ORGateInsufficientInput) {
    gateOR orGate1, orGate2;

    auto p1 = std::make_unique<iPin>(false);
    auto p2 = std::make_unique<iPin>(true);
    auto p3 = std::make_unique<iPin>();
    orGate1.addInputPin(p1.get());
    orGate2.addInputPin(p2.get());
    // 只給一個輸入 所以or無法得到結果
    EXPECT_THROW(orGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(orGate2.getOutput(), std::invalid_argument);
    // 雖然是兩個輸入，但有個輸入無法拿到確切的數值
    orGate2.addInputPin(p3.get());
    EXPECT_THROW(orGate2.getOutput(), std::invalid_argument);
}

/**
 * 驗證 2 輸入 OR Gate 的完整真值表
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
        //除了0000(0)以外都是1
        int expected = (i == 0) ? 0 : 1; // only 00 binary is false
        EXPECT_EQ(orGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * 驗證 3 輸入 OR Gate 的完整真值表
 * 遍歷 8 種組合 (000 ~ 111)情況下的計算正確性。
 */
TEST(GateTest, ORGate3InputTruthTable) {
    for (int i = 0; i < 8; i++) {
        gateOR orGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 3; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            orGate.addInputPin(pins.back().get());
        }
        //除了0000(0)以外都是1
        int expected = (i == 0) ? 0 : 1;
        EXPECT_EQ(orGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * 驗證 4 輸入 OR Gate 的完整真值表
 * 遍歷 16 種組合 (0000 ~ 1111)情況下的計算正確性。
 */
TEST(GateTest, ORGate4InputTruthTable) {
    for (int i = 0; i < 16; i++) {
        gateOR orGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 4; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            orGate.addInputPin(pins.back().get());
        }
        //除了0000(0)以外都是1
        int expected = (i == 0) ? 0 : 1;
        EXPECT_EQ(orGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}