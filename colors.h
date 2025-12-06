#pragma once
#include "raylib.h"
#include<vector>
using namespace std;

// Color constants used throughout the game for blocks, UI, and backgrounds
// These are declared as external constants defined in colors.cpp
extern const Color darkgrey;   // Dark grey for backgrounds
extern const Color green;      // Tetris piece color 1
extern const Color red;        // Tetris piece color 2
extern const Color orange;     // Tetris piece color 3
extern const Color yellow;     // Tetris piece color 4
extern const Color purple;     // Tetris piece color 5
extern const Color cyan;       // Tetris piece color 6
extern const Color blue;       // Tetris piece color 7
extern const Color lightblue;  // UI elements and buttons
extern const Color darkblue;   // Background color

// Function to get array of colors used for Tetris blocks
vector<Color> GetCellColors();