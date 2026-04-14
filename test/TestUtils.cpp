#include "../include/model/LogicSimulator.h"
#include "utils/FileUtil.h"
#include <gtest/gtest.h>
/**
 * 驗證讀取檔案工具是否正常
 */
TEST(GateTest, TestUtilsFunction) {
    LogicSimulator simulator;
    simulator.load("static/xor.lcf");
    // 可以正確讀取答案
    EXPECT_EQ(utils::readFile("static/xor_truth_table.txt"), simulator.getTruthTable());
    // 無法得到答案會正確抱錯
    EXPECT_EQ(utils::readFile("static/if_not_exist.txt"), "ERROR: File not found at static/if_not_exist.txt");
}