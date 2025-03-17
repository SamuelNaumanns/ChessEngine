#ifndef MOVE_H
#define MOVE_H

#include <cstdint>

struct Move {
    int sourceSquare;  // The square the piece is moving from
    int targetSquare;  // The square the piece is moving to
    bool isCapture;    // Whether the move is a capture
    bool isPromotion;  // Whether the move is a promotion 

    Move(int source, int target, bool capture = false, bool promotion = false)
        : sourceSquare(source), targetSquare(target), isCapture(capture), isPromotion(promotion) {}
};

#endif // MOVE_H