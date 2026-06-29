#include "preamble.hpp"
#include "blocks.hpp"

int board[24][10] = {}; //colors 0 ~ 7
int display[24][10] = {};

struct Piece {
    int type; //0 ~ 7
    int rot;  //0 ~ 3
    int x;
    int y;
};

int score;

bool gameOver = false;

Piece nowBlock = {};
Piece nextBlock = {};

const int TPS = 20;
const auto TICK = milliseconds(1000 / TPS);

int nowtick;

bool grounded = false;

const int LOCKDELAY = 13;
int lockTick;

bool blockExists = false;

bool hardDrop = false;

queue<Piece> blocksRow;

int randomBlocks[7] = {1, 2, 3, 4, 5, 6, 7};

int c = 127;

enum ExitReason {
    GAMEOVER,
    RESTART,
    TITLE
};

Piece holdedBlock = {};
bool holdExist = false;
bool holdUsed = false;

#include "canMove.hpp"
#include "getGhost.hpp"
#include "draw.hpp"
#include "mkDisplay.hpp"
#include "eraceLine.hpp"
#include "kbControl.hpp"
#include "placeBlock.hpp"
#include "game.hpp"

int main() {

    random_device rd;
    mt19937 rng(rd());

    while(true) {

        cout << "\033[2J\033[H";

        cout << R"(

████████╗███████╗████████╗██████╗ ██╗███████╗
╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝
   ██║   █████╗     ██║   ██████╔╝██║███████╗
   ██║   ██╔══╝     ██║   ██╔══██╗██║╚════██║
   ██║   ███████╗   ██║   ██║  ██║██║███████║
   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝

)";

        cout << "Press S to Start\n";

        cout << flush;

        while(true) {

            if(_kbhit()) {

                char c = tolower(_getch());

                if(c == 's')
                    break;
            }

            this_thread::sleep_for(TICK);
        }

        bool backToTitle = false;

        while(!backToTitle) {

            ExitReason result = game(rng);

            switch(result) {

            case RESTART:
                continue;

            case TITLE:
                backToTitle = true;
                break;

            case GAMEOVER:

                cout << "\033[2J\033[H";

                cout << "===== GAME OVER =====\n\n";
                cout << "Score : " << score << "\n\n";

                cout << "R : Restart\n";
                cout << "Q : Title\n";

                cout << flush;

                while(true) {

                    char c = tolower(_getch());

                    if(c == 'r')
                        break;

                    if(c == 'q') {
                        backToTitle = true;
                        break;
                    }

                    this_thread::sleep_for(TICK);

                }

                break;
            }
            this_thread::sleep_for(TICK);

        }
    this_thread::sleep_for(TICK);
    }

}
