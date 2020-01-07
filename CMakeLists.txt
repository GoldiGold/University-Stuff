cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(Advanced1_HW3
        Command.h
        ConnectClientCommand.h
        ConnectClientCommand.cpp
        DefineVarCommand.h
        DefineVarCommand.cpp
        Lexer.h
        Lexer.cpp
        main.cpp
        OpenServerCommand.h
        OpenServerCommand.cpp
        ProgVar.h
        ProgVar.cpp
        ServerSymbolTable.h
        ServerSymbolTable.cpp
        SymbolTable.h
        SymbolTable.cpp)