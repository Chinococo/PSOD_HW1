//
// Created by Chino on 2026/4/9.
//

#include "../../../include/model/basic/oPin.h"
oPin::oPin(bool _input) {
    this->output = {_input};
}

std::vector<bool> oPin::getOutput() {
    if (output.empty()) {
        throw std::invalid_argument("Doesn't have output signal");
    }
    return this->output;
}
