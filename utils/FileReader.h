//
// Created by wakaztahir on 5/24/2022.
//

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

namespace FileReader {
    std::vector<std::string>
    readFileLines(const char *filePath, const char *starting = nullptr, const char *ending = nullptr,
                  bool skipEmptyLines = false);

    std::string readFile(const char *filePath, const char *starting = nullptr, const char *ending = nullptr,
                         bool skipEmptyLines = false);
}