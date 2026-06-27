#pragma once

bool canMove(Piece p, int (&board)[24][10]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!SHAPE[p.type][p.rot][i][j]) continue;
            int x = i + p.x; int y = j + p.y;
            if(0 > x || x >= 24) return false;
            if(0 > y || y >= 10) return false;
            if(board[x][y]) return false;
        }
    }
    return true;
}
