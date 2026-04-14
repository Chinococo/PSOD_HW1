#include "../../../include/model/gates/gateOR.h"
#include <system_error>

std::vector<bool> gateOR::getOutput(){
    // 輸入不足
    if (this->iPins.size() <  2)
        throw std::invalid_argument("AndGate doesn't have enough input signal");
    bool result = false;
    try {
        for (const auto _iPin:this->iPins) {
            const bool output = _iPin->getOutput()[0];
            result = result || output;
        }
    }catch(std::invalid_argument&) {
        throw std::invalid_argument("AndGate can't simulation");
    }
    return {result};
}
