//
// Created by Chino on 2026/4/10.
//

#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <string>

namespace utils {
    // 獨立函式，不屬於任何類別
    std::string readFile(const std::string& filePath);
}

#endif