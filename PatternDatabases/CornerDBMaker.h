//
// Created by Abhay on 28-01-2026.
//

#ifndef RUBIKCUBESOLVER_CORNERDBMAKER_H
#define RUBIKCUBESOLVER_CORNERDBMAKER_H

#include "CornerPatternDatabase.h"
#include "../Model/RubiksCubeBitboard.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};


#endif //RUBIKCUBESOLVER_CORNERDBMAKER_H