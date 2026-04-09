//
// Created by Chino on 2026/4/9.
//

#include "../../include/control/LogicSimulator.h"
#include <math.h>
#include "model/basic/oPin.h"
#include "model/gates/gateNot.h"
#include "model/basic/iPin.h"
#include "model/gates/gateAND.h"
#include <iostream>
std::string LogicSimulator::getSimulationResult(std::vector<Device*> _inputs) {
    for (size_t i = 0 ; i < iPins.size() ; i++) {
        iPin* targetPin = dynamic_cast<iPin*>(iPins[i]);
        iPin* sourcePin = dynamic_cast<iPin*>(_inputs[i]);

        if (targetPin && sourcePin) {
            *targetPin = *sourcePin; // 這樣才會正確呼叫 iPin 的 operator=
        }
    }
    bool evaluated[1001];
    memset(evaluated,false,sizeof(evaluated));
    for (size_t i = 0 ; i < circuit.size() ; i++) {
        try {
            if (!evaluated[i]) {
                circuit[i]->getOutput()[0];
                evaluated[i] = true;
            }
        }catch (std::exception& e) {

        }
    }
    return std::to_string(oPins[0]->getOutput()[0]);
}
std::string LogicSimulator::getTruthTable() {
    return "";
}
bool LogicSimulator::load(std::string path) {
    iPins.push_back(new iPin(0));
    iPins.push_back(new iPin(0));
    oPins.push_back(new oPin());
    circuit.push_back(new gateAND({iPins[0],iPins[1]}));  //0
    circuit.push_back(new gateNot(circuit[0])); //1
    circuit.push_back(new gateAND({iPins[0],circuit[1]}));//2
    circuit.push_back(new gateAND({iPins[1],circuit[1]}));//3
    circuit.push_back(new gateNot(circuit[2]));//4
    circuit.push_back(new gateNot(circuit[3]));//5
    circuit.push_back(new gateAND({circuit[4],circuit[5]}));//6
    circuit.push_back(new gateNot(circuit[6]));
    oPins[0] = circuit[7];
    return true;
}