#include "../../include/model/control/controller.h"

void controller::process() {
    while (!text_ui.isFinish()) {
        TextUI::displayMenu();
        text_ui.processCommand();
    }
}