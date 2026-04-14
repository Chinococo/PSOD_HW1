#ifndef PSOD_HW1_LOGIC_SIMULATOR_H
#define PSOD_HW1_LOGIC_SIMULATOR_H
#include "model/basic/Device.h"
#include <string>
#include <ostream>

class LogicSimulator {
    std::vector<Device *> circuit;
    std::vector<Device *> iPins;
    std::vector<Device *> oPins;

public:
    ~LogicSimulator();
    [[nodiscard]] std::string getSimulationResult(const std::vector<Device*> &_inputs) const;
    [[nodiscard]] std::string getTruthTable() const;
    [[nodiscard]] std::string getHeader() const;
    bool load(const std::string& path);

    // 重載output stream
    friend std::ostream& operator<<(std::ostream& os, const LogicSimulator& ls);
    // 內部參數的Getter
    [[nodiscard]] size_t getCircuitSize() const { return circuit.size(); }
    [[nodiscard]] size_t getIPinSize() const { return iPins.size(); }
    [[nodiscard]] size_t getOPinSize() const { return oPins.size(); }
};


#endif //PSOD_HW1_LOGIC_SIMULATOR_H
