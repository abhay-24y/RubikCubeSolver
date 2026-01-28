//
// Created by Abhay on 28-01-2026.
//

#ifndef RUBIKCUBESOLVER_CORNERPATTERNDATABASE_H
#define RUBIKCUBESOLVER_CORNERPATTERNDATABASE_H

#include "../Model/RubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef RubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;

};


#endif //RUBIKCUBESOLVER_CORNERPATTERNDATABASE_H