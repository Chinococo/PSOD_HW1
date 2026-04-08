//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_IPIN_H
#define PSOD_HW1_IPIN_H
#include "Device.h"


class iPin : public Device {
    std::vector<bool> output;
public:
    iPin():Device(){};
    iPin(bool);
    std::vector<bool> getOutput() override;
};


#endif //PSOD_HW1_IPIN_H
