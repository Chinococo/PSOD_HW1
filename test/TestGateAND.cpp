#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateAND.h"


// 測試輸入不足的情況
TEST(GateTest, AndGateInsufficientInput) {
    gateAND andGate1,andGate2;
    // 只給一個輸入
    andGate1.addInputPin(new iPin(false));
    andGate2.addInputPin(new iPin(true));
    // 驗證是否會拋出 std::invalid_argument
    EXPECT_THROW(andGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);

    andGate2.addInputPin(new iPin());
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);
}

// 測試 2 輸入的 AND Gate
TEST(GateTest, AndGate2InputTruthTable) {
    for (int i = 0; i < 4; i++) {
        gateAND andGate;
        for (int j = 0; j < 2; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }

        int expected = (i == 3) ? 1 : 0; // 11 binary is 3
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

// 測試 3 輸入的 AND Gate
TEST(GateTest, AndGate3InputTruthTable) {
    for (int i = 0; i < 8; i++) {
        gateAND andGate;
        for (int j = 0; j < 3; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }

        int expected = (i == 7) ? 1 : 0; // 1111 binary is 15
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

// 測試 4 輸入的 AND Gate
TEST(GateTest, AndGate4InputTruthTable) {
    for (int i = 0; i < 16; i++) {
        gateAND andGate;
        for (int j = 0; j < 4; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }

        int expected = (i == 15) ? 1 : 0; // 1111 binary is 15
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}