#ifndef PSOD_HW1_GATE_OR_H
#define PSOD_HW1_GATE_OR_H
#include "../basic/Device.h"


class gateOR :public Device{
public:
    gateOR():Device(){}
    gateOR(Device * d) : Device(d){}
    gateOR(const std::vector<Device *>& _iPins) : Device(_iPins){}
    std::vector<bool> getOutput() override;
};



#endif //PSOD_HW1_GATE_OR_H
