#include <iostream>

#include "include/model/gates/gateAND.h"
#include "include/model/basic/iPin.h"
#include <gtest/gtest.h>

#include "control/LogicSimulator.h"

using namespace std;
int StartTest(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
int main(int argc, char **argv) {
   //return StartTest(argc,argv);
    LogicSimulator simulator;
    simulator.load("");
    std::cout<<simulator.getSimulationResult({new iPin(1),new iPin(1)})<<std::endl;

}