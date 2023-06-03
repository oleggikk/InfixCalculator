cmake_minimum_required(VERSION 3.23)
project(InfixCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(InfixCalculator main.cpp Node.cpp Node.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h InfixToPostfixConverter.cpp InfixToPostfixConverter.h Calculator.cpp Calculator.h)
