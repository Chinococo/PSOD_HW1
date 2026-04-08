//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_OPIN_H
#define PSOD_HW1_OPIN_H
#include "Device.h"


class oPin : public Device {
    std::vector<bool> output;
public:
    oPin():Device(){};
    oPin(bool);
    std::vector<bool> getOutput() override;
};


#endif //PSOD_HW1_OPIN_H
