#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>
#include <iostream>

class Bitboard {
public:
    uint64_t bitboards[12] = {0}; // 6 piece types * 2 colors

    enum PieceType {
        WHITE_PAWN, WHITE_KNIGHT, WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, WHITE_KING,
        BLACK_PAWN, BLACK_KNIGHT, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, BLACK_KING
    };

    Bitboard();
    void printBoard(uint64_t board);
    void initPosition();
};

// Bit Manipulation Helpers
inline void setBit(uint64_t &bb, int square) { bb |= (1ULL << square); }
inline void clearBit(uint64_t &bb, int square) { bb &= ~(1ULL << square); }
inline bool getBit(uint64_t bb, int square) { return (bb >> square) & 1ULL; }

#endif // BITBOARD_H