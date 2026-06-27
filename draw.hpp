#pragma once

void draw(int (&display)[24][10], int &score, Piece nextBlock, Piece holdedBlock, bool holdExist) {
    cout << "\033[2J\033[H";
    //cout << "\033[?25l";
    for(int i = 4; i < 24; i++) {
        cout << "│";
        for(int j = 0; j < 10; j++) {
            cout << COLOR[display[i][j]];
        }
        cout << "│";
        if(i == 4) cout << "SCORE : " << score << '\n';
        else if(i == 6) cout << "NEXT : \n";
        else if(i == 7 || i == 8 || i == 9 || i == 10) {
            for(int j = 0; j < 4; j++) {
                if(SHAPE[nextBlock.type][nextBlock.rot][i - 7][j]) cout << COLOR[nextBlock.type];
                else cout << "  ";
            }
            cout << '\n';
        }
        else if(i == 12) cout << "HOLD : \n";
        else if(i == 13 || i == 14 || i == 15 || i == 16) {
            for(int j = 0; j < 4; j++) {
                if(SHAPE[holdedBlock.type][holdedBlock.rot][i - 13][j]) cout << COLOR[holdedBlock.type];
                else cout << "  ";
            }
            cout << '\n';
        }
        else cout << '\n';
    }
    cout << "└────────────────────┘\n";
    cout << flush;
}
