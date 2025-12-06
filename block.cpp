#include"block.h"

Block::Block()
{
    // initial state of block
    cellsize=45;
    rotationState=0;
    colors=GetCellColors();
    rowOffset=0;
    columnOffset=0;
}

void Block::Draw(int offsetX,int offsetY)          // Function to draw the block on the screen
{
    vector<Position> tiles = GetCellPositions();
    for(Position item: tiles)
    {
        DrawRectangle(item.column*cellsize+offsetX,item.row*cellsize+offsetY,cellsize-1,cellsize-1,colors[id]);
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

void Block::Rotate()
{
    rotationState++;
    if(rotationState == (int)cells.size())
    {
        rotationState=0;
    }
}

void Block::UndoRotation()
{
    rotationState --;
    if(rotationState == -1)
    {
        rotationState = cells.size() -1;
    }
}
