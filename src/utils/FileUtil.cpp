//
// Created by Chino on 2026/4/10.
//
#include "../include/utils/FileUtil.h"
#include <fstream>
#include <sstream>

namespace utils {
    std::string readFile(const std::string& filePath) {
        std::ifstream ifs(filePath);
        if (!ifs.is_open()) {
            return "ERROR: File not found at " + filePath;
        }
        std::stringstream ss;
        ss << ifs.rdbuf();
        return ss.str();
    }
}