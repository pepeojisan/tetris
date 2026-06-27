#pragma once

void placeBlock(Piece p, int (&board)[24][10]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!SHAPE[p.type][p.rot][i][j]) continue;
            int x = p.x + i; int y = p.y + j;
            board[x][y] = p.type;
        }
    }
}
