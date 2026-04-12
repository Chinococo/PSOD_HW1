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


std::ostream& operator<<(std::ostream& os, const LogicSimulator& ls) {
    os << "Circuit: "
       << ls.iPins.size() << " input pins, "
       << ls.oPins.size() << " output pins and "
       << ls.circuit.size() << " gates";
    return os; // 務必回傳 os 才能支援鏈式呼叫 (如 cout << a << b;)
}

std::string LogicSimulator::getSimulationResult(const std::vector<Device *> &_inputs) const{
    for (size_t i = 0; i < iPins.size(); i++) {
        iPin *targetPin = dynamic_cast<iPin *>(iPins[i]);
        iPin *sourcePin = dynamic_cast<iPin *>(_inputs[i]);
        if (targetPin && sourcePin) {
            *targetPin = *sourcePin;
        }
    }
    std::string result;

    // 1. 產生表頭
    for (size_t i = 0; i < iPins.size(); i++) {
        result+="i ";
    }
    result+="| o\n";
    for (size_t i = 0; i < iPins.size(); i++) {
        result+=std::to_string(i+1)+" ";
    }
    result+="| 1\n";

    // 2. 產生分隔線 (例如: -----------)
    for (int i = 0; i < iPins.size() * 2 + 3; ++i) {
        if (i==iPins.size() * 2)
            result+="+";
        else
            result += "-";
    }
    result += "\n";
    // 3. 產生數值行 (例如: 0 1 1 | 0)
    for (const auto iPin : iPins) {
        // 取得每個輸入 pin 的目前狀態
        result += std::to_string(iPin->getOutput()[0]) + " ";
    }

    result += "| ";

    // 取得第一個輸出 pin 的結果
    if (!oPins.empty()) {
        result += std::to_string(oPins[0]->getOutput()[0]);
    }

    return result;
}

std::string LogicSimulator::getTruthTable() const{
    std::string truthTable;

    // 1. 產生表頭
    for (size_t i = 0; i < iPins.size(); i++) {
        truthTable+="i ";
    }
    truthTable+="| o\n";
    for (size_t i = 0; i < iPins.size(); i++) {
        truthTable+=std::to_string(i+1)+" ";
    }
    truthTable+="| 1\n";

    // 2. 產生分隔線 (例如: -----------)
    for (int i = 0; i < iPins.size() * 2 + 3; ++i) {
        if (i==iPins.size() * 2)
            truthTable+="+";
        else
            truthTable += "-";
    }
    truthTable += "\n";

    // 3. 遍歷所有組合
    for (int i = 0; i < std::pow(2,iPins.size()); ++i) {
        std::vector<Device *> currentInputs;

        // 將整數 i 轉為二進制位元，填入 currentInputs
        // 假設從最高位開始填，例如 i=1, numInputs=2 => 0, 1
        for (int j = static_cast<int>(iPins.size()) - 1; j >= 0; --j) {
            const int bit = (i >> j) & 1;
            currentInputs.push_back(new iPin(bit));
            truthTable += std::to_string(bit) + " ";
        }
        // 4. 呼叫你的模擬邏輯並取得結果
        std::string result = getSimulationResult(currentInputs);
        for (Device* ptr : currentInputs) {
            delete ptr;
        }
        truthTable += "| " + std::to_string(oPins[0]->getOutput()[0]);
        if (i!=std::pow(2,iPins.size())-1)
            truthTable+="\n";
    }

    return truthTable;
}

bool LogicSimulator::load(const std::string& path) {
    /*Init local variable*/
    for (Device* d : circuit) delete d;
    for (Device* d : iPins) delete d;
    for (Device* d : oPins) delete d;
    circuit.clear();
    iPins.clear();
    oPins.clear();

    std::ifstream inFile;
    inFile.open(path, std::ios::in);
    if (inFile) {
        int NI, NG;
        if (inFile >> NI >> NG) {
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
            // 所有輸出可能性
            std::set<int> possible;
            for (int i = 0; i < circuit.size(); i++)
                possible.insert(i);
            for (int i = 0, circuit_index = 0; i < pins.size(); i++) {
                if (static_cast<int>(pins[i]))
                    if (std::abs(pins[i]) == floor(std::abs(pins[i]))) {
                        const int index = static_cast<int>(floor(std::abs(pins[i])));
                        if (index-1 >= iPins.size())
                            throw std::invalid_argument("Wrong Input index");
                        circuit[circuit_index]->addInputPin(iPins[index - 1]); //要減1是因為他從1開始
                    } else {
                        const int index = static_cast<int>(floor(std::abs(pins[i])));
                        if (index-1 >= circuit.size())
                            throw std::invalid_argument("Wrong Circuit Output index");
                        circuit[circuit_index]->addInputPin(circuit[index - 1]); //要減1是因為他從1開始
                        // 他不可能是輸出
                        possible.erase(index - 1);
                    }
                else
                    circuit_index++;
            }
            // 題目規定只有一個 可擴充
            oPins.push_back(new oPin(circuit[*possible.begin()]));
        }
        inFile.close();
        return true;
    }
    return false;
}

LogicSimulator::~LogicSimulator() {
    for (Device* d : circuit) {
        delete d;
    }
    for (Device* d : iPins) {
        delete d;
    }
    for (Device* d : oPins) {
        delete d;
    }

}
