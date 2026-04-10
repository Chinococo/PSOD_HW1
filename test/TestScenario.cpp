#include <gtest/gtest.h>

#include "model/control/controller.h"

TEST(GateTest, TestScenarioFunction) {
    // 1. 準備模擬的使用者輸入 (每一行對應一次 Enter)
    std::stringstream simulatedInput;

    simulatedInput << "1\n" // Command: 1 (Load file)
            << "C:\\LS\\file_not_exist_or_format_error.lcf\n" // 輸入錯誤路徑
            << "2\n" // Command: 2 (Simulation - 未載入檔案)
            << "3\n"
            << "1\n" // Command: 1 (Load file)
            << "C:\\Users\\Chino\\CLionProjects\\PSOD_HW1\\test\\static\\illegal1.lcf\n"
            << "1\n" // Command: 1 (Load file)
            << "C:\\Users\\Chino\\CLionProjects\\PSOD_HW1\\test\\static\\example.lcf\n" // 輸入正確路徑
            << "2\n" // Command: 2 (Simulation)
            << "-1\n" // Pin 1: Invalid input (防呆測試)
            << "0\n" // Pin 1: Valid input
            << "1\n" // Pin 2: Valid input
            << "1\n" // Pin 3: Valid input
            << "3\n" // Command: 3 (Truth table)
            << "4\n"; // Command: 4 (Exit)

    // 2. 攔截 std::cin 與 std::cout
    std::stringstream capturedOutput;
    std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalCout = std::cout.rdbuf(capturedOutput.rdbuf());

    // 3. 執行 Controller
    // 建立物件 (建議變數名稱不要跟類別名稱一樣，這裡用 ctrl)
    controller ctrl;

    ctrl.process();

    // 4. 恢復原來的 cin 與 cout (非常重要！否則後續的其他測試或終端機輸出會壞掉)
    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);

    // 5. 驗證輸出結果
    std::string actualOutput = capturedOutput.str();

    // 驗證 A: 檔案不存在的防呆
    EXPECT_TRUE(actualOutput.find("File not found or file format error!!") != std::string::npos);

    // 驗證 B: 未載入檔案就模擬的防呆
    EXPECT_TRUE(actualOutput.find("Please load an lcf file, before using this operation.") != std::string::npos);

    // 驗證 C: 成功載入
    EXPECT_TRUE(actualOutput.find("Circuit: 3 input pins, 1 output pins and 3 gates") != std::string::npos);

    // 驗證 D: Pin 腳輸入防呆
    EXPECT_TRUE(actualOutput.find("The value of input pin must be 0/1") != std::string::npos);

    // 驗證 E: 模擬結果 (檢查關鍵的那一行計算結果)
    EXPECT_TRUE(actualOutput.find("0 1 1 | 0") != std::string::npos);

    // 驗證 F: 真值表 (挑幾行具代表性的來檢查)
    EXPECT_TRUE(actualOutput.find("1 0 1 | 1") != std::string::npos);
    EXPECT_TRUE(actualOutput.find("1 1 1 | 0") != std::string::npos);

    // 驗證 G: 成功離開
    EXPECT_TRUE(actualOutput.find("Goodbye, thanks for using LS.") != std::string::npos);
}
