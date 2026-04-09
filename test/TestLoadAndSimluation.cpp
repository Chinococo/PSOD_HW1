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