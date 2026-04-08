//
// Created by Chino on 2026/4/9.
//

#include "gateAND.h"

#include "oPin.h"

vector<bool> gateAND::getOutput(){
    bool result = true;
    for (auto _iPin:this->iPins) {
        result = result && _iPin->getOutput()[0];
    }
    return {result};
}
