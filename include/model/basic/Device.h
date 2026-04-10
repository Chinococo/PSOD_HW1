#ifndef PSOD_HW1_DEVICE_H
#define PSOD_HW1_DEVICE_H
#include <vector>

class Device {
protected:
    std::vector<Device *> iPins;
public:
    virtual ~Device() = default;

    Device()= default;

    explicit Device(Device *_iPin) {
        Device::addInputPin(_iPin);
    }
    explicit Device(const std::vector<Device *>& _iPins) {
        for (Device * _iPin : _iPins)
            Device::addInputPin(_iPin);
    }
    void addInputPin(Device *iPin);
    virtual std::vector<bool> getOutput() = 0;
};

#endif //PSOD_HW1_DEVICE_H
