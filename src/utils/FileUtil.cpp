#include "../include/utils/FileUtil.h"
#include <fstream>
#include <sstream>
#include <algorithm>
namespace utils {
    std::string readFile(const std::string& filePath) {
        std::ifstream ifs(filePath);
        if (!ifs.is_open()) {
            return "ERROR: File not found at " + filePath;
        }
        std::stringstream ss;
        ss << ifs.rdbuf();
        std::string content = ss.str();
        content.erase(std::remove(content.begin(), content.end(), '\r'), content.end());
        return content;
    }
}