#pragma once

ExitReason game(mt19937 &rng) {

    score = 0;

    gameOver = false;
    blockExists = false;
    hardDrop = false;

    nowtick = 0;
    lockTick = 0;

    memset(board, 0, sizeof(board));
    memset(display, 0, sizeof(display));

    while(!blocksRow.empty())
        blocksRow.pop();

    while(!gameOver) {

        if(blocksRow.empty()) {
            shuffle(randomBlocks, randomBlocks + 7, rng);

            for(int i : randomBlocks)
                blocksRow.push({i, 0, 0, 3});
        }

        if(nowtick == 0) {
            nextBlock = blocksRow.front();
            blocksRow.pop();
        }

        if(!blockExists) {

            nowBlock = nextBlock;

            if(!canMove(nowBlock, board)) {
                gameOver = true;
                break;
            }

            nextBlock = blocksRow.front();
            blocksRow.pop();

            blockExists = true;
            holdUsed = false;
        }

        c = 127;

        if(_kbhit()) {
            c = _getch();
            lockTick = 0;
        }
        

        if(c == 'r' || c == 'R')
            return RESTART;

        if(c == 'q' || c == 'Q')
            return TITLE;

        kbControl(nowBlock, nextBlock, holdedBlock, holdUsed, holdExist, c);

        if(c == ' ')
            hardDrop = true;

        

        eraceLine(score, board);

        mkDisplay(display, board, nowBlock);

        draw(display, score, nextBlock, holdedBlock, holdExist);

        // fall

        if(nowtick % max(3, 7 - score / 5) == 0) {

            if(canMove({nowBlock.type, nowBlock.rot, nowBlock.x + 1, nowBlock.y}, board)) {
                nowBlock.x++;
            }

        }

        if(!canMove({nowBlock.type, nowBlock.rot, nowBlock.x + 1, nowBlock.y}, board)) {

            if(!hardDrop) {

                lockTick++;

                if(lockTick >= LOCKDELAY) {

                    placeBlock(nowBlock, board);

                    blockExists = false;

                }

            }
            else {

                placeBlock(nowBlock, board);

                blockExists = false;

                hardDrop = false;

            }

        }
        else {

            lockTick = 0;

        }

        nowtick++;

        this_thread::sleep_for(TICK);

    }

    return GAMEOVER;

}
