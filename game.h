#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;
        Music music;
        Sound gameOverSound;

    private:
        void MoveBlockLeft();
        void MoveBlockRight();
        Block GetRandomBlock();
        vector<Block> GetAllBlocks();
        vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
        Sound rotateSound,clearSound;
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int LinesCleared,int moveDownPoints);
};