#ifndef PSOD_HW1_GATE_AND_H
#define PSOD_HW1_GATE_AND_H
#include "../basic/Device.h"

class gateAND:public Device{
    public:
        gateAND():Device(){}
        explicit gateAND(Device * d) : Device(d){}
        explicit gateAND(const std::vector<Device *>& _iPins) : Device(_iPins){}
        std::vector<bool> getOutput() override;
};


#endif //PSOD_HW1_GATE_AND_H
