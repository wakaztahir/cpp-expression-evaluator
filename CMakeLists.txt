cmake_minimum_required(VERSION 3.21)
project(parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(parser main.cpp utils/FileReader.h utils/FileReader.cpp expression/expression.h ast/AST.h)
