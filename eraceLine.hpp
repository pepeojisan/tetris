#pragma once

void eraceLine(int &score, int (&board)[24][10]) {
    for(int i = 23; i >= 0; i--) {
        bool full = true;
        for(int j = 0; j < 10; j++) {
            if(board[i][j] == 0) {
                full = false;
                break;
            }
        }
        if(full) {
            score++;
            for(int j = i; j > 0; j--) {
                for(int k = 0; k < 10; k++) {
                    board[j][k] = board[j - 1][k];
                }
            }
            for(int j = 0; j < 10; j++) {
                board[0][j] = 0;
            }
            i++;
        }
    }
}
