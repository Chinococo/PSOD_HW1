//
// Created by Chino on 2026/4/9.
//

#include "../../../include/Model/Gates/gateAND.h"
#include "../../../include/Model/Basic/oPin.h"

vector<bool> gateAND::getOutput(){
    bool result = true;
    for (auto _iPin:this->iPins) {
        result = result && _iPin->getOutput()[0];
    }
    return {result};
}
