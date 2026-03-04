//
// Created by Abhay on 27-01-2026.
//

#ifndef RUBIKCUBESOLVER_PATTERNDATABASE_H
#define RUBIKCUBESOLVER_PATTERNDATABASE_H

#include "../Model/RubiksCube.h"
#include "NibbleArray.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdint>


using namespace std;

/*
PatternDatabase :
-> database  → values
-> size      → capacity
-> numItems  → filled
*/

class PatternDatabase {
    NibbleArray database;
    size_t size;
    size_t numItems;

    // Private Constructor to prevent object creation without knowing size.
    PatternDatabase();

public:
    PatternDatabase(const size_t size);
    //    Testing for init_val
    PatternDatabase(const size_t size, uint8_t init_val);

    /* Given a cube, what is its index in the pattern database? */
    /* uint32_t can store up to ~4 billion */
    virtual uint32_t getDatabaseIndex(const RubiksCube &cube) const = 0;

    virtual bool setNumMoves(const RubiksCube &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const RubiksCube &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    /*
        size      → total capacity
        numItems  → filled entries
        isFull()  → numItems == size ?
    */
    virtual size_t getSize() const;
    virtual size_t getNumItems() const;
    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};


#endif //RUBIKCUBESOLVER_PATTERNDATABASE_H