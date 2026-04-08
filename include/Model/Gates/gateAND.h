//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_GATEAND_H
#define PSOD_HW1_GATEAND_H
#include "../Basic/Device.h"


class gateAND:public Device{
    public:
        gateAND():Device(){}
        gateAND(Device * d) : Device(d){}
        gateAND(const vector<Device *>& _iPins) : Device(_iPins){}
        vector<bool> getOutput() override;
};


#endif //PSOD_HW1_GATEAND_H
