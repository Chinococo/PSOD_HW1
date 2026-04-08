cmake_minimum_required(VERSION 4.2)
project(PSOD_HW1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PSOD_HW1 main.cpp
        Model/Device.cpp
        Model/Device.h
        Model/oPin.cpp
        Model/oPin.h
        Model/iPin.cpp
        Model/iPin.h
        Model/gateAND.cpp
        Model/gateAND.h)
