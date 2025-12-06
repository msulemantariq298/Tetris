#pragma once
#include<vector>
#include<map>
#include"position.h"
#include"colors.h"
using namespace std;

class Block
{
private:
    int cellsize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;
    
public:
    Block();
    void Draw(int offseX,int offsetY);
    void Move(int rows, int columns);
    vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;
    map<int,vector<Position>> cells;

};


