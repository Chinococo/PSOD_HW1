#include "../../../include/model/basic/oPin.h"
#include <system_error>

oPin::oPin(Device *_input) {
    this->output = {_input};
}

std::vector<bool> oPin::getOutput() {
    // 輸入不足
    if (output.empty()) {
        throw std::invalid_argument("Doesn't have output signal");
    }
    return this->output[0]->getOutput();
}
