#include "bitboard.h"

Bitboard::Bitboard() {
    initPosition();
}

void Bitboard::initPosition() {
    // Pawns
    bitboards[WHITE_PAWN] = 0x000000000000FF00ULL;  // Rank 2
    bitboards[BLACK_PAWN] = 0x00FF000000000000ULL;  // Rank 7

    // Rooks
    bitboards[WHITE_ROOK] = 0x8100000000000001ULL;
    bitboards[BLACK_ROOK] = 0x0000000000000081ULL;

    // Knights
    bitboards[WHITE_KNIGHT] = 0x4200000000000042ULL;
    bitboards[BLACK_KNIGHT] = 0x0000000000000042ULL;

    // Bishops
    bitboards[WHITE_BISHOP] = 0x2400000000000024ULL;
    bitboards[BLACK_BISHOP] = 0x0000000000000024ULL;

    // Queens
    bitboards[WHITE_QUEEN] = 0x0800000000000008ULL;
    bitboards[BLACK_QUEEN] = 0x0000000000000008ULL;

    // Kings
    bitboards[WHITE_KING] = 0x1000000000000010ULL;
    bitboards[BLACK_KING] = 0x0000000000000010ULL;
}

void Bitboard::printBoard(uint64_t board) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            std::cout << (getBit(board, square) ? "1 " : ". ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}