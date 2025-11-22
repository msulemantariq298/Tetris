#include"grid.h"
#include<iostream>
#include "colors.h"
using namespace std;

Grid::Grid()
{
    numRows=20;
    numCols=10;
    cellSize=30;
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
        for(int columnn = 0; columnn < numCols; columnn++)
        {
            int cellValue = grid[row][columnn];                                                                // Draws each cell of dimension 29px
            DrawRectangle(columnn*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1, colors[cellValue]);         // And gives it the color according to cells value
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
