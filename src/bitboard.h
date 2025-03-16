#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>
#include <iostream>

// Define the number of bitboards (e.g., 12 for 6 white and 6 black pieces)
#define NUM_BITBOARDS 12

class Bitboard {
public:
    uint64_t bitboards[NUM_BITBOARDS] = {0}; // 6 piece types * 2 colors

    enum PieceType {
        WHITE_PAWN, WHITE_KNIGHT, WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, WHITE_KING,
        BLACK_PAWN, BLACK_KNIGHT, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, BLACK_KING
    };

    Bitboard();
    void printBoard(uint64_t board);

    void clearAllBoards();

    uint64_t getWhitePieces() const;
    uint64_t getBlackPieces() const;

    uint64_t getKnightMoves(int square);
    
private:
    uint64_t knightMoveTable[64];

    void initKnightMoves();
    
};

// Bit Manipulation Helpers
inline void setBit(uint64_t &bb, int square) { bb |= (1ULL << square); }
inline void clearBit(uint64_t &bb, int square) { bb &= ~(1ULL << square); }
inline bool getBit(uint64_t bb, int square) { return (bb >> square) & 1ULL; }

#endif // BITBOARD_H