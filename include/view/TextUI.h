#ifndef PSOD_HW1_TEXTUI_H
#define PSOD_HW1_TEXTUI_H
#include "../model/LogicSimulator.h"

/**
 * @class TextUI
 * @brief 負責處理文字介面顯示與使用者指令輸入的類別
 */
class TextUI {
    // 內部邏輯模擬器實例，處理核心運算
    LogicSimulator logic_simulator;
    // 標記目前是否已成功載入資料/檔案
    bool isLoad = false;
    // 標記使用者是否已選擇結束程式
    bool isFinished = false;
public:
    /**
     * @brief 顯示主選單介面
     */
    static void displayMenu();
    /**
     * @brief 讀取並解析使用者輸入的指令，並呼叫對應的 logic_simulator 功能
     */
    void processCommand();
    /**
     * @brief 檢查程式是否應該結束
     * @return true 表示使用者欲結束程式，false 則繼續執行
     */
    [[nodiscard]] bool isFinish() const;
};
#endif //PSOD_HW1_TEXTUI_H
