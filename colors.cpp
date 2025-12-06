#include"colors.h"
#include<vector>
using namespace std;

// each color is set by {red,green,blue,alpha} combination
const Color darkGrey = {0,0,0,255};
const Color green = {62,168,44,255};
const Color red = {181,40,40,255};
const Color orange = {204,131,36,255};
const Color yellow = {220,205,41,255};
const Color purple = {177,16,180,255};
const Color cyan = {16,180,173,255};
const Color blue = {151,25,85,255};
const Color lightblue = {112,46,167,255};
const Color darkblue = {40,13,63,255};

vector<Color> GetCellColors()           // returns the color respectivly to the value passed to function
{
    return {darkGrey,green,red,orange,yellow,purple,cyan,blue};
}