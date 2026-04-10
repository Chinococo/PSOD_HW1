#include "../include/model/LogicSimulator.h"
#include "utils/FileUtil.h"
#include <gtest/gtest.h>
/**
 * @test 測試邏輯模擬器與檔案讀取工具的整合
 * @details
 * 1. 驗證 utils::readFile 是否能正確讀取真值表答案檔案。
 * 2. 驗證 LogicSimulator 加載電路檔 (.lcf) 後，生成的真值表是否與預期檔案內容相符。
 * 3. 答案檔案不存在時，工具函數是否回傳標準的錯誤訊息。
 * * @see utils::readFile()
 * @see LogicSimulator::load()
 * @see LogicSimulator::getTruthTable()
 */
TEST(GateTest, TestUtilsFunction) {
    LogicSimulator simulator;
    simulator.load("static/xor.lcf");

    EXPECT_EQ(utils::readFile("static/xor_truth_table.txt"), simulator.getTruthTable());
    EXPECT_EQ(utils::readFile("static/if_not_exist.txt"), "ERROR: File not found at static/if_not_exist.txt");
}