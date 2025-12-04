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
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row , int numRows);
    int numRows,numCols,cellSize;  
    vector<Color> colors;
};