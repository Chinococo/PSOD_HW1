//
// Created by Chino on 2026/4/9.
//

#include "../../../include/model/gates/gateNot.h"
#include <system_error>

std::vector<bool> gateNot::getOutput() {
    if (this->iPins.empty())
        throw std::invalid_argument("AndGate doesn't have input signal");

    bool result = true;
    try {
        result = !this->iPins[0]->getOutput()[0];
    }catch(std::invalid_argument& e) {
        throw std::invalid_argument("AndGate can't simulation");
    }

    return std::vector<bool>{result};
}
