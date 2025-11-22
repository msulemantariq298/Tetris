#pragma once

#include<vector>
#include"raylib.h"

using namespace std;

class Grid
{
    public:
    Grid();
    int grid[20][10];
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row,int column);

    private:
    int numRows,numCols,cellSize;  
    vector<Color> colors;
};