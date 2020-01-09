cmake_minimum_required(VERSION 3.15)
project(Advanced1_HW3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")


add_executable(Advanced1_HW3
        Command.h
        Condition.h
        Condition.cpp
        ConnectClientCommand.h
        ConnectClientCommand.cpp
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
        SymbolTable.cpp
        DefineVarLeftCommand.cpp
        DefineVarLeftCommand.h
        DefineVarRightCommand.cpp
        DefineVarRightCommand.h
        ex1.h
        ex1.cpp
        Expression.h
        SingletonObj.cpp
        SingletonObj.h
        DefineVarEqCommand.cpp
        DefineVarEqCommand.h
        IfCommand.h
        IfCommand.cpp
        WhileCommand.h
        WhileCommand.cpp
        SleepCommand.h
        SleepCommand.cpp
        PrintCommand.h
        PrintCommand.cpp
        PutCommand.h
        PutCommand.cpp
        Parser.h
        Parser.cpp)