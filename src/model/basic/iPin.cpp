#include "../../../include/model/basic/iPin.h"
#include <system_error>

iPin::iPin(bool _input) {
    this->output = {_input};
}

std::vector<bool> iPin::getOutput() {
    // 輸入不足
    if (output.empty()) {
        throw std::invalid_argument("Doesn't have Input signal");
    }
    return this->output;
}

iPin &iPin::operator=(const iPin &other) {
    this->output = {other.iPins[0]->getOutput()[0]};
    return *this;
}
