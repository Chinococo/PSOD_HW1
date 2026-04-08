//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_OPIN_H
#define PSOD_HW1_OPIN_H
#include "Device.h"
#include <stdexcept>
using namespace std;

class oPin : public Device {
    vector<bool> output;
public:
    oPin(bool);
    vector<bool> getOutput() override;
};


#endif //PSOD_HW1_OPIN_H
