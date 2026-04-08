//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_GATEAND_H
#define PSOD_HW1_GATEAND_H
#include "../basic/Device.h"

class gateAND:public Device{
    public:
        gateAND():Device(){}
        gateAND(Device * d) : Device(d){}
        gateAND(const std::vector<Device *>& _iPins) : Device(_iPins){}
        std::vector<bool> getOutput() override;
};


#endif //PSOD_HW1_GATEAND_H
