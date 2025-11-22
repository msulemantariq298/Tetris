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
    void Draw();
    void Move(int rows, int columns);
    vector<Position> GetCellPositions();
    int id;
    map<int,vector<Position>> cells;

};


