//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_IPIN_H
#define PSOD_HW1_IPIN_H
#include <vector>
#include <stdexcept>
#include "Device.h"
#include "oPin.h"
using namespace std;

class iPin : public Device {
    vector<bool> output;
public:
    iPin(bool);
    vector<bool> getOutput() override;
};


#endif //PSOD_HW1_IPIN_H
