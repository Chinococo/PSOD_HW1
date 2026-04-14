//
// Created by Chino on 2026/4/9.
//

#include "../../include/model/LogicSimulator.h"
#include <cmath>
#include "model/basic/oPin.h"
#include "model/gates/gateNot.h"
#include "model/basic/iPin.h"
#include "model/gates/gateAND.h"
#include <iostream>
#include <fstream>

#include "model/gates/gateOR.h"
#include <set>


std::ostream &operator<<(std::ostream &os, const LogicSimulator &ls) {
    os << "Circuit: "
            << ls.iPins.size() << " input pins, "
            << ls.oPins.size() << " output pins and "
            << ls.circuit.size() << " gates";
    return os;
}

std::string LogicSimulator::getHeader() const {
    std::string result;

    // 產生表頭
    for (size_t i = 0; i < iPins.size(); i++) {
        result += "i ";
    }
    result += "|";
    for (size_t i = 0; i < oPins.size(); i++) {
        result += " o";
    }
    result += "\n";
    for (size_t i = 0; i < iPins.size(); i++) {
        result += std::to_string(i + 1) + " ";
    }
    result += "|";
    for (size_t i = 0; i < oPins.size(); i++) {
        result += " " + std::to_string(i + 1);
    }
    result += "\n";
    for (int i = 0; i < (iPins.size() + oPins.size()) * 2 + 1; ++i) {
        if (i == iPins.size() * 2)
            result += "+";
        else
            result += "-";
    }
    return result;
}

std::string LogicSimulator::getSimulationResult(const std::vector<Device *> &_inputs) const {
    for (size_t i = 0; i < iPins.size(); i++) {
        const auto targetPin = dynamic_cast<iPin *>(iPins[i]);
        if (const iPin *sourcePin = dynamic_cast<iPin *>(_inputs[i]); targetPin && sourcePin) {
            *targetPin = *sourcePin;
        }
    }
    std::string result = this->getHeader() + "\n";

    // 寫上輸入
    for (const auto iPin: iPins) {
        result += std::to_string(iPin->getOutput()[0]) + " ";
    }

    result += "|";
    // 寫上輸出
    if (!oPins.empty()) {
        for (const auto oPin: oPins) {
            result += " " + std::to_string(oPin->getOutput()[0]);
        }
    }

    return result;
}


std::string LogicSimulator::getTruthTable() const {
    std::string truthTable = getHeader() + "\n";

    for (int i = 0; i < std::pow(2, iPins.size()); ++i) {
        std::vector<Device *> currentInputs;
        for (int j = static_cast<int>(iPins.size()) - 1; j >= 0; --j) {
            const int bit = (i >> j) & 1;
            currentInputs.push_back(new iPin(bit));
            truthTable += std::to_string(bit) + " ";
        }
        std::string result = getSimulationResult(currentInputs);

        //回收產生的臨時記憶體
        for (const Device *ptr: currentInputs) {
            delete ptr;
        }
        truthTable += "|" ;
        if (!oPins.empty()) {
            for (const auto oPin: oPins) {
                truthTable += " " + std::to_string(oPin->getOutput()[0]);
            }
        }
        if (i != std::pow(2, iPins.size()) - 1)
            truthTable += "\n";
    }

    return truthTable;
}

bool LogicSimulator::load(const std::string &path) {
    // 重新載入時要清除所有電路以及輸入輸出
    for (Device *d: circuit) delete d;
    for (Device *d: iPins) delete d;
    for (Device *d: oPins) delete d;
    circuit.clear();
    iPins.clear();
    oPins.clear();

    std::ifstream inFile;
    inFile.open(path, std::ios::in);
    if (inFile) {
        if (int NI,NG; inFile >> NI >> NG) {
            for (int i = 0; i < NI; i++)
                iPins.push_back(new iPin(false));
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
            // 所有輸出可能性 以便找出所有沒有輸出引腳接出的邏輯
            std::set<int> possible;
            for (int i = 0; i < circuit.size(); i++)
                possible.insert(i);

            for (int i = 0, circuit_index = 0; i < pins.size(); i++) {
                if (static_cast<int>(pins[i]))
                    if (std::abs(pins[i]) == floor(std::abs(pins[i]))) {
                        const int index = static_cast<int>(floor(std::abs(pins[i])));
                        if (index - 1 >= iPins.size())
                            throw std::invalid_argument("Wrong Input index");
                        circuit[circuit_index]->addInputPin(iPins[index - 1]); //要減1是因為他從1開始
                    } else {
                        const int index = static_cast<int>(floor(std::abs(pins[i])));
                        if (index - 1 >= circuit.size())
                            throw std::invalid_argument("Wrong Circuit Output index");
                        circuit[circuit_index]->addInputPin(circuit[index - 1]); //要減1是因為他從1開始
                        // 他不可能是輸出
                        possible.erase(index - 1);
                    }
                else
                    circuit_index++;
            }
            for (auto poss: possible) {
                oPins.push_back(new oPin(circuit[poss]));
            }
        }
        inFile.close();
        return true;
    }
    return false;
}

LogicSimulator::~LogicSimulator() {
    for (const Device *d: circuit) {
        delete d;
    }
    for (const Device *d: iPins) {
        delete d;
    }
    for (const Device *d: oPins) {
        delete d;
    }
}
