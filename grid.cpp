#include"grid.h"
#include<iostream>
#include "colors.h"
using namespace std;

Grid::Grid()
{
    numRows=20;
    numCols=10;
    cellSize=45;
    Initialize();
    colors = GetCellColors();
};


// Funtion to initialize all the elements of 2D array to zero
void Grid::Initialize()         
{
    for(int row=0;row<numRows;row++)
    {
        for(int col=0;col<numCols;col++)
        {
            grid[row][col]=0;
        }
    }
}

// Funtion to Print the elements of the Array
void Grid::Print()
{
    for(int row=0;row<numRows;row++)
    {
        for(int col=0;col<numCols;col++)
        {
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }
}

// Function to Draw the grid 
void Grid::Draw()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];                                                                // Draws each cell of dimension 29px
            DrawRectangle(column*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1, colors[cellValue]);         // And gives it the color according to cells value
        }
    }
}

bool Grid::IsCellOutside(int row, int column)                                   // if the block exceeds the grid it returns false
{
    if(row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row,int column)
{
    if(grid[row][column]==0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed=0;
    for(int row=numRows-1;row>=0;row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if(completed>0)
        {
            MoveRowDown(row,completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for(int column=0;column<numCols;column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column=0;column<numCols;column++)
    {
        grid[row][column]=0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int column=0;column<numCols;column++)
    {
        grid[row+numRows][column]=grid[row][column];
        grid[row][column]=0;
    }
}
