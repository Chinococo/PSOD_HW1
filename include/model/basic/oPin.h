#ifndef PSOD_HW1_OUT_PIN_H
#define PSOD_HW1_OUT_PIN_H
#include "Device.h"

class oPin : public Device {
    std::vector<Device *> output;
public:
    oPin():Device(){}
    explicit oPin(Device *);
    std::vector<bool> getOutput() override;
};
#endif
