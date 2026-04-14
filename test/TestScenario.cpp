#include <gtest/gtest.h>

#include "model/control/controller.h"
#include "utils/FileUtil.h"

/**
 * 實務場景1:無法載入檔案
 */
TEST(GateTest, TestScenario1Function) {
    // 準備模擬的使用者輸入
    std::stringstream simulatedInput;
    simulatedInput << "1\n"
            << "C:\\LS\\file_not_exist_or_format_error.lcf\n"
            << "2\n"
            << "4\n";

    // 載入到buffer
    std::stringstream capturedOutput;
    std::streambuf *originalInput = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // 建立controller
    controller ctrl;
    ctrl.process();

    // 還給正常std
    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);

    // 5. 驗證輸出結果
    std::string actualOutput = capturedOutput.str();

    // 檔案不存在
    EXPECT_TRUE(actualOutput.find("File not found or file format error!!") != std::string::npos);
    // 未載入檔案就模擬
    EXPECT_TRUE(actualOutput.find("Please load an lcf file, before using this operation.") != std::string::npos);
    // 成功離開
    EXPECT_TRUE(actualOutput.find("Goodbye, thanks for using LS.") != std::string::npos);

}
/**
 * 實務場景2:載入檔案，但檔案內部格式錯誤
 */
TEST(GateTest, TestScenario2Function) {
    // 準備模擬的使用者輸入
    std::stringstream simulatedInput;
    simulatedInput << "1\n"
            <<  PROJECT_ROOT_DIR << "/test/static/illegal1.lcf\n" // 錯誤格式檔案
            << "4\n";

    // 載入到buffer
    std::stringstream capturedOutput;
    std::streambuf *originalInput = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // 建立controller
    controller ctrl;
    ctrl.process();

    // 還給正常std
    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);

    std::string actualOutput = capturedOutput.str();
    // 檔案格式錯誤
    EXPECT_TRUE(actualOutput.find("File not found or file format error!!") != std::string::npos);
    // 成功離開
    EXPECT_TRUE(actualOutput.find("Goodbye, thanks for using LS.") != std::string::npos);

}
/**
 * 實務場景3: 載入xor.lcf並模擬跟輸出真值表
 */
TEST(GateTest, TestScenario3Function) {
    // 準備模擬的使用者輸入
    std::stringstream simulatedInput;
    simulatedInput << "1\n"
            << PROJECT_ROOT_DIR << "/test/static/xor.lcf\n" // 輸入正確路徑
            << "2\n"
            << "-1\n" // 錯誤輸入
            << "0\n"
            << "1\n"
            << "3\n"
            << "4\n";


    // 載入到buffer
    std::stringstream capturedOutput;
    std::streambuf *originalInput = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // 建立controller
    controller ctrl;
    ctrl.process();

    // 還給正常std
    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);

    std::string actualOutput = capturedOutput.str();
    // 輸入腳位數值檢查
    EXPECT_TRUE(actualOutput.find("The value of input pin must be 0/1") != std::string::npos);
    // 檢查模擬 (0,1) 答案是否為 1
    EXPECT_TRUE(actualOutput.find("i i | o\n1 2 | 1\n----+--\n0 1 | 1") != std::string::npos);
    // 檢查真值表
    EXPECT_TRUE(actualOutput.find(utils::readFile(std::string(PROJECT_ROOT_DIR) + "/test/static/xor_truth_table.txt")) != std::string::npos);
    // 成功離開
    EXPECT_TRUE(actualOutput.find("Goodbye, thanks for using LS.") != std::string::npos);
}
/**
 * 實務場景4: 載入example.lcf並模擬跟輸出真值表
 */
TEST(GateTest, TestScenario4Function) {
    // 準備模擬的使用者輸入
    std::stringstream simulatedInput;
    simulatedInput << "1\n"
            << PROJECT_ROOT_DIR << "/test/static/example.lcf\n" // 輸入正確路徑
            << "2\n"
            << "-1\n" // 錯誤輸入
            << "0\n"
            << "0\n"
            << "1\n"
            << "3\n"
            << "4\n";


    // 載入到buffer
    std::stringstream capturedOutput;
    std::streambuf *originalInput = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // 建立controller
    controller ctrl;
    ctrl.process();

    // 還給正常std
    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);

    std::string actualOutput = capturedOutput.str();
    // 輸入腳位數值檢查
    EXPECT_TRUE(actualOutput.find("The value of input pin must be 0/1") != std::string::npos);
    // 檢查模擬 (0,1) 答案是否為 1
    EXPECT_TRUE(actualOutput.find("i i i | o\n1 2 3 | 1\n------+--\n0 0 1 | 0") != std::string::npos);
    // 檢查真值表
    EXPECT_TRUE(actualOutput.find(utils::readFile(std::string(PROJECT_ROOT_DIR) + "/test/static/example_truth_table.txt")) != std::string::npos);
    // 成功離開
    EXPECT_TRUE(actualOutput.find("Goodbye, thanks for using LS.") != std::string::npos);
}

/**
 * 實務場景5: 載入full_adder.lcf並模擬跟輸出真值表 o1=sum o2=cout
 */
TEST(GateTest, TestScenario5Function) {
    // 準備模擬的使用者輸入
    std::stringstream simulatedInput;
    simulatedInput << "1\n"
            << PROJECT_ROOT_DIR << "/test/static/full_adder.lcf\n" // 輸入正確路徑
            << "2\n"
            << "-1\n" // 錯誤輸入
            << "1\n"
            << "0\n"
            << "1\n"
            << "3\n"
            << "4\n";


    // 載入到buffer
    std::stringstream capturedOutput;
    std::streambuf *originalInput = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // 建立controller
    controller ctrl;
    ctrl.process();

    // 還給正常std
    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);

    std::string actualOutput = capturedOutput.str();
    // 輸入腳位數值檢查
    EXPECT_TRUE(actualOutput.find("The value of input pin must be 0/1") != std::string::npos);
    // 檢查模擬 (0,1) 答案是否為 1
    EXPECT_TRUE(actualOutput.find("i i i | o o\n1 2 3 | 1 2\n------+----\n1 0 1 | 0 1") != std::string::npos);
    // 檢查真值表
    EXPECT_TRUE(actualOutput.find(utils::readFile(std::string(PROJECT_ROOT_DIR) + "/test/static/full_adder_truth_table.txt")) != std::string::npos);
    // 成功離開
    EXPECT_TRUE(actualOutput.find("Goodbye, thanks for using LS.") != std::string::npos);
}