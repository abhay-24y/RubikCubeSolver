//
// Created by Abhay on 29-01-2026.
//

#ifndef RUBIKCUBESOLVER_CUBEINPUTUI_H
#define RUBIKCUBESOLVER_CUBEINPUTUI_H

#include <opencv2/opencv.hpp>

// Color order FIXED (must match solver)
enum COLOR {
    WHITE = 0,
    GREEN = 1,
    RED = 2,
    BLUE = 3,
    ORANGE = 4,
    YELLOW = 5,
    UNKNOWN = 6
};

// 🔹 EXPOSE cube to main.cpp
extern COLOR cube[6][3][3];

// 🔹 UI entry point
void runCubeInputUI();


#endif //RUBIKCUBESOLVER_CUBEINPUTUI_H