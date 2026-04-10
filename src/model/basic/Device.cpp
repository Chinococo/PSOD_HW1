#include "../../../include/model/basic/Device.h"

void Device::addInputPin(Device *iPin) {
    this->iPins.emplace_back(iPin);
}
