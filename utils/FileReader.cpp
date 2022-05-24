//
// Created by wakaztahir on 5/24/2022.
//

#include "FileReader.h"

namespace FileReader {

    std::vector<std::string>
    readFileLines(const char *filePath, const char *starting, const char *ending, bool skipEmptyLines) {
        std::ifstream myFile;
        myFile.open(filePath);
        std::vector<std::string> lines{};
        bool started = starting == nullptr;
        while (true) {
            std::string line;
            if (!getline(myFile, line)) break;
            if (!started) {
                if (starting == line) {
                    started = true;
                    continue;
                } else continue;
            }
            if (ending != nullptr && ending == line) break;
            if (skipEmptyLines && line.empty()) continue;
            lines.push_back(line);
        }
        myFile.close();;
        return lines;
    }

    std::string readFile(const char *filePath, const char *starting, const char *ending, bool skipEmptyLines) {
        std::ifstream myFile;
        myFile.open(filePath);
        std::string text;
        std::string line;
        bool started = starting == nullptr;
        while (getline(myFile, line)) {
            if (!started) {
                if (starting == line) {
                    started = true;
                    continue;
                } else continue;
            }
            if (ending != nullptr && ending == line) break;
            if (skipEmptyLines && line.empty()) continue;
            text += line + '\n';
            line.clear();
        }
        myFile.close();
        return text;
    }
}