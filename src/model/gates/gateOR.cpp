//
// Created by Chino on 2026/4/9.
//

#include "../../../include/model/gates/gateOR.h"
std::vector<bool> gateOR::getOutput(){

    if (this->iPins.size() <  2)
        throw std::invalid_argument("AndGate doesn't have enough input signal");
    bool result = false;
    try {
        for (auto _iPin:this->iPins) {
            result = result || _iPin->getOutput()[0];
        }
    }catch(std::invalid_argument& e) {
        throw std::invalid_argument("AndGate can't simulation");
    }
    return {result};
}
