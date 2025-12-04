#include<iostream>
#include"raylib.h"
#include"game.h"
#include"colors.h"
using namespace std;

double lastUpdateTime =0 ;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

main()
{
    InitWindow(900,900,"Tetris");     

    SetTargetFPS(60);                 // Fps set to 60

    Font font = LoadFontEx("Font/monogram.ttf",64,0,0); // loading custom font


    Game game;                        // an object is made of class Game to use funtions initialized in Game class
    
    while(WindowShouldClose() == false)          // this function allows the window to remain open until user presses ESC or clicks on close 
    {
        game.HandleInput();                      // a funtion defined in Game class used by game object
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();                          // a function of raylib used to do anything on the window
        ClearBackground(darkblue);               // clears the background and adds the color you want
        //DrawRectangleRounded({460,10,430,880},0.1,6,ORANGE);
        DrawTextEx(font,"TETRIS",{570,20},64,4,WHITE); // Drawing the title text using custom font
        DrawTextEx(font,"SCORE",{590,150},64,4,WHITE);
        DrawRectangleRounded({585,220,170,60},0.3,6,lightblue);
        DrawTextEx(font,"NEXT",{610,350},64,4,WHITE);
        DrawRectangleRounded({570,420,200,200},0.3,6,lightblue);
        if(game.gameOver)
        DrawTextEx(font,"GAME OVER!",{520,700},64,4,WHITE);
        game.Draw();                             // Draw funtion defined in Game class us used to draw the grid and random block
        EndDrawing();
    }

    CloseWindow();
}