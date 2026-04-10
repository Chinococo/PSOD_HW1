//
// Created by Chino on 2026/4/10.
//

#include "../../include/view/TextUI.h"


void TextUI::displayMenu() {
    std::cout << "\n1. Load logic circuit file" << std::endl;
    std::cout << "2. Simulation" << std::endl;
    std::cout << "3. Display truth table" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Command: ";
}

bool TextUI::isFinish() {
    return isFinished;
}

void TextUI::processCommand() {
    std::string command;
    std::cin >> command;

    if (command == "1") {
        std::string filePath;
        std::cout << "Please key in a file path: ";
        std::cin >> filePath;
        try {
            if (logic_simulator.load(filePath)) {
                std::cout << "Circuit: "
                    << logic_simulator.iPins.size() << " input pins, "
                    << logic_simulator.oPins.size() << " output pins and "
                    << logic_simulator.circuit.size() << " gates\n";
                isLoad = true;
            }else {
                std::cout << "File not found or file format error!!" << std::endl;
            }

        } catch (const std::invalid_argument &e) {
            std::cout << "File not found or file format error!!" << std::endl;
            isLoad = false;
        }
    }
    else if (command == "2") {
        if (!isLoad) {
            std::cout << "Pleas load an lcf file, before using this operation." << std::endl;
            return;
        }
        std::vector<Device *> inputValues;
        // 要求使用者輸入每一個 pin 的值
        for (size_t i = 0; i < logic_simulator.iPins.size(); ++i) {
            std::string val;
            while (true) {
                std::cout << "Please key in the value of input pin " << (i + 1) << ": ";
                std::cin >> val;

                if (val != "0" && val != "1") {
                    std::cout << "The value of input pin must be 0/1\n";
                    continue;
                }

                inputValues.push_back(new iPin(std::stoi(val)));
                break;
            }
        }
        std::cout << "Simulation Result:\n" << logic_simulator.getSimulationResult(inputValues) << std::endl;
    } else if (command == "3") {
        if (!isLoad) {
            std::cout << "Please load an lcf file, before using this operation." << std::endl;
            return;
        }
        std::cout << "Truth table:\n" << logic_simulator.getTruthTable() << std::endl;
    } else if (command == "4") {
        std::cout << "Goodbye, thanks for using LS." << std::endl;
        isFinished = true;
    } else {
        std::cout << "Invalid command." << std::endl;
    }
}
