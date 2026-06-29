#pragma once

void mkDisplay(int (&display)[24][10], int (&board)[24][10], Piece nowBlock) {

    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 10; j++) {
            display[i][j] = board[i][j];
        }
    }

    Piece ghostBlock = getGhost(nowBlock);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {

            if(!SHAPE[ghostBlock.type][ghostBlock.rot][i][j])
                continue;

            int x = ghostBlock.x + i; int y = ghostBlock.y + j;

            if(x < 4 || x >= 24) continue;
            if(y < 0 || y >= 10) continue;

            if(display[x][y] == 0) {
                display[x][y] = 8;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {

            if(!SHAPE[nowBlock.type][nowBlock.rot][i][j])
                continue;

            int x = nowBlock.x + i; int y = nowBlock.y + j;

            if(x < 4 || x >= 24) continue;
            if(y < 0 || y >= 10) continue;

            display[x][y] = nowBlock.type;
        }
    }
}
