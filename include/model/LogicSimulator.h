//
// Created by Chino on 2026/4/9.
//

#ifndef PSOD_HW1_LOGICSIMULATOR_H
#define PSOD_HW1_LOGICSIMULATOR_H
#include "model/basic/Device.h"
#include <string.h>


class LogicSimulator {
public:
    std::vector<Device *> circuit;
    std::vector<Device *> iPins;
    std::vector<Device *> oPins;

    std::string getSimulationResult(std::vector<Device*>);
    std::string getTruthTable();
    bool load(std::string);
};


#endif //PSOD_HW1_LOGICSIMULATOR_H
