// ============================================
// TETRIS GAME - Main Entry Point
// ============================================
// This file contains the main game loop, menu system, and overall game flow

#include<iostream>
#include"raylib.h"           // Raylib graphics library
#include"game.h"             // Main game logic
#include"colors.h"           // Color definitions
#include"button.h"           // UI buttons
#include"animation.h"        // Menu animations
using namespace std;

// Global timer for managing game events
double lastUpdateTime = 0;

// EventTriggered - checks if enough time has passed since last event
// Used to control timing of block movements and other game events
bool EventTriggered(double interval)
{
    double currentTime = GetTime();  // Get current time in seconds
    
    // If interval has passed, update timer and return true
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

// Main - entry point for the Tetris game
int main()
{
    // ============ INITIALIZATION ============
    
    // Create game window (900x900 pixels)
    InitWindow(900, 900, "Tetris");     

    // Set target frame rate to 60 FPS
    SetTargetFPS(60);

    // Load custom font for game display
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    // Create game object and initialize game logic
    Game game;

    // Create menu animation system
    MenuAnimation menuAnimation;
    
    // ============ BUTTON SETUP ============
    
    // Calculate centered button positions (window is 900x900)
    float buttonWidth = 200;
    float buttonHeight = 60;
    float centerX = (900 - buttonWidth) / 2;
    float startButtonY = 350;
    float exitButtonY = 450;
    
    // Create start and exit buttons for main menu
    Button startButton(centerX, startButtonY, buttonWidth, buttonHeight, "Start", 50);
    Button exitButton(centerX, exitButtonY, buttonWidth, buttonHeight, "Exit", 50);
    
    // Create mute button in top right corner
    Button muteButton(820, 10, 70, 50, "Mute", 16);
    
    // ============ GAME STATE ============
    
    bool gameStarted = false;  // Tracks if game is active (false = menu screen)
    bool isMuted = false;      // Tracks if music is muted

    // ============ MAIN GAME LOOP ============
    
    while(WindowShouldClose() == false)  // Loop until user closes window
    {
        // Update music stream to keep playing
        UpdateMusicStream(game.music);
        
        // ============ UPDATE PHASE ============
        
        // Update all button states (hover detection)
        startButton.Update();
        exitButton.Update();
        muteButton.Update();

        // ============ INPUT HANDLING ============
        
        // Check if Start button was clicked
        if(startButton.IsClicked())
        {
            gameStarted = true;  // Transition to game screen
        }
        
        // Check if Exit button was clicked
        if(exitButton.IsClicked())
        {
            break;  // Exit the game loop
        }
        
        // Check if Mute button was clicked
        if(muteButton.IsClicked())
        {
            isMuted = !isMuted;  // Toggle mute state
            
            // Set music volume accordingly
            if(isMuted)
            {
                SetMusicVolume(game.music, 0.0f);  // Mute music
            }
            else
            {
                SetMusicVolume(game.music, 1.0f);  // Unmute music
            }
        }

        // ============ RENDERING PHASE ============
        
        BeginDrawing();                    // Start drawing to screen
        ClearBackground(darkblue);         // Clear screen with dark blue background
        
        // ============ MENU SCREEN ============
        
        if(!gameStarted)
        {
            // Update menu animation effects
            menuAnimation.Update();
            
            // Draw falling blocks animation in background
            menuAnimation.DrawFallingBlocks();
            
            // Get current title pulse scale for animation
            float titleScale = menuAnimation.GetTitleScale();
            
            // Calculate centered pulsing title position
            Vector2 titlePos = {240, 100};
            Vector2 titleSize = MeasureTextEx(font, "TETRIS", 128, 8);
            Vector2 scaledPos = {
                titlePos.x + (titleSize.x * (1.0f - titleScale)) / 2,
                titlePos.y + (titleSize.y * (1.0f - titleScale)) / 2
            };
            
            // Draw animated TETRIS title
            DrawTextEx(font, "TETRIS", scaledPos, (int)(128 * titleScale), 8, WHITE);
            
            // Draw developer credits - centered and larger
            int headerWidth = MeasureText("Developers:", 28);
            DrawText("Developers:", (900 - headerWidth) / 2, 580, 28, WHITE);
            
            int dev1Width = MeasureText("1. Muhammad Suleman Tariq", 22);
            DrawText("1. Muhammad Suleman Tariq", (900 - dev1Width) / 2, 620, 22, lightblue);
            
            int dev2Width = MeasureText("2. Huzaifa Mqbool", 22);
            DrawText("2. Huzaifa Mqbool", (900 - dev2Width) / 2, 655, 22, lightblue);
            
            int dev3Width = MeasureText("3. Abdur Rehman Shahab", 22);
            DrawText("3. Abdur Rehman Shahab", (900 - dev3Width) / 2, 690, 22, lightblue);
            
            // Draw menu buttons
            startButton.Draw();
            exitButton.Draw();
            muteButton.Draw();
        }
        // ============ GAME SCREEN ============
        
        else
        {
            // Handle player input during gameplay
            game.HandleInput();
            
            // Move block down at regular intervals
            if(EventTriggered(0.2))
            {
                game.MoveBlockDown();
            }

            // Draw game title
            DrawTextEx(font, "TETRIS", {570, 20}, 64, 4, WHITE); 

            // Draw Scoring System
            DrawTextEx(font, "SCORE", {590, 150}, 64, 4, WHITE);
            DrawRectangleRounded({578, 220, 190, 70}, 0.3, 6, lightblue);

            // Display current score
            char scoreText[10];
            sprintf(scoreText, "%d", game.score);
            Vector2 textSize = MeasureTextEx(font, scoreText, 64, 4);

            DrawTextEx(font, scoreText, {578 + (190 - textSize.x) / 2, 220}, 64, 4, WHITE);

            // Draw "Next Block" preview area
            DrawTextEx(font, "NEXT", {610, 350}, 64, 4, WHITE);
            DrawRectangleRounded({570, 420, 200, 200}, 0.3, 6, lightblue);
            
            // Display game over message if applicable
            if(game.gameOver)
            {
                DrawTextEx(font, "GAME OVER!", {520, 700}, 64, 4, WHITE);
                DrawTextEx(font, "Press (R) to Restart.", {510, 770}, 32, 2, WHITE);
            }

            // Draw main game grid and blocks
            game.Draw();
            
            // Draw mute button during gameplay
            muteButton.Draw();
        }
        EndDrawing();  // Finish drawing to screen
    }

    // ============ CLEANUP ============
    
    // Close the game window
    CloseWindow();
    
    return 0;
}