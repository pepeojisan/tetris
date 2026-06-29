#pragma onece

Piece getGhost(Piece nowBlock) {
    while(canMove({nowBlock.type, nowBlock.rot, nowBlock.x + 1, nowBlock.y}, board)) {
        nowBlock.x++;
    }
    return nowBlock;
}
