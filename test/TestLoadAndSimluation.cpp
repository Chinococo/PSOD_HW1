#include "control/LogicSimulator.h"
#include <gtest/gtest.h>

#include "model/basic/iPin.h"

TEST(GateTest, TestLoadXorSimulation) {
    LogicSimulator simulator;
    simulator.load("static/xor.lcf");

    EXPECT_EQ(simulator.getSimulationResult({new iPin(0),new iPin(0)}), "0");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(0),new iPin(1)}), "1");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(1),new iPin(0)}), "1");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(1),new iPin(1)}), "0");
}
TEST(GateTest, TestLoadExample1Simulation) {
    LogicSimulator simulator;
    simulator.load("static/example.lcf");

    EXPECT_EQ(simulator.getSimulationResult({new iPin(0), new iPin(0), new iPin(0)}), "0");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(0), new iPin(0), new iPin(1)}), "0");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(0), new iPin(1), new iPin(0)}), "0");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(0), new iPin(1), new iPin(1)}), "0");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(1), new iPin(0), new iPin(0)}), "1");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(1), new iPin(0), new iPin(1)}), "1");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(1), new iPin(1), new iPin(0)}), "0");
    EXPECT_EQ(simulator.getSimulationResult({new iPin(1), new iPin(1), new iPin(1)}), "0");

}
TEST(GateTest, TestLoadBroken) {
    LogicSimulator simulator;
    EXPECT_THROW(simulator.load("static/illegal1.lcf"), std::invalid_argument);
    EXPECT_THROW(simulator.load("static/illegal2.lcf"), std::invalid_argument);

}
TEST(GateTest, TestFileIsNotExist) {
    LogicSimulator simulator;
    EXPECT_EQ(simulator.load("static/fuck.lcf"), false);
}