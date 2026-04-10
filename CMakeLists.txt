cmake_minimum_required(VERSION 3.14)
project(PSOD_HW1)

set(CMAKE_CXX_STANDARD 14)

# --- 1. Google Test 配置 ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- 2. 編譯旗標 (Coverage) ---
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# --- 3. 檔案分類 ---
# 排除 main.cpp 以外的所有原始碼（這是你的邏輯核心）
file(GLOB_RECURSE CORE_SRC "src/*.cpp")
# 取得測試檔案
file(GLOB_RECURSE TEST_FILES "test/*.cpp")

# --- 4. 目標一：手動模式執行檔 (App) ---
# 只包含 main.cpp 和核心邏輯，不包含測試檔案
add_executable(logic_simulator_app main.cpp ${CORE_SRC})
target_include_directories(logic_simulator_app PRIVATE include)

# --- 5. 目標二：自動測試執行檔 (Tests) ---
# 包含核心邏輯和測試檔案，但不包含手動模式的 main.cpp
add_executable(logic_simulator_test ${CORE_SRC} ${TEST_FILES})
target_include_directories(logic_simulator_test PRIVATE include)
target_link_libraries(logic_simulator_test PRIVATE gtest_main)

# --- 6. 測試相關設定 ---
enable_testing()
include(GoogleTest)
gtest_discover_tests(logic_simulator_test)

# 複製靜態檔案到執行目錄
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/static DESTINATION ${CMAKE_CURRENT_BINARY_DIR})