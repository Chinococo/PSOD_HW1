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
#include <fstream>

#include "model/gates/gateOR.h"

std::string LogicSimulator::getSimulationResult(std::vector<Device *> _inputs) {
    for (size_t i = 0; i < iPins.size(); i++) {
        iPin *targetPin = dynamic_cast<iPin *>(iPins[i]);
        iPin *sourcePin = dynamic_cast<iPin *>(_inputs[i]);
        if (targetPin && sourcePin) {
            *targetPin = *sourcePin;
        }
    }
    bool evaluated[1001];
    int count = 0;
    memset(evaluated, false, sizeof(evaluated));
    do {
        for (size_t i = 0; i < circuit.size(); i++) {
            try {
                if (!evaluated[i]) {
                    circuit[i]->getOutput()[0];
                    evaluated[i] = true;
                    count++;
                }
            } catch (std::exception &e) {
            }
        }
    } while (count < circuit.size());


    return std::to_string(oPins[0]->getOutput()[0]);
}

std::string LogicSimulator::getTruthTable() {
    return "";
}

bool LogicSimulator::load(std::string path) {
    std::ifstream inFile;
    inFile.open(path, std::ios::in);
    if (inFile) {
        int NI, NG;
        if (inFile >> NI >> NG) {
            for (int i = 0; i < NI; i++)
                iPins.push_back(new iPin(0));
            std::vector<double> pins;
            for (int i = 0; i < NG; ++i) {
                int gateType;
                double pin;
                inFile >> gateType; // 讀取邏輯閘種類 (1: AND, 2: OR, 3: NOT)
                if (gateType == 1)
                    circuit.emplace_back(new gateAND());

                else if (gateType == 2)
                    circuit.emplace_back(new gateOR());
                else {
                    circuit.emplace_back(new gateNot());
                }
                while (inFile >> pin && pin != 0)
                    pins.push_back(pin);
                pins.push_back(0);
            }
            oPins.push_back(circuit[NG-1]);

            for (int i=0,circuit_index=0;i<pins.size();i++) {
                if (pins[i])
                    if (abs(pins[i]) == floor(abs(pins[i]))) {
                        int index = (int) floor(abs(pins[i]));
                        circuit[circuit_index]->addInputPin(iPins[index - 1]); //要減1是因為他從1開始
                    } else {
                        int index = (int) floor(abs(pins[i]));
                        circuit[circuit_index]->addInputPin(circuit[index - 1]); //要減1是因為他從1開始
                    }
                else
                    circuit_index ++;
            }
        }
        inFile.close();
        return false;
    }
    return false;
}
