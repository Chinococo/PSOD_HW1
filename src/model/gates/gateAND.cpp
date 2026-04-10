#include "../../../include/model/gates/gateAND.h"
#include "../../../include/model/basic/oPin.h"
#include <iostream>

std::vector<bool> gateAND::getOutput() {
    if (this->iPins.size() < 2)
        throw std::invalid_argument("AndGate doesn't have enough input signal");
    bool result = true;
    try {
        for (auto _iPin: this->iPins) {
            bool output = _iPin->getOutput()[0];
            result = result && output;
        }
    } catch (std::invalid_argument &) {
        throw std::invalid_argument("AndGate can't simulation");
    }
    return {result};
}
