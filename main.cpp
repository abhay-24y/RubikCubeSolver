#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "../RubikCubeSolver/Solver/DFSSolver.h"
#include "../RubikCubeSolver/Solver/BFSSolver.h"
#include "../RubikCubeSolver/Solver/IDDFSSolver.h"

using namespace std;

int main() {
                                     // Testing Phase :

    // ------------------------------DFS Solver Testing ________________________________________________________________
    // RubiksCube3dArray cube;
    // cube.print();
    // cube.b2();
    // cube.b();
    // cube.l2();
    // cube.lPrime();
    // cube.b2();
    // cube.b2();
    // // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
    // vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // dfsSolver.rubiksCube.print();
    //------------------------------------------------------------------------------------------------------------------

    //-------------------------------BFS Solver Testing-----------------------------------------------------------------
    // RubiksCube3dArray cube;
    // cube.print();
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
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
    RubiksCube3dArray cube;
    cube.print();
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    IDDFSSolver<RubiksCube3dArray,Hash3d> iddfsSolver(cube,7);
    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubiksCube.print();
    return 0;
}