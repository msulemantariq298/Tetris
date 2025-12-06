#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game
{
    public:
        Game();
        Block GetRandomBlock();
        vector<Block> GetAllBlocks();
        void Draw();
        Grid grid;
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        bool gameOver;
        int score;

    private:
        vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int LinesCleared,int moveDownPoints);
};