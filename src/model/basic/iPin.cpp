//
// Created by Chino on 2026/4/9.
//

#include "../../../include/model/basic/iPin.h"
#include <system_error>
iPin::iPin(bool _input) {
    this->output = {_input};
}

std::vector<bool> iPin::getOutput() {
    if (output.empty()) {
        throw std::invalid_argument("Doesn't have Input signal");
    }
    return this->output;
}
