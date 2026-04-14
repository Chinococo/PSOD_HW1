#ifndef PSOD_HW1_TEXTUI_H
#define PSOD_HW1_TEXTUI_H
#include "../model/LogicSimulator.h"

class TextUI {
    LogicSimulator logic_simulator;
    bool isLoad = false;
    bool isFinished = false;
public:
    static void displayMenu();
    void processCommand();
    [[nodiscard]] bool isFinish() const;
};
#endif //PSOD_HW1_TEXTUI_H
