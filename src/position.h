#ifndef POSITION_H
#define POSITION_H

#include "bitboard.h"

class Position {
public:
    Bitboard bitboard;
    bool whiteToMove;
    int enPassantSquare;
    bool castlingRights[4]; // KQkq

    Position();
    void initializeStartPosition(); // Initialize starting position

    // Move Generation
    void generateKnightMoves(bool isWhite);
};

#endif // POSITION_H