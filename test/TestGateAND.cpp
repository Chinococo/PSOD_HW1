#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateAND.h"


/**
 * 驗證 AND Gate 輸入錯誤資料是否會抱錯
 */
TEST(GateTest, AndGateInsufficientInput) {
    gateAND andGate1,andGate2;
    auto p1 = std::make_unique<iPin>(false);
    auto p2 = std::make_unique<iPin>(true);
    auto p3 = std::make_unique<iPin>();
    andGate1.addInputPin(p1.get());
    andGate2.addInputPin(p2.get());

    // 只給一個輸入 驗證是否會拋出 std::invalid_argument
    EXPECT_THROW(andGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);

    // 有個iPin無法得到數值，驗證是否會拋出 std::invalid_argument
    andGate2.addInputPin(p3.get());
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);
}

/**
 * 驗證 2-AND Gate 的完整真值表
 */
TEST(GateTest, AndGate2InputTruthTable) {
    for (int i = 0; i < 4; i++) {
        gateAND andGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 2; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            andGate.addInputPin(pins.back().get());
        }
        //只有11(3)答案會是True
        int expected = (i == 3) ? 1 : 0;
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * 驗證 3-AND Gate 的完整真值表
 */
TEST(GateTest, AndGate3InputTruthTable) {
    for (int i = 0; i < 8; i++) {
        gateAND andGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 3; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            andGate.addInputPin(pins.back().get());
        }
        //只有111(7)答案會是True
        int expected = (i == 7) ? 1 : 0;
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

/**
 * 驗證 4-AND Gate 的完整真值表
 */
TEST(GateTest, AndGate4InputTruthTable) {
    for (int i = 0; i < 16; i++) {
        gateAND andGate;
        std::vector<std::unique_ptr<iPin>> pins;
        for (int j = 0; j < 4; j++) {
            pins.push_back(std::make_unique<iPin>((i >> j) & 1));
            andGate.addInputPin(pins.back().get());
        }
        //只有1111(15)答案會是True
        int expected = (i == 15) ? 1 : 0;
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}