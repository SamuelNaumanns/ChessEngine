#include <iostream>
#include <cassert>
#include "../src/position.h"

void testGenerateKnightMoves() {
  Position position;

  // Test 1: White knights in initial position
  std::cout << "Test 1: White knights in initial position\n";
  position.initializeStartPosition();
  auto whiteKnightMoves = position.generateKnightMoves(true);
  assert(whiteKnightMoves.size() == 4); // Knights should initially have 4 valid moves
  for (const auto& move : whiteKnightMoves) {
      std::cout << "Knight moves from " << move.sourceSquare 
                << " to " << move.targetSquare 
                << (move.isCapture ? " (capture)" : "") << "\n";
  }
  position.bitboard.clearAllBoards();

  // Test 2: Black knights in initial position
  std::cout << "Test 2: Black knights in initial position\n";
  position.initializeStartPosition();
  auto blackKnightMoves = position.generateKnightMoves(false);
  assert(blackKnightMoves.size() == 4); // Knights should initially have 2 valid moves
  for (const auto& move : blackKnightMoves) {
      std::cout << "Knight moves from " << move.sourceSquare 
                << " to " << move.targetSquare 
                << (move.isCapture ? " (capture)" : "") << "\n";
  }
  position.bitboard.clearAllBoards();

  // Test 3: White knight in the center of the board (d4)
  std::cout << "Test 3: White knight in the center of the board (d4)\n";
  position.bitboard.bitboards[Bitboard::WHITE_KNIGHT] = 0x8000000ULL; // d4
  auto centerKnightMoves = position.generateKnightMoves(true);
  assert(centerKnightMoves.size() == 8); // Knight should have 8 valid moves
  for (const auto& move : centerKnightMoves) {
      std::cout << "Knight moves from " << move.sourceSquare 
                << " to " << move.targetSquare 
                << (move.isCapture ? " (capture)" : "") << "\n";
  }
  position.bitboard.clearAllBoards();

  // Test 4: Black knight in the corner (a8)
  std::cout << "Test 4: Black knight in the corner (a8)\n";
  position.bitboard.bitboards[Bitboard::BLACK_KNIGHT] = 0x8000000000000000ULL; // a8
  auto cornerKnightMoves = position.generateKnightMoves(false);
  assert(cornerKnightMoves.size() == 2); // Knight should have 2 valid moves
  for (const auto& move : cornerKnightMoves) {
      std::cout << "Knight moves from " << move.sourceSquare 
                << " to " << move.targetSquare 
                << (move.isCapture ? " (capture)" : "") << "\n";
  }
  position.bitboard.clearAllBoards();

  // Test 5: White knight surrounded by friendly pieces
  std::cout << "Test 5: White knight surrounded by 3 friendly pieces\n";
  position.bitboard.bitboards[Bitboard::WHITE_KNIGHT] = 0x8000000ULL; // d4
  position.bitboard.bitboards[Bitboard::WHITE_PAWN] = 0x2000020400ULL;   // b3, c2, f5
  auto surroundedKnightMoves = position.generateKnightMoves(true);
  assert(surroundedKnightMoves.size() == 5); // Knight should have 8 - 3 = 5 valid moved
  for (const auto& move : surroundedKnightMoves) {
    std::cout << "Knight moves from " << move.sourceSquare 
              << " to " << move.targetSquare 
              << (move.isCapture ? " (capture)" : "") << "\n";
}
  position.bitboard.clearAllBoards();

  // Test 6: Black knight surrounded by enemy pieces
  std::cout << "Test 6: Black knight surrounded by enemy pieces\n";
  position.bitboard.bitboards[Bitboard::BLACK_KNIGHT] = 0x8000000ULL; // d4
  position.bitboard.bitboards[Bitboard::WHITE_PAWN] = 0x142200221400ULL;   // b3, b5, c2, c6, e2, e6, f3, f5 (completely surrounded)
  auto surroundedEnemyKnightMoves = position.generateKnightMoves(false);
  assert(surroundedEnemyKnightMoves.size() == 8); // Knight should have 8 valid capture moves
  for (const auto& move : surroundedEnemyKnightMoves) {
      std::cout << "Knight moves from " << move.sourceSquare 
                << " to " << move.targetSquare 
                << (move.isCapture ? " (capture)" : " (no capture)") << "\n";
  }
  position.bitboard.clearAllBoards();

  std::cout << "All tests completed.\n";
}

int main() {
  testGenerateKnightMoves();
  return 0;
}