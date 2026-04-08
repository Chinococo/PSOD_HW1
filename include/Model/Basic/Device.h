//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_DEVICE_H
#define PSOD_HW1_DEVICE_H
#include <vector>
using namespace std;

class Device {

protected:
    vector<Device *> iPins;
public:
    Device(){};
    Device(Device *_iPin) {
        Device::addInputPin(_iPin);
    }
    Device(const vector<Device *>& _iPins) {
        for (Device * _iPin : _iPins)
            Device::addInputPin(_iPin);
    }

    void addInputPin(Device *iPin);
    virtual vector<bool> getOutput() = 0;
};


#endif //PSOD_HW1_DEVICE_H
