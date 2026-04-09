#include "control/LogicSimulator.h"
#include "utils/FileUtil.h"
#include <gtest/gtest.h>
TEST(GateTest, TestUtilsFunction) {
    LogicSimulator simulator;
    simulator.load("static/xor.lcf");

    EXPECT_EQ(utils::readFile("static/xor_truth_table.txt"), simulator.getTruthTable());
    EXPECT_EQ(utils::readFile("static/if_not_exist.txt"), "ERROR: File not found at static/if_not_exist.txt");
}