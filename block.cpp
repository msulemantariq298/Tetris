#include"block.h"

Block::Block()
{
    cellsize=30;
    rotationState=0;
    colors=GetCellColors();
    rowOffset=0;
    columnOffset=0;
}

void Block::Draw()
{
    vector<Position> tiles = GetCellPositions();
    for(Position item: tiles)
    {
        DrawRectangle(item.column*cellsize+1,item.row*cellsize+1,cellsize-1,cellsize-1,colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset+=rows;
    columnOffset+=columns;
}

vector<Position> Block::GetCellPositions()
{
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;
    for(Position item: tiles)
    {
        Position newPos = Position(item.row+rowOffset,item.column+columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}