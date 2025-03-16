#include <iostream>
#include "bitboard.h"
#include "position.h"

int main() {
    Position pos;
    Bitboard board = pos.bitboard;

    std::cout << "White Pieces:" << std::endl;
    board.printBoard(board.getWhitePieces());

    std::cout << "Black Pieces:" << std::endl;
    board.printBoard(board.getBlackPieces());

    pos.generateKnightMoves(true);

    return 0;
}