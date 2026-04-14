#ifndef PSOD_HW1_CONTROLLER_H
#define PSOD_HW1_CONTROLLER_H
#include "view/TextUI.h"

class controller {
    TextUI  text_ui;
public:
    controller()= default;
    void process();
};

#endif //PSOD_HW1_CONTROLLER_H
