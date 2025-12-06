#pragma once
#include "raylib.h"
#include "colors.h"
using namespace std;

// FallingBlock struct represents a single animated block on the menu
struct FallingBlock
{
    float x;           // X position of the block
    float y;           // Y position of the block
    float size;        // Size of the block (width and height)
    Color color;       // Color of the block
    float speed;       // Vertical falling speed
};

// MenuAnimation class handles all menu screen animations
class MenuAnimation
{
private:
    float pulseTimer;           // Timer for tracking pulse animation progress
    float pulseDuration;        // Duration of one complete pulse cycle (in seconds)
    FallingBlock fallingBlocks[5];  // Array of 5 falling blocks for background animation
    
public:
    MenuAnimation();            // Constructor - initializes animation state
    void Update();              // Updates animation state each frame
    float GetTitleScale();      // Returns the current scale factor for the pulsing title
    void DrawFallingBlocks();   // Renders the falling blocks on screen
    void Reset();               // Resets animation timers
};
