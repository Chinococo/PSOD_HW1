//
// Created by Chino on 2026/4/9.
//

#include "../../../include/Model/Basic/iPin.h"

iPin::iPin(bool _input) {
    this->output = {_input};
}

vector<bool> iPin::getOutput() {
    if (output.empty()) {
        throw std::invalid_argument("Doesn't have Input signal");
    }
    return this->output;
}
