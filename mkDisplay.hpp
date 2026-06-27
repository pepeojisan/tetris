#pragma once

void mkDisplay(int (&display)[24][10], int (&board)[24][10], Piece nowBlock) {

    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 10; j++) {
            display[i][j] = board[i][j];
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
