cmake_minimum_required(VERSION 3.14)
project(PSOD_HW1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- 1. Google Test 配置 ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- 2. 尋找 Clang-Tidy (先不要全域套用) ---
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "Found clang-tidy: ${CLANG_TIDY_EXE}")
    # 定義一套實用的規則，過濾掉不必要的檢查
    set(MY_CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE};-checks=-*,bugprone-*,modernize-*,readability-*;--warnings-as-errors=*")
else()
    message(WARNING "clang-tidy not found!")
endif()

# --- 3. 編譯旗標 (Coverage) ---
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# --- 4. 檔案分類 (加入 CONFIGURE_DEPENDS 以追蹤檔案新增/刪除) ---
file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS "test/*.cpp")

# --- 5. 目標一：手動模式執行檔 (App) ---
add_executable(logic_simulator_app main.cpp ${CORE_SRC})
target_include_directories(logic_simulator_app PRIVATE include)

# 僅對自己的目標綁定 Clang-Tidy
if(CLANG_TIDY_EXE)
    set_target_properties(logic_simulator_app PROPERTIES CXX_CLANG_TIDY "${MY_CLANG_TIDY_COMMAND}")
endif()

# --- 6. 目標二：自動測試執行檔 (Tests) ---
add_executable(logic_simulator_test ${CORE_SRC} ${TEST_FILES})
target_include_directories(logic_simulator_test PRIVATE include)
target_link_libraries(logic_simulator_test PRIVATE gtest_main)


# --- 7. 測試相關設定 ---
enable_testing()
include(GoogleTest)
gtest_discover_tests(logic_simulator_test)

# 複製靜態檔案到執行目錄
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/static DESTINATION ${CMAKE_CURRENT_BINARY_DIR})