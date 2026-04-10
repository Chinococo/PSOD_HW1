//
// Created by Chino on 2026/4/10.
//

#ifndef PSOD_HW1_CONTROLLER_H
#define PSOD_HW1_CONTROLLER_H
#include "view/TextUI.h"
/**
 * @class controller
 * @brief 系統的主控制類別，負責協調 UI 顯示與程式生命週期
 */
class controller {
    TextUI  text_ui;
public:
    controller()= default;
    /**
     * @brief 啟動程式的主迴圈
     * 通常會在此函式中持續呼叫 text_ui.displayMenu() 與 text_ui.processCommand()，
     * 直到使用者選擇退出（text_ui.isFinish() 為 true）為止。
     */
    void process();
};

#endif //PSOD_HW1_CONTROLLER_H
