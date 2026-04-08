cmake_minimum_required(VERSION 4.2)
project(PSOD_HW1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PSOD_HW1 main.cpp
        src/Model/Basic/Device.cpp
        include/Model/Basic/Device.h
        src/Model/Basic/oPin.cpp
        include/Model/Basic/oPin.h
        src/Model/Basic/iPin.cpp
        include/Model/Basic/iPin.h
        src/Model/Gates/gateAND.cpp
        include/Model/Gates/gateAND.h
        src/Model/Gates/gateNot.cpp
        include/Model/Gates/gateNot.h)
