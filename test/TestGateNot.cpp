#include <gtest/gtest.h>

#include "../include/model/basic/iPin.h"
#include "../include/model/gates/gateNot.h"

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
