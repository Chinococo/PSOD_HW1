//
// Created by Chino on 2026/4/9.
//

#include "Device.h"
void Device::addInputPin(Device *iPin) {
    this->iPins.emplace_back(iPin);
}
