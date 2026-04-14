#ifndef PSOD_HW1_IN_PIN_H
#define PSOD_HW1_IN_PIN_H
#include "Device.h"

class iPin : public Device {
    std::vector<bool> output;
public:
    iPin():Device(){}
    explicit iPin(bool _input);
    std::vector<bool> getOutput() override;
    iPin& operator=(const iPin&);
};


#endif
