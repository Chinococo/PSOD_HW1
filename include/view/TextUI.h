//
// Created by Chino on 2026/4/10.
//

#ifndef PSOD_HW1_TEXTUI_H
#define PSOD_HW1_TEXTUI_H
#include "../model/LogicSimulator.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "model/basic/iPin.h"

class TextUI {
    LogicSimulator logic_simulator;
    bool isLoad = false;
    bool isFinished = false;
public:
    static void displayMenu();
    void processCommand();
    bool isFinish();
};



#endif //PSOD_HW1_TEXTUI_H
