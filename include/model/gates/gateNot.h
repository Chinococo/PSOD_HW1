#ifndef PSOD_HW1_GATE_NOT_H
#define PSOD_HW1_GATE_NOT_H
#include "../basic/Device.h"

class gateNot :public Device{
public:
    gateNot():Device(){}
    explicit gateNot(Device * d) : Device(d){}
    std::vector<bool> getOutput() override;
};

#endif //PSOD_HW1_GATE_NOT_H
