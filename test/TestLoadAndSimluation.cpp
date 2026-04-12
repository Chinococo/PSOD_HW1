#include "../include/model/LogicSimulator.h"
#include <gtest/gtest.h>

#include "model/basic/iPin.h"
#include <fstream>
#include <string>

#include "utils/FileUtil.h"

/**
 * @test 驗證 XOR 電路模擬結果
 * @details
 * 1. 載入標準 XOR 電路設定檔 (xor.lcf)。
 * 2. 依序測試 XOR 邏輯的四種輸入組合：(0,0), (0,1), (1,0), (1,1)。
 * 3. 驗證輸出字串格式與邏輯運算結果是否完全正確。
 * @note 傳入 getSimulationResult 的 iPin 物件應確保會被正確釋放，避免記憶體洩漏。
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
 * @test 驗證複雜電路 (3-input) 的模擬結果
 * @details
 * 載入 example.lcf 並遍歷 8 種輸入組合 (000 ~ 111)，
 * 確保多級邏輯閘連接後的輸出結果與預期相符。
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
 * @test 驗證非法檔案格式處理 (Robustness)
 * @details 嘗試載入格式錯誤的 .lcf 檔案，預期程式應拋出 std::invalid_argument 異常而非崩潰。
 */
TEST(GateTest, TestLoadBroken) {
    LogicSimulator simulator;
    EXPECT_THROW(simulator.load("static/illegal1.lcf"), std::invalid_argument);
    EXPECT_THROW(simulator.load("static/illegal2.lcf"), std::invalid_argument);
}

/**
 * @test 驗證檔案不存在之例外處理
 * @details 嘗試載入不存在的路徑，驗證 load() 函數是否能正確回傳 false 狀態。
 */
TEST(GateTest, TestFileIsNotExist) {
    LogicSimulator simulator;
    EXPECT_EQ(simulator.load("static/fuck.lcf"), false);
}

/**
 * @test 驗證完整真值表生成功能
 * @details
 * 將模擬器生成的全組合真值表 (getTruthTable) 答案檔進行比對，
 * 確保大批量資料輸出的正確性。
 * @see utils::readFile()
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
