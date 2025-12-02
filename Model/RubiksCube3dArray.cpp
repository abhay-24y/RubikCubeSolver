//
// Created by Abhay on 01-12-2025.
//

#include "RubiksCube.h";

class RubiksCube3dArray : public RubiksCube {
private:
    void rotateFace(int ind) {
        // ind(index) face ko store kar rha hu temporary. Ex: 0 means front face;
        char temp_arr[3][3] = {};
        for (int i=0 ; i<3 ;i++) {
            for (int j=0 ; j<3 ;j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }

        //              0 1 2
        //            0 X X X
        //            1 X X X
        //            2 X X X

        // For making the 2nd row as the 0th column;
        for (int i = 0; i < 3; i++) cube[ind][i][0] = temp_arr[2][i];
        // for making the 0th col as 0th row.
        for (int i = 0; i < 3; i++) cube[ind][0][2 - i] = temp_arr[i][0];
        // for making the 0th row as the 2nd col.
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        // for making the 2nd column as the 2nd row.
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
    }

public:
    char cube[6][3][3];

    RubiksCube3dArray() {
        for (int i=0 ; i<6 ; i++) {
            for (int j=0 ; j<3 ; j++) {
                for (int k=0 ; k<3 ; k++) {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }


    RubiksCube &u() override {
        // This will rotate the upper face
        this->rotateFace(0);

        // Now we also have to take care of the other 4 face first row as they are changing;
        // First we store any one face 0th row (here we have save 4th face 0th row.)
        char temp_arr[3]={};
        for (int i=0 ; i<3 ;i++) temp_arr[i] = cube[4][0][i];
        // Copying 1st -> 4th face
        for (int i=0 ; i<3 ;i++) cube[4][0][i] = cube[1][0][i];
        // Copying 2nd -> 1st face
        for (int i=0 ; i<3 ;i++) cube[1][0][i] = cube[2][0][i];
        // Copying 3rd -> 2nd face
        for (int i=0 ; i<3 ;i++) cube[2][0][i] = cube[3][0][i];
        // Copying 4th -> 3rd face
        for (int i=0 ; i<3 ;i++) cube[3][0][i] = temp_arr[i];

        return *this;
    }

    RubiksCube &uPrime() override {
        // uPrime is same as doing three times u.
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

     RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCube3dArray &r1) const {
        for (int i=0 ;i<6 ; i++) {
            for (int j=0 ; j<3 ; j++) {
                for (int k=0 ; k<3 ; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }
    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3dArray &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};