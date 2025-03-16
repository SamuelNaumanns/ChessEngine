#include <iostream>
#include <cassert>
#include "../src/position.h"

void testGenerateKnightMoves() {
  Position position;

  // Test 1: White knights in initial position
  std::cout << "Test 1: White knights in initial position\n";
  position.initializeStartPosition();
  position.generateKnightMoves(true);
  position.bitboard.clearAllBoards();

  // Test 2: Black knights in initial position
  std::cout << "Test 2: Black knights in initial position\n";
  position.initializeStartPosition();
  position.generateKnightMoves(false);
  position.bitboard.clearAllBoards();

  // Test 3: White knight in the center of the board (d4)
  std::cout << "Test 3: White knight in the center of the board (d4)\n";
  position.bitboard.bitboards[Bitboard::WHITE_KNIGHT] = 0x8000000ULL; // d4
  position.generateKnightMoves(true);
  position.bitboard.clearAllBoards();

  // Test 4: Black knight in the corner (a8)
  std::cout << "Test 4: Black knight in the corner (a8)\n";
  position.bitboard.bitboards[Bitboard::BLACK_KNIGHT] = 0x8000000000000000ULL; // a8
  position.generateKnightMoves(false);
  position.bitboard.clearAllBoards();

  // Test 5: White knight surrounded by friendly pieces
  std::cout << "Test 5: White knight surrounded by friendly pieces\n";
  position.bitboard.bitboards[Bitboard::WHITE_KNIGHT] = 0x8000000ULL; // d4
  position.bitboard.bitboards[Bitboard::WHITE_PAWN] = 0x2000020400ULL;   // b3, c2, f5
  position.generateKnightMoves(true);
  position.bitboard.clearAllBoards();

  // Test 6: Black knight surrounded by enemy pieces
  std::cout << "Test 6: Black knight surrounded by enemy pieces\n";
  position.bitboard.bitboards[Bitboard::BLACK_KNIGHT] = 0x8000000ULL; // d4
  position.bitboard.bitboards[Bitboard::WHITE_PAWN] = 0x0000000000000028ULL;   // b3, b5, c2, c6, e2, e6, f3, f5 (completely surrounded)
  position.generateKnightMoves(false);
  position.bitboard.clearAllBoards();

  std::cout << "All tests completed.\n";
}

int main() {
  testGenerateKnightMoves();
  return 0;
}