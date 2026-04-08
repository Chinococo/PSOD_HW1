#include <iostream>

#include "include/model/gates/gateAND.h"
#include "include/model/basic/iPin.h"
#include <gtest/gtest.h>
using namespace std;
int StartTest(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
int main(int argc, char **argv) {
   return StartTest(argc,argv);
}