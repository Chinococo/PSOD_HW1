//
// Created by Chino on 2026/4/10.
//

#include "../../include/model/control/controller.h"

void controller::process() {
    while (!text_ui.isFinish()) {
        text_ui.displayMenu();
        text_ui.processCommand();
    }
}