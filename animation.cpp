#include "animation.h"
#include <cstdlib>
#include <cmath>

// Constructor - initializes the menu animation system
// Sets up pulse timer and creates 5 random falling blocks
MenuAnimation::MenuAnimation()
{
    pulseTimer = 0.0f;
    pulseDuration = 1.5f;  // Pulse animation takes 1.5 seconds per cycle
    
    // Initialize falling blocks with random properties
    for(int i = 0; i < 5; i++)
    {
        fallingBlocks[i].x = 50 + (rand() % 800);              // Random X position
        fallingBlocks[i].y = -50 - (i * 100);                  // Staggered Y positions (off-screen)
        fallingBlocks[i].size = 30 + (rand() % 20);            // Random size between 30-50
        
        // Assign random color from the game's color palette
        Color blockColors[] = {green, red, orange, yellow, purple, cyan, blue};
        fallingBlocks[i].color = blockColors[rand() % 7];
        fallingBlocks[i].speed = 0.5f + (rand() % 10) * 0.1f;  // Random speed between 0.5-1.4
    }
}

// Update - called each frame to update animation state
void MenuAnimation::Update()
{
    // Increment pulse timer based on frame time
    pulseTimer += GetFrameTime();
    
    // Reset timer when pulse cycle completes
    if(pulseTimer > pulseDuration)
    {
        pulseTimer = 0.0f;
    }
    
    // Update falling blocks positions
    for(int i = 0; i < 5; i++)
    {
        fallingBlocks[i].y += fallingBlocks[i].speed;  // Move block down
        
        // Reset block when it falls off bottom of screen
        if(fallingBlocks[i].y > 950)
        {
            fallingBlocks[i].y = -50;                               // Move back to top
            fallingBlocks[i].x = 50 + (rand() % 800);               // New random X position
            fallingBlocks[i].size = 30 + (rand() % 20);             // New random size
            
            // Assign new random color
            Color blockColors[] = {green, red, orange, yellow, purple, cyan, blue};
            fallingBlocks[i].color = blockColors[rand() % 7];
            fallingBlocks[i].speed = 0.5f + (rand() % 10) * 0.1f;   // New random speed
        }
    }
}

// GetTitleScale - returns the scale factor for the pulsing title
// Uses a sine wave to smoothly pulse between 0.9 and 1.1
float MenuAnimation::GetTitleScale()
{
    // Calculate progress through current pulse cycle (0.0 to 1.0)
    float progress = pulseTimer / pulseDuration;
    
    // Use sine wave to create smooth pulsing effect
    float pulse = sin(progress * 3.14159f * 2.0f);
    
    // Return scale value between 0.9 and 1.1
    return 1.0f + (pulse * 0.1f);
}

// DrawFallingBlocks - renders all falling blocks on screen
void MenuAnimation::DrawFallingBlocks()
{
    for(int i = 0; i < 5; i++)
    {
        // Create semi-transparent version of block color for depth effect
        Color blockColor = fallingBlocks[i].color;
        blockColor.a = 100;  // Set alpha to 100 for transparency
        
        // Draw filled rounded rectangle for the block
        DrawRectangleRounded(
            {fallingBlocks[i].x, fallingBlocks[i].y, fallingBlocks[i].size, fallingBlocks[i].size},
            0.2f,   // Roundness factor
            10,     // Number of segments
            blockColor
        );
        
        // Draw border around block
        DrawRectangleRoundedLines(
            {fallingBlocks[i].x, fallingBlocks[i].y, fallingBlocks[i].size, fallingBlocks[i].size},
            0.2f,
            10,
            blockColor
        );
    }
}

// Reset - resets animation timers (called when returning to menu)
void MenuAnimation::Reset()
{
    pulseTimer = 0.0f;
}
