//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_GATENOT_H
#define PSOD_HW1_GATENOT_H
#include "../basic/Device.h"

class gateNot :public Device{
public:
    gateNot():Device(){}
    gateNot(Device * d) : Device(d){}
    std::vector<bool> getOutput() override;
};



#endif //PSOD_HW1_GATENOT_H
