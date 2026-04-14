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
        // 清除linux讀取window檔案造成的 \r 問題
        content.erase(std::remove(content.begin(), content.end(), '\r'), content.end());
        return content;
    }
}