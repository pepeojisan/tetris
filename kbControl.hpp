#pragma once

void kbControl(Piece &nowBlock, Piece &nextBlock, Piece &holdedBlock, bool holdUsed, bool holdExit , char c) {

    //rotate && draw

    int kick[5] = {0, 1, -1, 2, -2};

    if(c == 0 || c == 224) c = _getch();

    if(c == 75) {
        if(canMove({nowBlock.type, nowBlock.rot, nowBlock.x, nowBlock.y - 1}, board)) {
            nowBlock = {nowBlock.type, nowBlock.rot, nowBlock.x, nowBlock.y - 1};
        }
    }
    if(c == 77) {
        if(canMove({nowBlock.type, nowBlock.rot, nowBlock.x, nowBlock.y + 1}, board)) {
            nowBlock = {nowBlock.type, nowBlock.rot, nowBlock.x, nowBlock.y + 1};
        }
    }
    if(c == 122 || c == 120 || c == 72 || c == 97) {
        for(auto i : kick) {
            if(c == 122) {
                if(canMove({nowBlock.type, (nowBlock.rot + 3) % 4, nowBlock.x, nowBlock.y + i}, board)) {
                    nowBlock = {nowBlock.type, (nowBlock.rot + 3) % 4, nowBlock.x, nowBlock.y + i};
                    break;
                }
            }
            if(c == 120) {
                if(canMove({nowBlock.type, (nowBlock.rot + 1) % 4, nowBlock.x, nowBlock.y + i}, board)) {
                    nowBlock = {nowBlock.type, (nowBlock.rot + 1) % 4, nowBlock.x, nowBlock.y + i};
                    break;
                }
            }
            if(c == 72) {
                if(canMove({nowBlock.type, (nowBlock.rot + 1) % 4, nowBlock.x, nowBlock.y + i}, board)) {
                    nowBlock = {nowBlock.type, (nowBlock.rot + 1) % 4, nowBlock.x, nowBlock.y + i};
                    break;
                }
            }
            if(c == 97) {
                if(canMove({nowBlock.type, (nowBlock.rot + 2) % 4, nowBlock.x, nowBlock.y + i}, board)) {
                    nowBlock = {nowBlock.type, (nowBlock.rot + 2) % 4, nowBlock.x, nowBlock.y + i};
                    break;
                }
            }
        }
    }
    if(c == 32 || c == 80) {
        while(true) {
            if(canMove({nowBlock.type, nowBlock.rot, nowBlock.x + 1, nowBlock.y}, board)) {
                nowBlock = {nowBlock.type, nowBlock.rot, nowBlock.x + 1, nowBlock.y};
            }
            else break;
        }
    }
    if((c == 'c' || c == 'C' || (GetAsyncKeyState(VK_SHIFT) & 0x8000)) && !holdUsed) {
        holdUsed = true;

        if(!holdExist)
        {
            holdedBlock = nowBlock;
            holdedBlock.rot = 0;

            nowBlock = nextBlock;

            nextBlock = blocksRow.front();
            blocksRow.pop();

            holdExist = true;
        }
        else
        {
            swap(nowBlock, holdedBlock);

            nowBlock.rot = 0;
        }

        nowBlock.x = 0;
        nowBlock.y = 3;
    }
    // if(c == 114) {
    //     //restart
    //     exitReason = RESTART;
    //     break;
    // }
    // if(c == 113) {
    //     //quit
    //     exitReason = TITLE;
    //     break;
    // }
}
