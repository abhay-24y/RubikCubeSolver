cmake_minimum_required(VERSION 4.0)
project(RubikCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubikCubeSolver main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h)
