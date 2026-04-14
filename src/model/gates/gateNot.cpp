#include "../../../include/model/gates/gateNot.h"
#include <system_error>

std::vector<bool> gateNot::getOutput() {
    // 輸入不足
    if (this->iPins.empty())
        throw std::invalid_argument("AndGate doesn't have input signal");

    try {
        const bool result = !this->iPins[0]->getOutput()[0];
        return std::vector<bool>{result};
    } catch (std::invalid_argument &) {
        throw std::invalid_argument("AndGate can't simulation");
    }
}
