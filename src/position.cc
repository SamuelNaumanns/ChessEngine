#include "position.h"

Position::Position() : whiteToMove(true), enPassantSquare(-1) {
  castlingRights[0] = castlingRights[1] = castlingRights[2] = castlingRights[3] = true;
  // initializeStartPosition();  // Call initPosition in constructor
}

void Position::initializeStartPosition() {
  // Pawns
  bitboard.bitboards[Bitboard::WHITE_PAWN] = 0x000000000000FF00ULL;  // Rank 2
  bitboard.bitboards[Bitboard::BLACK_PAWN] = 0x00FF000000000000ULL;  // Rank 7

  // Rooks
  bitboard.bitboards[Bitboard::WHITE_ROOK] = 0x0000000000000081ULL;  // a1, h1
  bitboard.bitboards[Bitboard::BLACK_ROOK] = 0x8100000000000000ULL;  // a8, h8

  // Knights
  bitboard.bitboards[Bitboard::WHITE_KNIGHT] = 0x0000000000000042ULL;  // b1, g1
  bitboard.bitboards[Bitboard::BLACK_KNIGHT] = 0x4200000000000000ULL;  // b8, g8

  // Bishops
  bitboard.bitboards[Bitboard::WHITE_BISHOP] = 0x0000000000000024ULL;  // c1, f1
  bitboard.bitboards[Bitboard::BLACK_BISHOP] = 0x2400000000000000ULL;  // c8, f8

  // Queens
  bitboard.bitboards[Bitboard::WHITE_QUEEN] = 0x0000000000000008ULL;  // d1
  bitboard.bitboards[Bitboard::BLACK_QUEEN] = 0x0800000000000000ULL;  // d8

  // Kings
  bitboard.bitboards[Bitboard::WHITE_KING] = 0x0000000000000010ULL;  // e1
  bitboard.bitboards[Bitboard::BLACK_KING] = 0x1000000000000000ULL;  // e8
}

void Position::generateKnightMoves(bool isWhite) {
  uint64_t knights = isWhite ? bitboard.bitboards[Bitboard::WHITE_KNIGHT] 
                             : bitboard.bitboards[Bitboard::BLACK_KNIGHT];

  while (knights) {
      int knightSquare = __builtin_ctzll(knights); // Get least significant bit index
      uint64_t moves = bitboard.getKnightMoves(knightSquare); // Generate knight moves
      moves &= ~(isWhite ? bitboard.getWhitePieces() : bitboard.getBlackPieces()); // Remove friendly fire

      std::cout << "Knight moves from " << knightSquare << ":\n";
      bitboard.printBoard(moves);

      knights &= knights - 1; // Remove processed knight
  }
}