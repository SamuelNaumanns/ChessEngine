#ifndef POSITION_H
#define POSITION_H

#include "bitboard.h"
#include "move.h"

class Position {
public:
    Bitboard bitboard;
    bool whiteToMove;
    int enPassantSquare;
    bool castlingRights[4]; // KQkq

    Position();
    void initializeStartPosition(); // Initialize starting position

    // Move Generation
    std::vector<Move> generateKnightMoves(bool isWhite);
};

#endif // POSITION_H