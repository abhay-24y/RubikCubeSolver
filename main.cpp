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

  #include "Model/RubiksCube3dArray.cpp"
  // #include "Model/RubiksCube1dArray.cpp"
// #include "../RubikCubeSolver/Solver/DFSSolver.h"
// #include "../RubikCubeSolver/Solver/BFSSolver.h"
// #include "../RubikCubeSolver/Solver/IDDFSSolver.h"
#include "../RubikCubeSolver/Solver/IDAstarSolver.h"
// #include "PatternDatabases/CornerDBMaker.h"
//#include "PatternDatabases/CornerPatternDatabase.h"
#include "Model/RubiksCubeBitboard.cpp"

#include <opencv2/opencv.hpp>

#include "Input/CubeInputUI.h"

using namespace std;

int main() {
                                     // Testing Phase :

    // ------------------------------DFS Solver Testing ________________________________________________________________
    // RubiksCube1dArray cube;
    // cube.print();
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // DFSSolver<RubiksCube1dArray, Hash1d> dfsSolver(cube, 8);
    // vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // dfsSolver.rubiksCube.print();
    //------------------------------------------------------------------------------------------------------------------

    //-------------------------------BFS Solver Testing-----------------------------------------------------------------
    // RubiksCube3dArray cube;
    // cube.print();
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(4);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // BFSSolver<RubiksCube3dArray,Hash3d> bfsSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();


    //----------------------------IDDFS Solver Testing------------------------------------------------------------------
    // RubiksCubeBitboard cube;
//     cube.print();
//     vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//     for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//     cout << "\n";
//     cube.print();
//
//     IDDFSSolver<RubiksCube3dArray,Hash3d> iddfsSolver(cube,7);
//     vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
//     for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//     cout << "\n";
//     iddfsSolver.rubiksCube.print();
//     return 0;
//
    // CornerDBMaker Testing --------------------------------------------------------------------------
    string fileName = "C:\\Users\\Abhay\\CLionProjects\\RubikCubeSolver\\Databases\\cornerDepth5V1.txt";

    //    Code to create Corner Database
    // CornerDBMaker dbMaker(fileName, 0x99);
    // dbMaker.bfsAndStore();

    // RubiksCubeBitboard cube;
    // auto shuffleMoves = cube.randomShuffleCube(13);
    // cube.print();
    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    //
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    // auto moves = idaStarSolver.solve();
    //
    // idaStarSolver.rubiksCube.print();
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";


    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube, fileName);
    // auto solve_moves = idAstarSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // idAstarSolver.rubiksCube.print();


    // runCubeInputUI();
    // RubiksCubeBitboard cubeModel;
    //
    // for(int face = 0; face < 6; face++) {
    //     for(int i = 0; i < 3; i++) {
    //         for(int j = 0; j < 3; j++) {
    //             cubeModel.setColor(
    //                 static_cast<RubiksCube::FACE>(face),
    //                 i, j,
    //                 static_cast<RubiksCube::COLOR>(cube[face][i][j])
    //             );
    //         }
    //     }
    // }
    //
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> solver(cubeModel,fileName);
    // auto solve_moves = solver.solve();
    //
    // for (auto move: solve_moves) cout << cubeModel.getMove(move) << " ";
    // cout << "\n";
    // solver.rubiksCube.print();
    //


    return 0;

}