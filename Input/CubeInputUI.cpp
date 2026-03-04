//
// Created by Abhay on 29-01-2026.
//

#include "CubeInputUI.h"

#include <map>
using namespace cv;
using namespace std;

static const int BOX = 60;
static const int GAP = 5;

COLOR cube[6][3][3];

static COLOR selectedColor = UNKNOWN;

static map<COLOR, Scalar> colorMap = {
    {WHITE,  Scalar(255,255,255)},
    {GREEN,  Scalar(0,255,0)},
    {RED,    Scalar(0,0,255)},
    {BLUE,   Scalar(255,0,0)},
    {ORANGE, Scalar(0,165,255)},
    {YELLOW, Scalar(0,255,255)},
    {UNKNOWN,Scalar(40,40,40)}
};

// Face layout (DO NOT CHANGE)
static Point facePos[6] = {
    {3*BOX, 0},        // WHITE (TOP)
    {0, 3*BOX},        // GREEN (LEFT)
    {3*BOX, 3*BOX},    // RED (FRONT)
    {6*BOX, 3*BOX},    // BLUE (RIGHT)
    {9*BOX, 3*BOX},    // ORANGE (BACK)
    {3*BOX, 6*BOX}     // YELLOW (BOTTOM)
};

static void initCube() {
    for(int f=0; f<6; f++)
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cube[f][i][j] = UNKNOWN;

    // lock centers
    cube[0][1][1] = WHITE;
    cube[1][1][1] = GREEN;
    cube[2][1][1] = RED;
    cube[3][1][1] = BLUE;
    cube[4][1][1] = ORANGE;
    cube[5][1][1] = YELLOW;
}

static void onMouse(int event, int x, int y, int, void*) {
    if(event != EVENT_LBUTTONDOWN) return;

    // palette click
    int py = 9*BOX + 10;
    for(int i=0;i<6;i++) {
        Rect p(10 + i*(BOX+10), py, BOX, BOX);
        if(p.contains(Point(x,y))) {
            selectedColor = (COLOR)i;
            return;
        }
    }

    // cube click
    for(int f=0; f<6; f++) {
        Rect face(facePos[f], Size(3*BOX, 3*BOX));
        if(face.contains(Point(x,y))) {
            int col = (x - facePos[f].x) / BOX;
            int row = (y - facePos[f].y) / BOX;

            if(row==1 && col==1) return; // center locked
            if(selectedColor != UNKNOWN)
                cube[f][row][col] = selectedColor;
        }
    }
}

static void drawCube(Mat &img) {
    img = Mat(9*BOX + 100, 12*BOX, CV_8UC3, Scalar(30,30,30));

    for(int f=0; f<6; f++)
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++) {
                Rect r(
                    facePos[f].x + j*BOX,
                    facePos[f].y + i*BOX,
                    BOX-GAP, BOX-GAP
                );
                rectangle(img, r, colorMap[cube[f][i][j]], FILLED);
                rectangle(img, r, Scalar(0,0,0), 2);
            }
}

static void drawPalette(Mat &img) {
    int y = 9*BOX + 10;
    for(int i=0;i<6;i++) {
        Rect r(10 + i*(BOX+10), y, BOX, BOX);
        rectangle(img, r, colorMap[(COLOR)i], FILLED);
        rectangle(img, r, Scalar(0,0,0), 2);
    }
}

void runCubeInputUI() {
    initCube();
    Mat img;

    namedWindow("Cube Input");
    setMouseCallback("Cube Input", onMouse);

    while(true) {
        drawCube(img);
        drawPalette(img);
        imshow("Cube Input", img);
        if(waitKey(30) == 27) break; // ESC to finish
    }
}