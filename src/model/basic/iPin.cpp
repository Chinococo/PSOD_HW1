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
    // 檢查不要自己複製自己
    if (this != &other) {
        this->output = other.output;
    }
    return *this;
}
