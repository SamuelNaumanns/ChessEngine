#include "bitboard.h"
#include "bitboard_utils.h"

Bitboard::Bitboard() {
    initKnightMoves();
}

// Get bitboard of all white pieces by OR-ing all white piece bitboards
uint64_t Bitboard::getWhitePieces() const {
    return bitboards[WHITE_PAWN] | bitboards[WHITE_KNIGHT] | 
           bitboards[WHITE_BISHOP] | bitboards[WHITE_ROOK] | 
           bitboards[WHITE_QUEEN] | bitboards[WHITE_KING];
}

// Get bitboard of all black pieces by OR-ing all black piece bitboards
uint64_t Bitboard::getBlackPieces() const {
    return bitboards[BLACK_PAWN] | bitboards[BLACK_KNIGHT] | 
           bitboards[BLACK_BISHOP] | bitboards[BLACK_ROOK] | 
           bitboards[BLACK_QUEEN] | bitboards[BLACK_KING];
}

// Initialize the lookup table for possible knight moves for every given square
void Bitboard::initKnightMoves() {
    for (int square = 0; square < 64; ++square) {
        uint64_t bitboard = 1ULL << square;
        uint64_t moves = 0ULL;

        // Shift first, then mask leftward/rightward moves
        moves |= noNoEa(bitboard); // Up-right
        moves |= noNoWe(bitboard); // Up-left
        moves |= noEaEa(bitboard); // Right-up
        moves |= noWeWe(bitboard); // Left-up

        moves |= soSoWe(bitboard); // Down-left
        moves |= soSoEa(bitboard); // Down-right
        moves |= soWeWe(bitboard); // Left-down
        moves |= soEaEa(bitboard); // Right-down

        knightMoveTable[square] = moves;
    }
}

uint64_t Bitboard::getKnightMoves(int square) {
    return knightMoveTable[square];
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

void Bitboard::clearAllBoards() {
    for (int i = 0; i < NUM_BITBOARDS; ++i) {
        bitboards[i] = 0ULL;
    }
}