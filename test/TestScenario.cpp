#include <gtest/gtest.h>

#include "model/control/controller.h"
/**
 * @test 整合情境測試：驗證模擬器控制流程與使用者互動防呆
 * @details
 * 本測試模擬使用者操作全流程，包含以下檢查點：
 * 1. **檔案異常處理**：輸入不存在的路徑或格式錯誤檔案（illegal1.lcf）應報錯。
 * 2. **狀態機保護**：在未成功載入電路前，執行模擬或顯示真值表應受阻。
 * 3. **輸入校驗**：模擬時輸入非 0/1 的數值（應觸發防呆提示。
 * 4. **核心邏輯**：驗證在正確載入 example.lcf 後，模擬結果與真值表內容是否精準。
 * 5. **生命週期**：輸入指令 4 能否正確結束程式循環。
 * @see controller::process()
 */
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

    // 2. 攔截 std輸入
    std::stringstream capturedOutput;
    std::streambuf *originalInput = std::cin.rdbuf(simulatedInput.rdbuf());
    std::streambuf *originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

    // 3. 執行 Controller
    // 建立物件 (建議變數名稱不要跟類別名稱一樣，這裡用 ctrl)
    controller ctrl;

    ctrl.process();

    // 4. 恢復 std輸入
    std::cin.rdbuf(originalInput);
    std::cout.rdbuf(originalOutput);

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
