cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Advanced1_HW3 main.cpp Command.h ConnectClientCommand.h ConnectClientCommand.cpp Lexer.cpp OpenServerCommand.h OpenServerCommand.cpp ProgVar.cpp ServerSymbolTable.h ServerSymbolTable.cpp SymbolTable.cpp DefineVarCommand.h DefineVarCommand.cpp SymbolTable.h)