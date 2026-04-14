#include "../include/model/LogicSimulator.h"
#include <gtest/gtest.h>

#include "model/basic/iPin.h"
#include <fstream>
#include <string>

#include "utils/FileUtil.h"

/**
 * 2-XOR 電路模擬結果
 * 載入標準 XOR 電路設定檔 (xor.lcf)
 * 依序測試 XOR 邏輯的四種輸入組合：(0,0), (0,1), (1,0), (1,1)。
 */
TEST(GateTest, TestLoadXorSimulation) {
    LogicSimulator simulator;
    simulator.load("static/xor.lcf");
    const auto p0 = std::make_unique<iPin>(0);
    const auto p1 = std::make_unique<iPin>(1);

    EXPECT_EQ(simulator.getSimulationResult({p0.get(), p0.get()}), "i i | o\n1 2 | 1\n----+--\n0 0 | 0");
    EXPECT_EQ(simulator.getSimulationResult({p0.get(), p1.get()}), "i i | o\n1 2 | 1\n----+--\n0 1 | 1");
    EXPECT_EQ(simulator.getSimulationResult({p1.get(), p0.get()}), "i i | o\n1 2 | 1\n----+--\n1 0 | 1");
    EXPECT_EQ(simulator.getSimulationResult({p1.get(), p1.get()}), "i i | o\n1 2 | 1\n----+--\n1 1 | 0");
}

/**
 * 3-XOR 電路模擬結果
 * 載入標準 XOR 電路設定檔 (xor.lcf)
 * 依序測試 XOR 邏輯的八種輸入組合：(0,0,0)~(1,1,1)。
 */
TEST(GateTest, TestLoadExample1Simulation) {
    LogicSimulator simulator;
    simulator.load("static/example.lcf");
    const auto p0 = std::make_unique<iPin>(0);
    const auto p1 = std::make_unique<iPin>(1);
    EXPECT_EQ(simulator.getSimulationResult({p0.get(), p0.get(), p0.get()}), "i i i | o\n1 2 3 | 1\n------+--\n0 0 0 | 0");
    EXPECT_EQ(simulator.getSimulationResult({p0.get(), p0.get(), p1.get()}), "i i i | o\n1 2 3 | 1\n------+--\n0 0 1 | 0");
    EXPECT_EQ(simulator.getSimulationResult({p0.get(), p1.get(), p0.get()}), "i i i | o\n1 2 3 | 1\n------+--\n0 1 0 | 0");
    EXPECT_EQ(simulator.getSimulationResult({p0.get(), p1.get(), p1.get()}), "i i i | o\n1 2 3 | 1\n------+--\n0 1 1 | 0");
    EXPECT_EQ(simulator.getSimulationResult({p1.get(), p0.get(), p0.get()}), "i i i | o\n1 2 3 | 1\n------+--\n1 0 0 | 1");
    EXPECT_EQ(simulator.getSimulationResult({p1.get(), p0.get(), p1.get()}), "i i i | o\n1 2 3 | 1\n------+--\n1 0 1 | 1");
    EXPECT_EQ(simulator.getSimulationResult({p1.get(), p1.get(), p0.get()}), "i i i | o\n1 2 3 | 1\n------+--\n1 1 0 | 0");
    EXPECT_EQ(simulator.getSimulationResult({p1.get(), p1.get(), p1.get()}), "i i i | o\n1 2 3 | 1\n------+--\n1 1 1 | 0");
}
/**
    讀取格式錯誤的 .lcf 檔案是否會正確抱錯
 */
TEST(GateTest, TestLoadBroken) {
    LogicSimulator simulator;
    EXPECT_THROW(simulator.load("static/illegal1.lcf"), std::invalid_argument);
    EXPECT_THROW(simulator.load("static/illegal2.lcf"), std::invalid_argument);
}

/**
 * 嘗試載入不存在的路徑，驗證 load() 函數是否能正確回傳 false 狀態。
 */
TEST(GateTest, TestFileIsNotExist) {
    LogicSimulator simulator;
    EXPECT_EQ(simulator.load("static/fuck.lcf"), false);
}

/**
 * 驗證完整真值表生成功能
 */
TEST(GateTest, TestTruthTable) {
    LogicSimulator simulator;
    // 測試 XOR 真值表
    simulator.load("static/xor.lcf");
    std::string ans = utils::readFile("static/xor_truth_table.txt");
    EXPECT_EQ(simulator.getTruthTable(), ans);

    // 測試 Example 1 真值表
    simulator.load("static/example.lcf");
    ans = utils::readFile("static/example_truth_table.txt");
    EXPECT_EQ(simulator.getTruthTable(), ans);
}
