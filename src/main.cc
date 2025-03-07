#include <iostream>
#include "bitboard.h"

int main() {
    Bitboard board;

    std::cout << "White Pawns:" << std::endl;
    board.printBoard(board.bitboards[Bitboard::WHITE_PAWN]);

    std::cout << "Black Pawns:" << std::endl;
    board.printBoard(board.bitboards[Bitboard::BLACK_PAWN]);

    return 0;
}