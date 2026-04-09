cmake_minimum_required(VERSION 3.14)
project(PSOD_HW1)

set(CMAKE_CXX_STANDARD 14)

# --- 1. Google Test (FetchContent) ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- 2. Gcov Coverage Report ---
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()


file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HDR_FILES "include/*.h")
file(GLOB_RECURSE TEST_FILES "test/*.cpp")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/static DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(PSOD_HW1 main.cpp ${SRC_FILES} ${TEST_FILES} ${HDR_FILES})

target_include_directories(PSOD_HW1 PRIVATE include)

target_link_libraries(PSOD_HW1 PRIVATE gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PSOD_HW1)
