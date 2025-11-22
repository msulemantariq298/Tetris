#include<iostream>
#include"raylib.h"
#include"game.h"
using namespace std;
main()
{
    Color darkBlue = {0,0,100,255};   // Background color
    InitWindow(300,600,"Tetris");     

    SetTargetFPS(60);                 // Fps set to 60

    Game game;                        // an object is made of class Game to use funtions initialized in Game class
    
    while(WindowShouldClose() == false)          // this function allows the window to remain open until user presses ESC or clicks on close 
    {
        game.HandleInput();                      // a funtion defined in Game class used by game object
        BeginDrawing();                          // a function of raylib used to do anything on the window
        ClearBackground(darkBlue);               // clears the background and adds the color you want
        game.Draw();                             // Draw funtion defined in Game class us used to draw the grid and random block
        EndDrawing();
    }

    CloseWindow();
}