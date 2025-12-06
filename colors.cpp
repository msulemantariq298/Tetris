#include"colors.h"
#include<vector>
using namespace std;

// Color definitions - each color is defined as {red, green, blue, alpha}
// where values range from 0-255

const Color darkGrey = {0,0,0,255};             // Pure black - backgrounds and dark elements
const Color green = {62,168,44,255};            // Green - Tetris I-piece
const Color red = {181,40,40,255};              // Red - Tetris S-piece
const Color orange = {204,131,36,255};          // Orange - Tetris O-piece
const Color yellow = {220,205,41,255};          // Yellow - Tetris Z-piece
const Color purple = {177,16,180,255};          // Purple - Tetris T-piece
const Color cyan = {16,180,173,255};            // Cyan - Tetris L-piece
const Color blue = {151,25,85,255};             // Dark Blue - Tetris J-piece
const Color lightblue = {112,46,167,255};       // Light Blue - UI and buttons
const Color darkblue = {40,13,63,255};          // Dark Blue - Main background

// GetCellColors - returns a vector of all Tetris block colors
// Used to map block IDs to their corresponding display colors
vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}