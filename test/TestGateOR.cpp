#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateOR.h"


// 測試輸入不足的情況
TEST(GateTest, ORGateInsufficientInput) {
    gateOR andGate1,andGate2;
    // 只給一個輸入
    andGate1.addInputPin(new iPin(false));
    andGate2.addInputPin(new iPin(true));
    // 驗證是否會拋出 std::invalid_argument
    EXPECT_THROW(andGate1.getOutput(), std::invalid_argument);
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);

    andGate2.addInputPin(new iPin());
    EXPECT_THROW(andGate2.getOutput(), std::invalid_argument);
}

// 測試 2 輸入的 OR Gate
TEST(GateTest, ORGate2InputTruthTable) {
    for (int i = 0; i < 4; i++) {
        gateOR andGate;
        for (int j = 0; j < 2; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }

        int expected = (i == 0) ? 0 : 1; // 11 binary is 3
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

// 測試 3 輸入的 OR Gate
TEST(GateTest, ORGate3InputTruthTable) {
    for (int i = 0; i < 8; i++) {
        gateOR andGate;
        for (int j = 0; j < 3; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }

        int expected = (i == 0) ? 0 : 1; // 1111 binary is 15
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}

// 測試 4 輸入的 OR Gate
TEST(GateTest, ORGate4InputTruthTable) {
    for (int i = 0; i < 16; i++) {
        gateOR andGate;
        for (int j = 0; j < 4; j++) {
            andGate.addInputPin(new iPin((i >> j) & 1));
        }

        int expected = (i == 0) ? 0 : 1; // 1111 binary is 15
        EXPECT_EQ(andGate.getOutput()[0], expected) << "Failed at input combination: " << i;
    }
}