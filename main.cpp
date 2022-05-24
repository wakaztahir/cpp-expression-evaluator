#include <iostream>
#include "utils/FileReader.h"
#include "expression/expression.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "arguments don't include an input & output file";
    }

    auto input = argv[1];
    auto output = argv[1];

    auto expressions = FileReader::readFileLines(input, nullptr, "#end", true);
    auto answers = FileReader::readFileLines(input, "#end", nullptr, true);

    for (int i = 0; i < expressions.size(); i++) {
        auto str = expressions[i];
        char *ca = new char[str.size() + 1];
        std::copy(str.begin(), str.end(), ca);
        ca[str.size()] = '\0';
        // print all the numbers in equation
//        while (*ca != '\0') {
//            if (*ca >= '0' && *ca <= '9') {
//                std::cout << Expression::getDouble(ca) << ",";
//            }
//            ca++;
//        }
        std::cout << std::endl;
        std::cout << str << " = " << Expression::evaluate(ca) << " ; expected = " << answers[i] << std::endl;
    }

    return 0;
}

